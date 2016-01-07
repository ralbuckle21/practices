#include<iostream>
using namespace std;
const int maxs=INT_MAX/3;
int f[3831][3831][2];
int g[3831][3831][2];
int a[3831];
int n,m;
int maxv(int x,int y){ return x>y?x:y; }
void dp(){
    for(int i=0;i<=m;i++) f[1][i][0]=f[1][i][1]=g[1][i][0]=g[1][i][1]=-maxs;
    f[1][0][0]=f[1][1][1]=0;
    g[1][0][0]=0; g[1][1][1]=a[1];
    for(int i=2;i<=n;i++){
        f[i][0][1]=-maxs;
        g[i][0][1]=-maxs;
        for(int j=1;j<=m;j++){
              if(j>i) {
                   f[i][j][0]=f[i][j][1]=-maxs;
                   g[i][j][0]=g[i][j][1]=-maxs;        
              }
              f[i][j][0]=maxv(f[i-1][j][0],f[i-1][j][1]);
              if(j>0) f[i][j][1]=maxv(f[i-1][j-1][0],f[i-1][j-1][1]+a[i]);
              g[i][j][0]=maxv(g[i-1][j][0],g[i-1][j][1]);   
              if(j>0) g[i][j][1]=maxv(g[i-1][j-1][0],g[i-1][j-1][1]+a[i]);       
        }        
    }     
    int result=maxv(maxv(f[n][m][0],f[n][m][1]),g[n][m][1]);
    printf("%d\n",result);
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    dp();
    system("pause");
    return 0;
}
