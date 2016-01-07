#include<iostream>
using namespace std;
const int basen=1010;
const int maxs=400000000;
int cost[basen][basen];
int flow[basen][basen];
int graph[basen][basen];
int dist[basen],pre[basen];
int n,e;
int S,T;
int money(){    
    int i,j,result=0;    
    bool quit;    
    while(true){        
         for(i=0;i<=n+1;i++) dist[i]=maxs;        
         dist[S]=0;                
         while(true){ // bellman_fold算法求扩张最少费用流              
             quit=true;             
             for(i=0;i<=n+1;i++){             
                for(j=0;j<=n+1;j++){                    
                    if(flow[i][j]<graph[i][j] && cost[i][j]+dist[i]<dist[j]){            
                        dist[j]=dist[i]+cost[i][j];                          
                        pre[j]=i;                          
                        quit=false;                                              
                    }                           
                }                      
             }                
             if(quit) break;                       
         }        
         if(dist[T]==maxs) break;        
         int mins=maxs;        
         j=T;        
         while(j!=S){ //逆向求出流量              
             i=pre[j];             
             if(graph[i][j]-flow[i][j]<mins) mins=graph[i][j]-flow[i][j];             
             j=i;        
         }              
         j=T;        
         while(j!=S){ //更新流量              
             i=pre[j];             
             flow[i][j]+=mins;             
             flow[j][i]-=flow[i][j];             
             j=i;                    
         }        
         result+=mins*dist[T]; 
    }    
    return result;   
}
void solve(){
    int x,y,w;
    memset(flow,0,sizeof(flow));
    memset(graph,0,sizeof(graph));
    scanf("%d%d",&n,&e); 
    for(int i=0;i<=n+1;i++)
        for(int j=0;j<=n+1;j++)
            cost[i][j]=maxs;
    for(int i=0;i<e;i++){
        scanf("%d%d%d",&x,&y,&w);
        graph[x][y]=1; 
        if(cost[x][y]>w){
             cost[x][y]=w;
             cost[y][x]=-w;
        }
    }
    graph[0][n+1]=2; cost[0][n+1]=0;
    graph[n+1][1]=2; cost[n+1][1]=0;
    S=0; T=n;
}
int main(){ 
    solve();       
    printf("%d\n",money());
    system("pause");    
    return 0;
}
