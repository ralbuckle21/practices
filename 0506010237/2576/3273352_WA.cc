#include<iostream>
using namespace std;
int n,sum=0;
int f[101][45000];
int g[101][45000];
int w[101];
int main()
{
     scanf("%d",&n);
     for(int i=1;i<=n;i++)
     {
          scanf("%d",&w[i]);
          sum+=w[i];
     }
     for(int i=0;i<=n;i++)
     {
          f[i][0]=0;
          g[i][0]=0;
     }
     for(int i=0;i<=sum;i++) 
     {
          f[0][i]=0;
          g[0][i]=0;
     }
     for(int i=1;i<=n;i++)
     {
           for(int j=1;j<=sum;j++)
           {
                 if(j>w[i] && abs(f[i-1][j-w[i]]+w[i])<abs(f[i-1][j]-w[i]))
                 {
                       f[i][j]=f[i-1][j-w[i]]+w[i];
                       g[i][j]=g[i-1][j-w[i]]+1;       
                 }       
                 else
                 {
                       f[i][j]=f[i-1][j]-w[i];
                       g[i][j]=g[i-1][j];    
                 }
           }        
     }
     int mins=10000000;
     for(int i=1;i<=n;i++)
     for(int j=1;j<=sum;j++)
     {
          if(abs(f[i][j])<mins && g[i][j]<=(n+1)/2 && g[i][j]>=(n-1)/2)
                  mins=abs(f[i][j]);
     }
     printf("%d %d\n",(sum-mins)/2,(sum+mins)/2);
     system("pause");
     return 0;
}
