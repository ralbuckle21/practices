#include<iostream>
using namespace std;
int f[100005],g[100005];
int v[100005];
int n;
int main()
{
     int maxs;
     while(true){
          scanf("%d",&n);
          if(n==0) break;
          for(int i=1;i<=n;i++) scanf("%d",&v[i]);
          maxs=0; f[1]=v[1];
          if(f[1]>maxs) maxs=f[1];
          for(int i=2;i<=n;i++){
              if(f[i-1]>0) f[i]=f[i-1]+v[i];
              else f[i]=v[i];
              if(f[i]>=maxs) maxs=f[i];
              else f[i]=maxs;
          }
          maxs=0; g[n]=v[n];
          if(g[n]>maxs) maxs=g[n];
          for(int i=n-1;i>=1;i--){
              if(g[i+1]>0) g[i]=g[i+1]+v[i];
              else g[i]=v[i];
              if(g[i]>=maxs) maxs=g[i];
              else g[i]=maxs;
          }
          int maxs=0;
          for(int k=2;k<=n;k++)
              if(maxs<f[k-1]+g[k])
                  maxs=f[k-1]+g[k];
          printf("%d\n",maxs);             
     }
     system("pause");
     return 0;
}
