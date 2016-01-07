#include<iostream>
using namespace std;
int maxs=1000000;
int sum=0;
void prim(int cost[100][100],int n,int v)
{
    int lowcost[100],min;
    int close[100],i,j,k;
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
        min=maxs;
        for(j=0;j<n;j++)
         if(lowcost[j]!=0 && lowcost[j]<min)
         {
            min=lowcost[j];
            k=j;                 
         } 
         sum=sum+min;
         lowcost[k]=0;
         for(j=0;j<n;j++)
          if(cost[k][j]!=0 && cost[k][j]<lowcost[j])
          {
              lowcost[j]=cost[k][j];
              close[j]=k;                 
          }               
    }
}
int main()
{
    int n;
    int cost[100][100];
    while(scanf("%d",&n)!=EOF)
    {
      for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
          scanf("%d",&cost[i][j]);
       prim(cost,n,0);
       printf("%d\n",sum);
       sum=0;
    }
    system("pause");
    return 0;
}

