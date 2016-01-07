#include<iostream>
#define maxs INT_MAX
using namespace std;
int n,p,c,m;
int cost[501][501];
int cow[101];
int shortt(){
     bool s[501];
     int u,dist[501];
     for(int i=0;i<n;i++){
        s[i]=0;
        dist[i]=cost[0][i]; 
     }    
     s[0]=1;
     for(int i=1;i<n;i++){ 
        int min=maxs;
        for(int j=1;j<n;j++){
            if(s[j]==0 && dist[j]<min){ 
               min=dist[j];
               u=j;     
            }
        }
        s[u]=1;
        for(int w=0;w<n;w++){ 
            if(s[w]==0 && dist[w]>dist[u]+cost[u][w])
              dist[w]=dist[u]+cost[u][w];        
        }
     }
     dist[0]=0;
     int sum=0;
     for(int i=0;i<c;i++){  
          if(dist[cow[i]]<=m){
                cow[i]=-1;
                sum++;                    
          }    
     }
     printf("%d\n",sum);
     for(int i=0;i<c;i++)
         if(cow[i]==-1) printf("%d\n",i+1);
}
int main()
{
    int k,h,w;
    for(int i=0;i<501;i++)
        for(int j=0;j<501;j++)
           cost[i][j]=maxs/2;
    scanf("%d %d %d %d",&n,&p,&c,&m);
    for(int i=0;i<p;i++){
        scanf("%d %d %d",&k,&h,&w);
        cost[k-1][h-1]=cost[h-1][k-1]=w;     
    }
    for(int i=0;i<c;i++){
         scanf("%d",&k);
         cow[i]=k-1;        
    }
    shortt();
    system("pause");
    return 0;
}
