#include<iostream>
#include<math.h> 
using namespace std;
int maxs=int(pow(2,31))-1;
int cost[1001][1001];
bool visit[1001];
int dist[1001];
int n,m;
void init(){
     for(int i=1;i<=n;i++) 
         for(int j=1;j<=n;j++)
             cost[i][j]=maxs;     
}
int mins(int a,int b){ return a<b?a:b; }
int shortt(int s,int d){
     int u;
     for(int i=1;i<=n;i++){
        visit[i]=0;
        dist[i]=cost[s][i]; 
     }    
     visit[s]=1; dist[s]=0;
     for(int i=1;i<n;i++){ 
        int min=maxs;
        for(int j=1;j<=n;j++){ 
            if(visit[j]==0 && dist[j]<min){   
               min=dist[j];
               u=j;     
            }
        }
        if(u==d) return min;
        visit[u]=1;
        for(int w=1;w<=n;w++){ 
            if(visit[w]==0 && cost[u][w]!=maxs && dist[w]>dist[u]+cost[u][w])
              dist[w]=dist[u]+cost[u][w];        
        }
     }
}
int main(){
    int x,y,w;
    scanf("%d%d",&n,&m);
    init();
    for(int i=0;i<m;i++){
          scanf("%d%d%d",&x,&y,&w);
          cost[x][y]=cost[y][x]=mins(cost[x][y],w);        
    }
    printf("%d\n",shortt(n,1));
    system("pause");
    return 0;
}
