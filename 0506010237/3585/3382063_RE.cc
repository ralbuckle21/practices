#include<iostream>
using namespace std;
int sum=0;
int net(int s,int t,int cost[501][501],int n){//是通过最短路径所改
     bool visit[501];
     int u,dist[501],path[501];//dist记录的是从起点到其它点的最少距离path记录点的前驱
     for(int i=1;i<=n;i++){
        visit[i]=0;
        dist[i]=cost[s][i]; 
        path[i]=s;      
     }    
     visit[s]=1;path[s]=-1;
     for(int i=1;i<n;i++){
        int max=0;
        for(int j=1;j<=n;j++){//找出离起点距离最短的且未被访问的点 
            if(visit[j]==0 && j!=s && dist[j]>max){   
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
               if(w1!=s && w2!=t)cost[w2][w1]=cost[w2][w1]+dist[t];     
                w2=w1;w1=path[w2];
            }   
            return dist[t];
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
    int n,t,totals=0,max=0,cost[501][501],nums[501][501],sign[501];
    scanf("%d",&t);
    while(t--){//可接受多组测试语句
         scanf("%d",&n);
         memset(cost,0,sizeof(cost));
         memset(sign,0,sizeof(sign));
         for(int i=1;i<n;i++){
             int w1,w2,pow;
             scanf("%d %d %d",&w1,&w2,&pow);
             cost[w1][w2]=cost[w1][w2]+pow; 
             cost[w2][w1]=cost[w1][w2];   
             sign[w1]++;
             sign[w2]++;    
         }
         n++;
         for(int i=1;i<n;i++){
             for(int x=1;x<n;x++){
                for(int y=1;y<n;y++)
                     nums[x][y]=cost[x][y];
                if(sign[x]==1) nums[x][n]=nums[n][x]=100000000;
                else nums[x][n]=nums[n][x]=0;
             }    
             nums[i][n]=0;
             while(true){
                 max=net(i,n,nums,n);
                 if(max<=0) break;//找不到增广路
                 totals=totals+max;           
             }
             if(sum<totals) sum=totals;
             totals=0;
         }
         printf("%d\n",sum);  
         sum=0;  
    }
}
int main()
{
   total();
   system("pause");
   return 0;
}
