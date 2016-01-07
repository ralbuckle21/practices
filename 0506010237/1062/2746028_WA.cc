#include<iostream>
#include<math.h>
#define MAX 100000;
using namespace std;
int m,n;
void shortt(int v,int cost[100][100],int sign[100],int price[100])
{
     int u;
     bool s[100];
     int dist[100];
     for(int i=0;i<n;i++)
     {
        s[i]=0;
        dist[i]=cost[v][i];       
     }    
     s[v]=1;
     for(int i=1;i<n;i++)
     {
        int min=MAX;
        for(int j=0;j<n;j++)
        { 
            if(s[j]==0 && dist[j]<min && abs(sign[v]-sign[j])<=m)
            {   
               min=dist[j];
               u=j;     
            }
        }
        s[u]=1;
        for(int w=0;w<n;w++)
        {
            if(s[w]==0 && dist[w]>dist[u]+cost[u][w] && abs(sign[u]-sign[w])<=m)
              dist[w]=dist[u]+cost[u][w];        
        }
     }
     dist[0]=0;
     for(int i=0;i<n;i++)
       dist[i]=dist[i]+price[i];
     int min=MAX;
     for(int i=0;i<n;i++)
       if(dist[i]<min && abs(sign[v]-sign[i])<=m)
         min=dist[i];
     printf("%d\n",min);
}

int main()
{
    int i,j,h,v;
    scanf("%d %d",&m,&n);
    int cost[100][100],price[100],sign[100];
    for(i=0;i<n;i++)
      for(j=0;j<n;j++)
       cost[i][j]=MAX;
    for(i=0;i<n;i++)
    {
         scanf("%d %d %d",&price[i],&sign[i],&h);
         for(j=0;j<h;j++)
         {
           scanf("%d",&v);
           scanf("%d",&cost[i][v-1]);
           }                
    }
    shortt(0,cost,sign,price);
    system("pause");
    return 0;
}
