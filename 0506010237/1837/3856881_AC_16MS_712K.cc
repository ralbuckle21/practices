#include<iostream>
using namespace std;
int f[20][15005];
int w[22],sum=0;
int n,m;
int c[22];
int down,up,len;
int main()
{
     scanf("%d%d",&m,&n);
     for(int i=1;i<=m;i++){
         scanf("%d",&c[i]);
         if(c[i]>0) len=i;
     } 
     for(int i=1;i<=n;i++){
         scanf("%d",&w[i]);
         sum+=w[i];
     }
     down=7500+c[1]*sum; up=7500+c[m]*sum;
     for(int x=1;x<=m;x++) f[1][7500+c[x]*w[1]]=1;
     for(int i=2;i<=n;i++){
          for(int x=len;x<=m;x++)   
             for(int j=up;j>=down;j--)
                if(f[i-1][j]) f[i][j+c[x]*w[i]]+=f[i-1][j];
          for(int x=1;x<len;x++)
             for(int j=down;j<=up;j++)
                if(f[i-1][j]) f[i][j+c[x]*w[i]]+=f[i-1][j];                  
     }
     printf("%d\n",f[n][7500]);
     system("pause");
     return 0;
}
