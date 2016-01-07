#include<iostream>
using namespace std;
int net(int s,int t,int cost[201][201],int n)
{
     int u;
     bool visit[n];
     int dist[n],path[n];
     for(int i=1;i<=n;i++)
     {
        visit[i]=0;
        dist[i]=cost[s][i]; 
        path[i]=s;      
     }    
     visit[s]=1;
     path[s]=-1;
     for(int i=1;i<n;i++)
     {
        int max=0;
        for(int j=1;j<=n;j++)
        { 
            if(visit[j]==0 && j!=s && dist[j]>max)
            {   
               max=dist[j];
               u=j;     
            }
        }
        if(max==0)
           return 0;
        visit[u]=1;
        if(u==t)
        {
           int w1,w2;
           w1=path[t];
           w2=t;
           while(w1!=-1)
           {
               cost[w1][w2]=cost[w1][w2]-dist[t];  
               if(w1!=s && w2!=t) 
                  cost[w2][w1]=cost[w2][w1]+dist[t];     
                w2=w1;
                w1=path[w2];
           }   
           return dist[t];
        }  
        for(int w=1;w<=n;w++)
        {
            int minpath=dist[u]<cost[u][w]?dist[u]:cost[u][w];
            if(visit[w]==0 && dist[w]<minpath)
             {
                   dist[w]=minpath;
                   path[w]=u;
             }        
        }
     }
}
void total()
{
   while(true)
   {
    int totals=0;
    int max=0;
    int n,e,cost[201][201];
    cin>>e;
    cin>>n;
    if(n<2)
       break;
    for(int i=0;i<=n;i++)
     for(int j=0;j<=n;j++)
          cost[i][j]=0;
    for(int i=0;i<e;i++)
    {
        int w1,w2,pow;
        cin>>w1;
        cin>>w2;
        cin>>pow;
        cost[w1][w2]=pow;        
    }
    while(true)
    {
        max=net(1,n,cost,n);
        if(max<=0)
          break;
        totals=totals+max;           
    }
    cout<<totals<<endl;           
   }
}
int main()
{
   total();
   system("pause");
   return 0;
}
