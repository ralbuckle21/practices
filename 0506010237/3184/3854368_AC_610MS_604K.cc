#include<iostream>
using namespace std;
const int maxs=INT_MAX/10;
int f[2][10001];
int g[2][10000];
int x[10000];
int n,len,k,d;
int abv(int a){ return a>0?a:-a; }
int main()
{
     int base,pre,s,y;
     scanf("%d%d",&n,&len); n--;
     for(int i=0;i<=n;i++) scanf("%d",&x[i]);
     if(n==0){ cout<<0<<endl; return 0;}
     d=len/n; k=len%n;
     for(int i=1;i<=k;i++) f[0][i]=maxs;
     f[0][0]=x[0];
     base=0; pre=1;
     for(int i=1;i<=n;i++){
          base=pre; pre=1-pre;
          s=k+i-n; y=i<k?i:k;
          if(s<=0){
              f[base][0]=f[pre][0]+abv(g[pre][0]+d-x[i]);
              g[base][0]=g[pre][0]+d;
              s=1;
          }
          for(int j=s;j<=y;j++){
                int v=f[pre][j-1]+abv(g[pre][j-1]+d+1-x[i]);
                int v1=f[pre][j]+abv(g[pre][j]+d-x[i]);
                if(v<v1){ f[base][j]=v; g[base][j]=g[pre][j-1]+d+1; }
                else{ f[base][j]=v1; g[base][j]=g[pre][j]+d; }   
          }    
          f[base][y+1]=maxs;
     }
     printf("%d\n",f[base][k]);
     system("pause");
     return 0;
}
