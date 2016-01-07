#include<iostream>
#include<math.h> 
using namespace std;
long long maxs=0xffffffff;
long long cost[1101][1101];
bool visit[1101];
long long dist[1101];
int n,m;
void init(){
     for(int i=1;i<=n;i++) 
         for(int j=1;j<=n;j++)
             cost[i][j]=maxs;     
}
long long mins(long long a,long long b){ return a<b?a:b; }
long long shortt(int s,int d){
     int u;
     for(int i=1;i<=n;i++){
        visit[i]=0;
        dist[i]=cost[s][i]; 
     }    
     visit[s]=1; 
     for(int i=1;i<n;i++){ 
        long long min=maxs;
        for(int j=1;j<=n;j++){ 
            if(!visit[j] && dist[j]<min){   
               min=dist[j];
               u=j;     
            }
        }
        if(u==d) return min;
        visit[u]=1;
        for(int w=1;w<=n;w++){ 
            if(!visit[w] && dist[w]>dist[u]+cost[u][w])
              dist[w]=dist[u]+cost[u][w];        
        }
     }
}
int main(){
    long long x,y,w;
    scanf("%d%d",&n,&m);
    init();
    for(int i=0;i<m;i++){
          cin>>x>>y>>w;
          cost[x][y]=cost[y][x]=mins(cost[x][y],w);        
    }
    for(int i=1;i<=n;i++) cost[i][i]=0;
    cout<<shortt(1,n)<<endl;
    system("pause");
    return 0;
}
