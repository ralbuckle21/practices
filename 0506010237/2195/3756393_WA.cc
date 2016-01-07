#include<iostream>
using namespace std;
const int maxs=INT_MAX;
char c[110][110];
int n,m;
struct{
    int x;
    int y;   
}point[210];
struct{
      int cost;//费用
      int mg;//容量
      int rmg;//反向(对方)所引起的不需费用的容量,等于从对方运过来的流 
}num[210][210];
int len=0;
int abv(int a){ return a>0?a:-a; }
int feiyong(int n){
       bool visit[210];
       int u,dist[210],path[210],distmg[210];
       for(int i=1;i<n;i++){
           visit[i]=0;
           dist[i]=num[0][i].cost;//起点到i的费用
           distmg[i]=num[0][i].mg;//起点到i的流量  
           path[i]=0;  //记录前驱   
       }
       visit[0]=1;path[0]=-1;
       for(int i=1;i<n;i++){
          int min=maxs;
          for(int j=1;j<n;j++){ //找费用最少的流
               if(visit[j]==0 && dist[j]<min && distmg[j]>0){   
                  min=dist[j];
                  u=j;   
               }
          }
          if(min==maxs)return 0; //没有找到增广路
          visit[u]=1;
          if(u==n-1){//终点认为是n-1
             int w1=path[u],w2=u;
             while(w1!=-1){
                 if(num[w1][w2].rmg>0){//已存在反向流量
					 if(num[w1][w2].rmg>=distmg[u]){//反向流够用
                         num[w1][w2].rmg=num[w1][w2].rmg-distmg[u];
                         num[w2][w1].mg=num[w2][w1].mg+distmg[u];
					 }
					 else{//反向流不够用
                         num[w2][w1].mg=num[w2][w1].mg+num[w1][w2].rmg;//对方本来流容量增加						 num[w1][w2].mg=num[w1][w2].mg-distmg[u]+num[w1][w2].rmg;//流容量减少num[w2][w1].rmg=num[w2][w1].rmg-distmg[u]+num[w1][w2].rmg;//对方反向留增加
						 num[w1][w2].rmg=0;
					 }
                 }
                 else{//不存在反向流
                     num[w1][w2].mg=num[w1][w2].mg-distmg[u];
                     if(w1!=0 && w2!=n-1)num[w2][w1].rmg=num[w2][w1].rmg+distmg[u]; 
                 }
                 w2=w1;w1=path[w2];
              }   
              return distmg[u]*dist[u];
           }  
           for(int w=1;w<n;w++){
                if(visit[w]==0){
                    if(num[u][w].rmg>0  && (dist[w]>dist[u]-num[w][u].cost)){
						/*w->u已有运量。则存在反向流可以节约*/
                         dist[w]=dist[u]-num[w][u].cost;//可以把w,u流的价格给节约起来
                         distmg[w]=distmg[u]<=num[u][w].rmg?distmg[u]:num[u][w].rmg;   
                         path[w]=u;
                    }
                    else if(num[w][u].rmg==0 && num[u][w].mg!=0 && (dist[w]>dist[u]+num[u][w].cost)){
                         dist[w]=dist[u]+num[u][w].cost;
                         distmg[w]=distmg[u]<=num[u][w].mg?distmg[u]:num[u][w].mg;
                         path[w]=u;    
                    }                   
               }      
           }
      }
}
void startfei(){
     int sum=0,v; 
     while(true){
         v=feiyong(n);
         if(v<=0) break; //找不到增广路
         sum+=v;         
     }   
     printf("%d\n",sum);      
}
void input(){
     while(true){
         scanf("%d %d",&n,&m);
         if(n==0 && m==0) break;
         for(int i=0;i<n;i++) scanf("%s",c[i]);
         len=1;
         for(int i=0;i<n;i++)
             for(int j=0;j<m;j++)
                if(c[i][j]=='H'){  point[len].x=i;point[len].y=j; len++; }
         for(int i=0;i<n;i++)
             for(int j=0;j<m;j++)           
                if(c[i][j]=='m'){  point[len].x=i;point[len].y=j; len++; }
         memset(num,0,sizeof(num)); len--;
         for(int i=1;i<=len;i++)
             for(int j=1;j<=len;j++){
                num[i][j].mg=maxs;      
                num[i][j].cost=abv(point[j].x-point[i].x)+abv(point[j].y-point[i].y);
                num[i][j].rmg=0;
             } 
         for(int i=1;i<=len/2;i++){
             num[0][i].mg=1;num[0][i].cost=0;num[0][i].rmg=0;    
             num[0][len/2+i].cost=maxs;    
         }
         for(int i=len/2+1;i<=len;i++){
             num[i][len+1].mg=1;num[i][len+1].cost=0;num[i][len+1].rmg=0;  
             num[i-len/2][len+1].cost=maxs;      
         }
         num[0][len+1].cost=maxs;
         n=len+2;
         startfei();       
    }      
}
int main()
{
     input();
     system("pause");
     return 0;
}
