#include<iostream>
#include<math.h>
using namespace std;
int s[10][10][10][10];
int f[16][10][10][10][10];
int v[10][10];
int n; 
void pow(int &a){ a=a*a; }
int main()
{
     scanf("%d",&n);
     n--;
     for(int i=1;i<=8;i++)
         for(int j=1;j<=8;j++)
             scanf("%d",&v[i][j]);
     for(int x1=1;x1<=8;x1++)
         for(int y1=1;y1<=8;y1++)
             for(int x2=x1;x2<=8;x2++)
                for(int y2=y1;y2<=8;y2++){
                      for(int x=x1;x<=x2;x++)
                         for(int y=y1;y<=y2;y++)        
                              s[x1][y1][x2][y2]+=v[x][y];
                              pow(s[x1][y1][x2][y2]);
                              f[0][x1][y1][x2][y2]=s[x1][y1][x2][y2];
                } 
     for(int k=1;k<=n;k++){
         for(int x1=1;x1<8;x1++)
            for(int y1=1;y1<8;y1++)
               for(int x2=x1+1;x2<=8;x2++)
                   for(int y2=y1+1;y2<=8;y2++){
                        f[k][x1][y1][x2][y2]=INT_MAX;
                        for(int a=x1;a<x2;a++){
                             int num=f[k-1][x1][y1][a][y2]+s[a+1][y1][x2][y2];
                             if(num<f[k][x1][y1][x2][y2]) f[k][x1][y1][x2][y2]=num;
                             num= f[k-1][a+1][y1][x2][y2]+s[x1][y1][a][y2];
                             if(num<f[k][x1][y1][x2][y2]) f[k][x1][y1][x2][y2]=num;        
                        }
                        for(int b=y1;b<y2;b++){
                             int num=f[k-1][x1][y1][x2][b]+s[x1][b+1][x2][y2];
                             if(num<f[k][x1][y1][x2][y2]) f[k][x1][y1][x2][y2]=num;
                             num= f[k-1][x1][b+1][x2][y2]+s[x1][y1][x2][b];
                             if(num<f[k][x1][y1][x2][y2]) f[k][x1][y1][x2][y2]=num;                                        
                        }
                   }        
     } 
     double r=double(f[n][1][1][8][8])/(n+1),rs=s[1][1][8][8]/((n+1)*(n+1));
     double re=sqrt(r-rs);
     printf("%.3f\n",re);
     system("pause");
     return 0;
}
