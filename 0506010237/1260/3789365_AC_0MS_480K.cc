#include<iostream>
using namespace std;
const int maxs=INT_MAX;
int w[110][110];
int f[110];
int n,t;
int p[110][2];
int main()
{
     scanf("%d",&t);
     while(t--){
         scanf("%d",&n);
         for(int i=1;i<=n;i++) scanf("%d%d",&p[i][0],&p[i][1]);        
         for(int i=1;i<=n;i++){
             for(int j=1;j<=n;j++){
                 w[i][j]=10;
                 for(int h=i;h<=j;h++)  w[i][j]+=p[h][0];
                 w[i][j] *= p[j][1];        
             }        
         }
         f[0]=0;
         for(int i=1;i<=n;i++){
              f[i]=maxs;
              for(int j=0;j<i;j++){
                  int v=f[j]+w[j+1][i];
                  if(v<f[i]) f[i]=v;        
              }
         }
         cout<<f[n]<<endl;           
     }
     system("pause");
     return 0;
}
