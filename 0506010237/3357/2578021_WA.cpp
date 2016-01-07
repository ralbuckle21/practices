#include<iostream>
#include<stdio.h>
using namespace std;
int maxs=1000000;
typedef struct 
{
      char start;
      char stop;
      int d; 
}node;
void prim(int cost[100][100],int n,int v)
{
    int lowcost[100],min,h=0;
    int close[100],i,j,k;
    node dist[100],key;
    for(i=0;i<n;i++)
    {
        if(cost[v][i]!=0 || v==i)
          lowcost[i]=cost[v][i];
        else
          lowcost[i]=maxs;
        close[i]=v;                
    }    
    for(i=1;i<n;i++)
    {
        min=32767;
        for(j=0;j<n;j++)
         if(lowcost[j]!=0 && lowcost[j]<min)
         {
            min=lowcost[j];
            k=j;                 
         } 
         if(close[k]<k)
         {
            dist[h].start=char(close[k]+'A');
            dist[h].stop=char(k+'A');
         }
         else
         {
            dist[h].stop=char(close[k]+'A');
            dist[h].start=char(k+'A');   
         }
         dist[h].d=min;
         h++;
         lowcost[k]=0;
         for(j=0;j<n;j++)
          if(cost[k][j]!=0 && cost[k][j]<lowcost[j])
          {
              lowcost[j]=cost[k][j];
              close[j]=k;                 
          }               
    }
     for(j=0;j<h;j++)
     {
           i=j-1;
           key=dist[j];
           while(i>=0 && dist[i].d>key.d)
           {
                dist[i+1]=dist[i]; 
               i--;   
           }       
           dist[i+1]=key;
     }   
    for(int t=0;t<h;t++)
    {
        printf("%c%c%c %d\n",dist[t].start,'-',dist[t].stop,dist[t].d);        
    }
}
int main()
{
    int n,k;
    int cost[100][100];
    scanf("%d",&k);
    for(int l=1;l<=k;l++)
    {
       scanf("%d",&n);
       for(int i=0;i<n;i++)
         for(int j=0;j<n;j++)
         {
           scanf("%d",&cost[i][j]);
           getchar();
         }
       printf("%s%d%c \n","Case ",l,':');
       prim(cost,n,0);
    }
    system("pause");
    return 0;
}
