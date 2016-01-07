#include<iostream>
#include<math.h>
using namespace std;
int cs=1,n,m;
double cost[1004][1004];
int num[1004][2];
double maxs(double a,double b){ return a>b?a:b; }
double sqr(double a){ return a*a; }
double dijstra(){
     bool visit[1004];
     double dist[1004];
     for(int i=2;i<=n;i++){
        dist[i]=cost[1][i];
        visit[i]=false;
     }
     double vvv=0;
     while(true){
          double mins=1000000000;
          int u;
          for(int i=2;i<=n;i++) 
               if(!visit[i] && mins>dist[i]){
                    mins=dist[i];
                    u=i;                 
               }             
          if(u==2) return mins;
          visit[u]=true;
          for(int w=2;w<=n;w++){
               double v=maxs(dist[u],cost[u][w]);
               if(!visit[w] && dist[w]>v)
                    dist[w]=v;        
          }  
     }   
}
int main()
{
     int s,d,w;
     while(true){
         scanf("%d",&n); 
         if(n==0) break;
         for(int i=1;i<=n;i++) scanf("%d %d",&num[i][0],&num[i][1]);
         for(int i=1;i<=n;i++){
              cost[i][i]=1000000000;
              for(int j=i+1;j<=n;j++){
                   cost[i][j]=sqrt(sqr(num[i][0]-num[j][0])+sqr(num[i][1]-num[j][1]));
                   cost[j][i]=cost[i][j];        
              }      
         }
         printf("Scenario #%d:\n",cs++);
         printf("%.3f\n\n",dijstra());
     }
     system("pause");
     return 0;
}

