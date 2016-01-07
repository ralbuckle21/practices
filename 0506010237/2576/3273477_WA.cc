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
                 if(j>=w[i] && f[i-1][j-w[i]]+w[i]>f[i-1][j])
                 {
                       f[i][j]=f[i-1][j-w[i]]+w[i];
                       g[i][j]=g[i-1][j-w[i]]+1;       
                 }       
                 else
                 {
                       f[i][j]=f[i-1][j];
                       g[i][j]=g[i-1][j];    
                 }
           }      
     }
     int mins=10000000;
     for(int i=n/2-1;i<=n;i++)
     {
        for(int j=0;j<=sum/2+1;j++)
        {
            if(abs(n-2*g[i][j])<=1&&(abs(sum-2*mins)>abs(sum-2*f[i][j])))
                      mins=f[i][j];
        }
     }
     if(sum-mins<mins)  printf("%d %d\n",sum-mins,mins);
     else printf("%d %d\n",mins,sum-mins);
     system("pause");
     return 0;
}
