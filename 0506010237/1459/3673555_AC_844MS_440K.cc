#include<iostream>
using namespace std;
int n,m,np,nc;
int cost[110][110];
int net(){
     bool visit[110];
     int u,dist[110],path[110];
     for(int i=0;i<=n;i++){
        visit[i]=0;
        dist[i]=cost[0][i]; 
        path[i]=0;      
     }    
     visit[0]=1;path[0]=-1;
     for(int i=1;i<=n;i++){
        int max=0;
        for(int j=1;j<=n;j++){
            if(visit[j]==0 && dist[j]>max){   
               max=dist[j];
               u=j;     
            }
        }
        if(max==0) return 0;
        visit[u]=1;
        if(u==n){
            int w1=path[n],w2=n;
            while(w1!=-1){
               cost[w1][w2]=cost[w1][w2]-dist[n];  
               if(w1!=0 && w2!=n) cost[w2][w1]=cost[w2][w1]+dist[n];     
               w2=w1;w1=path[w2];
            }   
            return dist[n];
        }  
        for(int w=1;w<=n;w++){
            int minpath=dist[u]<cost[u][w]?dist[u]:cost[u][w];
            if(visit[w]==0 && dist[w]<minpath){
                   dist[w]=minpath;
                   path[w]=u;
             }        
        }
     }
}
void total(){
    int w1,w2,pow,totals=0;
    char c;
    memset(cost,0,sizeof(cost));
    for(int i=0;i<m;i++){
         c=getchar();
         while(c!='(') c=getchar();
         scanf("%d",&w1);getchar();
         scanf("%d",&w2);getchar();
         scanf("%d",&pow);
         cost[w1+1][w2+1]=pow;       
    }
    for(int i=0;i<np;i++){
         c=getchar();
         while(c!='(') c=getchar();
         scanf("%d",&w2);getchar();
         scanf("%d",&pow);
         cost[0][w2+1]=pow;                  
    }
    for(int i=0;i<nc;i++){
         c=getchar();
         while(c!='(') c=getchar();
         scanf("%d",&w1);getchar();
         scanf("%d",&pow);
         cost[w1+1][n]=pow;                  
    }
    if(nc!=0)
    while(true){
          int maxs=net();
          if(maxs<=0) break;
          totals=totals+maxs;           
    }
    printf("%d\n",totals);          
}
int main()
{
     while(scanf("%d %d %d %d",&n,&np,&nc,&m)!=EOF){
        n=n+1;
        total();                
     }
     system("pause");
     return 0;
}
