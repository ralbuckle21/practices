#include<iostream>
using namespace std;
int map[1001][1001];
bool g[1001][1001];
bool flag[1001];
int n,m;
void dfs(int k,int v){
    flag[k]=true;
    for(int i=1;i<=map[k][0];i++){
         if(!flag[map[k][i]] && g[k][map[k][i]]){
               g[v][map[k][i]]=true;  
               dfs(map[k][i],v);          
         }        
    }     
}
int main(){
    int x,y;
    memset(g,0,sizeof(g));
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
         scanf("%d%d",&x,&y);
         map[x][++map[x][0]]=y;
         g[x][y]=true;         
    }
    for(int i=1;i<=n;i++) g[i][i]=true;
    for(int i=1;i<=n;i++){
        memset(flag,0,sizeof(flag));
        dfs(i,i);        
    }
    int sum=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(!g[i][j] && !g[j][i]) sum++;        
        }        
    }
    printf("%d\n",sum);
    system("pause");
    return 0;
}
