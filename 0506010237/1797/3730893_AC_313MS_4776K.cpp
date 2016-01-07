#include<iostream>
using namespace std;
int t,n,m;
int cost[1004][1004];
int mins(int a,int b){ return a<b?a:b; }
int dijstra(){
     bool visit[1004];
     int dist[1004];
     for(int i=2;i<=n;i++){
        dist[i]=cost[1][i];
        visit[i]=false;
     }
     while(true){
          int maxs=0,u;
          for(int i=2;i<=n;i++) 
               if(!visit[i] && maxs<dist[i]){
                    maxs=dist[i];
                    u=i;                 
               }        
          if(u==n || maxs==0) return maxs;
          visit[u]=true;
          for(int w=2;w<=n;w++){
               int v=mins(dist[u],cost[u][w]);
               if(!visit[w] && dist[w]<v)
                    dist[w]=v;        
          }  
     }   
}
int main()
{
     int s,d,w;
     scanf("%d",&t);
     for(int i=1;i<=t;i++){
         scanf("%d%d",&n,&m);
         memset(cost,0,sizeof(cost));
         for(int j=0;j<m;j++){
              scanf("%d%d%d",&s,&d,&w);
              cost[s][d]=w;
              cost[d][s]=w;        
         }        
         printf("Scenario #%d:\n",i);
         printf("%d\n\n",dijstra());
     }
     system("pause");
     return 0;
}
