#include<iostream>
using namespace std;
int a,b,c;
int num[21][21][21]={0};
int main()
{
     for(int i=0;i<=20;i++)
       for(int j=0;j<=20;j++)
       {
          num[i][j][0]=1;
          num[i][0][j]=1;
          num[0][i][j]=1;
       }
     for(int i=1;i<=20;i++)
        for(int j=1;j<=20;j++)
           for(int x=1;x<=20;x++)
           {
                if(i<j && j<x) 
                   num[i][j][x]=num[i][j][x-1]+num[i][j-1][x-1]-num[i][j-1][x];
                else
                    num[i][j][x]=num[i-1][j][x]+num[i-1][j-1][x]+num[i-1][j][x-1]-num[i-1][j-1][x-1];
           }
     while(true)
     {
           scanf("%d %d %d",&a,&b,&c);
           if(a==-1 && b==-1 && c==-1) break;
           if(a<=0 || b<=0 || c<=0) printf("w(%d, %d, %d) = %d\n",a,b,c,1);  
           else if(a>20 || b>20 || c>20) printf("w(%d, %d, %d) = %d\n",a,b,c,num[20][20][20]);
           else printf("w(%d, %d, %d) = %d\n",a,b,c,num[a][b][c]);         
     }
     system("pause");
     return 0;
}
