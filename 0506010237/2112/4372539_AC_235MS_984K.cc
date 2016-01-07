#include<iostream>
using namespace std;
const int maxs=1000000;
int cost[231][231];
int map[201][451];
int k,c,m,n;
bool searchs[451];
int pre[451];
bool dfs(int data,int vs){
    for(int i=1;i<=n;i++){
        if(map[data][i]<=vs && !searchs[i]){
             searchs[i]=true;
             if(pre[i]==0 || dfs(pre[i],vs)){
                 pre[i]=data;
                 return true;
             }
        }
    }
    return false;
} 
void read(){
    scanf("%d%d%d",&k,&c,&m);
    for(int i=1;i<=k+c;i++){
        for(int j=1;j<=k+c;j++){
             scanf("%d",&cost[i][j]);
             if(cost[i][j]==0) cost[i][j]=maxs;        
        }        
    }     
}
void floyd(){ 
    for(int u=1;u<=k+c;u++)
       for(int v=1;v<=k+c;v++)
         for(int w=1;w<=k+c;w++)
            if(cost[v][w]>cost[v][u]+cost[u][w])
               cost[v][w]=cost[v][u]+cost[u][w];  
}
bool find(int vs){
    memset(pre,0,sizeof(pre));
    for(int i=1;i<=c;i++){ 
         memset(searchs,0,sizeof(searchs));
         if(!dfs(i,vs)) return false;
    }
    return true;
}
void solve(){
    floyd(); 
    for(int j=k+1;j<=k+c;j++){
        n=0;
        for(int i=1;i<=k;i++)
            for(int h=1;h<=m;h++)
                map[j-k][++n]=cost[i][j];  
    }
    int left=0,right=46000,mid;
    while(left<=right){
        mid=(left+right)/2;
        if(!find(mid)) left=mid+1;
        else right=mid-1;                    
    }         
    printf("%d\n",left);
}
int main(){
    read();
    solve();
    system("pause");
    return 0;
}
