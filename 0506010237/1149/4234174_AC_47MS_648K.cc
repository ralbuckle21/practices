#include<iostream>
using namespace std;
const int maxs=1000000;
int map[1010][110];
int cost[110][110];
int m,n;
int pig[1010];
int v[110];
void readdata(){
    int x,k;
    scanf("%d%d",&m,&n);
    for(int i=1;i<=m;i++) scanf("%d",&pig[i]);
    for(int i=1;i<=n;i++){
         scanf("%d",&k);
         for(int j=1;j<=k;j++){
              scanf("%d",&x);
              map[x][++map[x][0]]=i;        
         }
         scanf("%d",&v[i]);        
    }     
    for(int i=1;i<=n;i++) cost[i][n+1]=v[i];
    for(int i=1;i<=m;i++){
        if(map[i][0]>=1) cost[0][map[i][1]]+=pig[i];
        for(int j=1;j<map[i][0];j++) cost[map[i][j]][map[i][j+1]]=maxs;        
    }
}
int net(){
     bool visit[110];
     int u,dist[110],path[110],s=0,t=n+1;
     for(int i=0;i<=n+1;i++){
        visit[i]=0;
        dist[i]=cost[s][i]; 
        path[i]=s;      
     }    
     visit[s]=1;path[s]=-1;
     while(true){
        int max=0;
        for(int j=1;j<=n+1;j++){
            if(!visit[j] && dist[j]>max){   
               max=dist[j];
               u=j;     
            }
        }
        if(max==0) return 0;
        visit[u]=1;
        if(u==t){
            int w1=path[t],w2=t;
            while(w1!=-1){
               cost[w1][w2]=cost[w1][w2]-dist[t];  
               if(w1!=s && w2!=t) cost[w2][w1]=cost[w2][w1]+dist[t];     
                w2=w1;w1=path[w2];
            }   
            return dist[t];
        }  
        for(int w=1;w<=n+1;w++){
            int minpath=dist[u]<cost[u][w]?dist[u]:cost[u][w];
            if(!visit[w] && dist[w]<minpath){
                   dist[w]=minpath;
                   path[w]=u;
             }        
        }
     }
}
void solve(){
    int totals=0,r;
    memset(cost,0,sizeof(cost));
    readdata();     
    while(true){
         r=net();
         if(r<=0) break;
         totals+=r;          
    }
    printf("%d\n",totals);
}
int main(){
    solve();
    system("pause");
    return 0;
}
