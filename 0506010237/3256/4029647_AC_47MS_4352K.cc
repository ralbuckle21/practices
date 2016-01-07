#include<iostream>
using namespace std;
int graze[1001][1001];
int c[1001];
bool visit[1001];
int cow[101];
int k,n,m;
void dfs(int x){
    visit[x]=true;
    c[x]++;
    for(int i=1;i<=graze[x][0];i++)
        if(!visit[graze[x][i]]) dfs(graze[x][i]);      
}
int main(){
    int x,y,sum=0;
    scanf("%d%d%d",&k,&n,&m);
    for(int i=1;i<=k;i++) scanf("%d",&cow[i]);
    for(int i=1;i<=m;i++){
        scanf("%d%d",&x,&y); 
        graze[x][++graze[x][0]]=y;       
    }
    for(int i=1;i<=k;i++){
        memset(visit,0,sizeof(visit));
        dfs(cow[i]);        
    }
    for(int i=1;i<=n;i++) if(c[i]==k) sum++;
    printf("%d\n",sum);
    system("pause");
    return 0;
}
