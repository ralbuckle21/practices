#include<iostream>
using namespace std;
const int maxs=INT_MAX/2;
char c[210][210];
int n,m;
struct{
    int x,y;   
}point[410];
struct{
      int cost,c;
      int mg,rmg;
}num[410][410];
int len;
int abv(int a){ return a>0?a:-a; }
int good=0;
int feiyong(int n){
       bool visit[410];
       int u,dist[410],path[410],distmg[410];
       for(int i=1;i<n;i++){
           visit[i]=0;
           dist[i]=num[0][i].cost;
           distmg[i]=num[0][i].mg;
           path[i]=0;  
       }
       visit[0]=1;path[0]=-1;
       for(int i=1;i<n;i++){
          int min=maxs;
          for(int j=1;j<n;j++){ //找费用最少的流
               if(visit[j]==0 && dist[j]<min){   
                  min=dist[j];
                  u=j;   
               }
          }
          if(min==maxs)return min;
          visit[u]=1;
          if(u==n-1){
             int w1=path[u],w2=u;
             while(w1!=-1){
                 if(num[w1][w2].rmg>0){
                         num[w1][w2].rmg=num[w1][w2].rmg-distmg[u];
                         num[w2][w1].mg=num[w2][w1].mg+distmg[u];
                 }
                 else{
                     num[w1][w2].mg=num[w1][w2].mg-distmg[u];
                     if(w1!=0 && w2!=n-1) num[w2][w1].rmg=num[w2][w1].rmg+distmg[u]; 
                 }
                 w2=w1;w1=path[w1];
              }   
              return distmg[u]*dist[u];
           }  
           for(int w=1;w<n;w++){
                if(visit[w]==0){
                    if(num[u][w].rmg>0 && dist[w]>dist[u]-num[w][u].c){
                         dist[w]=dist[u]-num[w][u].c;
                         distmg[w]=distmg[u]<=num[u][w].rmg?distmg[u]:num[u][w].rmg;   
                         path[w]=u;
                    }
                    else if(dist[w]>dist[u]+num[u][w].cost){
                         dist[w]=dist[u]+num[u][w].cost;
                         distmg[w]=distmg[u]<=num[u][w].mg?distmg[u]:num[u][w].mg;
                         path[w]=u;    
                    }                   
               }      
           }
      }
}
void startfei(){
     int sum=0,v=0; 
     while(true){
         for(int i=0;i<n;i++)
             for(int j=0;j<n;j++)
                  if(num[i][j].mg==0) num[i][j].cost=maxs;
                  else num[i][j].cost=num[i][j].c;
        v=feiyong(n);
        if(v==maxs) break; //找不到增广路
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
                if(c[i][j]=='m'){  point[len].x=i;point[len].y=j; len++; }
         for(int i=0;i<n;i++)
             for(int j=0;j<m;j++)           
                if(c[i][j]=='H'){  point[len].x=i;point[len].y=j; len++; }
         memset(num,0,sizeof(num)); len--;
         for(int i=1;i<=len;i++)
             for(int j=1;j<=len;j++){
                num[i][j].mg=maxs;      
                num[i][j].c=abv(point[j].x-point[i].x)+abv(point[j].y-point[i].y);
                num[i][j].rmg=0;
             } 
         for(int i=1;i<=len/2;i++){
             num[0][i].mg=1;num[0][i].c=0;num[0][i].rmg=0;    
             num[i][len+1].c=maxs;    
         }
         for(int i=len/2+1;i<=len;i++){
             num[i][len+1].mg=1;num[i][len+1].c=0;num[i][len+1].rmg=0;  
             num[0][i].c=maxs;      
         }
         num[0][len+1].c=maxs;
         n=len+2;
         startfei();       
    }      
}
int main()
{
     //freopen("book.txt","r",stdin);
 //freopen("bb.txt","w",stdout);
     input();
     system("pause");
     return 0;
}
