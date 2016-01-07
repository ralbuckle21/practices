#include<iostream>
#include<math.h> 
using namespace std;
const int maxs=INT_MAX;
int cost[1005][1005];
bool visit[1005];
int dist[1005];
int n,m;
void init(){
     for(int i=1;i<=n;i++) 
         for(int j=1;j<=n;j++)
             cost[i][j]=maxs;     
}
int shortt(int s,int d){
     int u;
     unsigned int mins;
     for(int i=1;i<=n;i++){
        visit[i]=0;
        dist[i]=cost[s][i]; 
     }    
     visit[s]=1;
     for(int i=1;i<n;i++){ 
        mins=maxs;
        for(int j=1;j<=n;j++){ 
            if(!visit[j] && dist[j]<mins){   
               mins=dist[j];
               u=j;     
            }
        }
        if(u==d) return mins;
        visit[u]=1;
        for(int w=1;w<=n;w++){ 
            if(!visit[w] && cost[u][w]!=maxs && dist[w]>dist[u]+cost[u][w])
              dist[w]=dist[u]+cost[u][w];        
        }
     }
}
int main(){
    int x,y,w;
    scanf("%d%d",&m,&n);
    init();
    for(int i=0;i<m;i++){
          scanf("%d%d%d",&x,&y,&w);
          if(w<cost[x][y]){
             cost[x][y]=cost[y][x]=w;
          }      
    }
    for(int i=1;i<=n;i++) cost[i][i]=0;
    printf("%d\n",shortt(1,n));
    system("pause");
    return 0;
}

