#include<iostream>
using namespace std;
int n,m;
int cost[20000][20000];
int shortt(int v,int t)
{
     int u;
     bool s[n];
     int dist[n];
     for(int i=0;i<n;i++)
     {
        s[i]=0;
        dist[i]=cost[v][i];       
     }    
     s[v]=1;
     for(int i=1;i<n;i++)
     {
        int maxs=0;
        for(int j=1;j<=n;j++)
        { 
            if(s[j]==0 && j!=v && dist[j]>maxs)
            {   
                maxs=dist[j];
                u=j;     
            }
        }
        if(u==t) return dist[u];
        s[u]=1;
        for(int w=0;w<n;w++)
        {
            if(s[w]==0 && dist[w]<dist[u]+cost[u][w])
              dist[w]=dist[u]+cost[u][w];        
        }
     }
}
int main()
{
       int mins=0,s,t,d,c;
       while(scanf("%d %d",&n,&m)!=EOF)
       {
              memset(cost,0,sizeof(0));   
              for(int i=1;i<=m;i++)
              {
                      scanf("%d %d %d %c",&s,&t,&d,&c);
                      cost[s][t]=d;
                      cost[t][s]=d;
              } 
              for(int i=1;i<n;i++)
                 for(int j=i+1;j<=n;j++)
                 {
                      int way=shortt(i,j);
                      if(way>mins) mins=way;        
                 }  
              printf("%d\n",mins);        
       }
       system("pause");
       return 0;
}
