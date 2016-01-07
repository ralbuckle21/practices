#include<iostream>
using namespace std;
typedef struct{
     int x;
     int y;
     int pow;
     int powx;   
}edge;
int sum=0;
int net(int s,int t,edge e[10002],int n,int hs){
     bool visit[10002];
     int u,dist[10002],path[10002];
     for(int i=1;i<=n;i++){ visit[i]=0;path[i]=s;dist[i]=0;}
     for(int i=1;i<hs;i++) if(e[i].x==s) dist[e[i].y]=e[i].powx;           
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
               int f1=1,f2;
               while(f1<hs &&(e[f1].x!=w1 || e[f1].y!=w2)) f1++;
               f2=f1+1;
               e[f1].powx=e[f1].powx-dist[t]; 
               if(w1!=s && w2!=t) e[f2].powx=e[f2].powx+dist[t];     
               w2=w1;w1=path[w2];
            }   
            return dist[t];
        }  
        for(int w=1;w<=n;w++){
            int f=1;
            while(f<hs && (e[f].x!=u || e[f].y!=w)) f++;
            if(f==hs) continue;
            f=e[f].powx;
            int minpath=dist[u]<f?dist[u]:f;
            if(visit[w]==0 && dist[w]<minpath){
                   dist[w]=minpath;
                   path[w]=u;
            }        
        }
     }
}
void total(){
    int n,t,totals=0,max=0,sign[10002];
    edge e[10010];
    scanf("%d",&t);
    while(t--){//可接受多组测试语句
         scanf("%d",&n);
         memset(sign,0,n+2);
         int hs=1;
         for(int i=1;i<n;i++){
             int w1,w2,pow;
             scanf("%d %d %d",&e[hs].x,&e[hs].y,&e[hs].pow); 
             sign[e[hs].x]++;sign[e[hs].y]++; hs++;
             e[hs].x=e[hs-1].y;e[hs].y=e[hs-1].x;e[hs].pow=e[hs-1].pow; hs++;     
         }
         for(int i=1;i<=n;i++){
             for(int x=1;x<hs;x++) e[x].powx=e[x].pow;   
             for(int j=1;j<=n;j++){
                 if(sign[j]==1 && j!=i){ 
                       while(true){
                           max=net(i,j,e,n,hs);
                           if(max<=0) break;//找不到增广路
                           totals=totals+max;
                       }
                 }           
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
