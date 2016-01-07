#include<iostream>
using namespace std;
const int maxs=INT_MAX/3;
int f[2][3831][2];
int g[2][3831][2];
int a[3831];
int n,m;
int maxv(int x,int y){ return x>y?x:y; }
void dp(){
    int pre=0,cur=1;
    for(int i=0;i<=m;i++) f[1][i][0]=f[1][i][1]=g[1][i][0]=g[1][i][1]=-maxs;
    f[1][0][0]=f[1][1][1]=0;
    g[1][0][0]=0; g[1][1][1]=a[1];
    for(int i=2;i<=n;i++){
        pre=cur; cur=(cur+1)%2;
        f[cur][0][1]=-maxs;
        g[cur][0][1]=-maxs;
        for(int j=1;j<=m;j++){
              f[cur][j][0]=maxv(f[pre][j][0],f[pre][j][1]);
              f[cur][j][1]=maxv(f[pre][j-1][0],f[pre][j-1][1]+a[i]);
              g[cur][j][0]=maxv(g[pre][j][0],g[pre][j][1]);   
              g[cur][j][1]=maxv(g[pre][j-1][0],g[pre][j-1][1]+a[i]);       
        }        
    }     
    int result=maxv(maxv(f[cur][m][0],f[cur][m][1]),g[cur][m][1]);
    printf("%d\n",result);
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    dp();
    system("pause");
    return 0;
}
