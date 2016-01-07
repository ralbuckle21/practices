#include<iostream>
using namespace std;
const int maxs=INT_MAX;
int n,p,k;
int cost[1010][1010];
int f[1010][501];
bool visit[1010][501];
void init(){
     for(int i=0;i<=1000;i++)
        for(int j=0;j<=1000;j++)
            cost[i][j]=maxs; 
     for(int i=0;i<=1000;i++)
        for(int j=0;j<=500;j++)
            f[i][j]=maxs;   
}
int maxv(int a,int b){ return a>b?a:b; }
int minv(int a,int b){ return a<b?a:b; }
int shortpath(){
     int u,v,m=n*(k+1);
     for(int i=2;i<=n;i++){
         if(cost[1][i]!=maxs && k>0) f[i][1]=0;
         f[i][0]=cost[1][i];    
     }
     for(int i=1;i<m;i++){
         int min=maxs;
         for(int j=1;j<=n;j++)
            for(int t=0;t<=k;t++)
                if(!visit[j][t] && min>f[j][t]){
                     min=f[j][t];
                     u=j;
                     v=t;
                }
         if(u==n || min==maxs) return min;
         visit[u][v]=true;
         for(int w=2;w<=n;w++){ 
             if(cost[u][w]!=maxs){
                  int vv=maxv(f[u][v],cost[u][w]);
                  f[w][v]=minv(vv,f[w][v]);
                  if(v<k) f[w][v+1]=minv(f[u][v],f[w][v+1]);                     
             }        
        }        
     }              
     return maxs;
}
int main()
{ 
     init();
     int s,d,w;  
     scanf("%d %d %d",&n,&p,&k);
     while(p--){
         scanf("%d%d%d",&s,&d,&w);
         cost[s][d]=w;
         cost[d][s]=w;           
     }
     int result=shortpath();
     if(result<maxs)  printf("%d\n",result);
     else printf("-1\n");
     system("pause");
     return 0;
}
