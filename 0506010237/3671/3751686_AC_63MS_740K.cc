#include<iostream>
using namespace std;
int n;
int v[30002];
int f[30002];
int g[30002];
int main()
{
     scanf("%d",&n);
     for(int i=1;i<=n;i++) scanf("%d",&v[i]);
     f[0]=0; g[n+1]=0;
     for(int i=1;i<=n;i++){
          if(v[i]==2) f[i]=f[i-1]+1;
          else f[i]=f[i-1];     
     }
     for(int i=n;i>=1;i--){
          if(v[i]==1) g[i]=g[i+1]+1;
          else g[i]=g[i+1];       
     }
     int mins=100000000;
     for(int i=0;i<=n;i++)
         if(f[i]+g[i+1]<mins)
            mins=f[i]+g[i+1];
     printf("%d\n",mins);
     system("pause");
     return 0;
}
