#include<iostream>
using namespace std;
int n,m;
int w[401];
int c[401];
int f[401][ 12881];
int max(int a,int b){  return a>b?a:b;   }
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d %d",&w[i],&c[i]);
    for(int i=1;i<=n;i++) f[i][0]=0;
    for(int i=1;i<=m;i++) f[0][i]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(j>=w[i]) f[i][j]=max(f[i-1][j-w[i]]+c[i],f[i-1][j]);            
            else f[i][j]=f[i-1][j];
        }        
    } 
    printf("%d\n",f[n][m]);
    system("pause");
    return 0;
}
