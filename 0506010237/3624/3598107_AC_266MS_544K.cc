#include<iostream>
using namespace std;
int n,m;
int w[3403];
int c[3403];
int f[2][12881];
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d %d",&w[i],&c[i]);
    for(int i=0;i<=m;i++) f[0][m]=0;
    for(int i=1;i<=n;i++){
        int cur=i%2,pre=(i+1)%2;
        for(int j=1;j<=m;j++){
           if(j>=w[i]){
                 if(f[pre][j-w[i]]+c[i]>=f[pre][j]) f[cur][j]=f[pre][j-w[i]]+c[i];
                 else f[cur][j]=f[pre][j];
           }            
           else f[cur][j]=f[pre][j];
        }        
    } 
    printf("%d\n",f[(n%2)][m]);
    system("pause");
    return 0;
}
