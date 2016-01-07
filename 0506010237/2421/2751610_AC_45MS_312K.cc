#include<iostream>
#define MAX 100000;
using namespace std;
int cost[100][100];
int n,c,sum=0;
void prim()
{
   int lowcost[100],min;
   int closeset[100],k;
   for(int i=0;i<n;i++)
   {
       lowcost[i]=cost[0][i];
       closeset[i]=0;        
   }  
   lowcost[0]=-1;  
   for(int i=1;i<n;i++)
   {
      min=MAX;
      for(int j=0;j<n;j++)
      {
          if(lowcost[j]!=-1 && lowcost[j]<min)
          {
              min=lowcost[j];
              k=j;                 
          }                
      }        
      sum=sum+min;
      lowcost[k]=-1;
      for(int j=0;j<n;j++)
      {
         if(cost[k][j]<lowcost[j])
         {
               lowcost[j]=cost[k][j];
               closeset[j]=k;                 
         }        
      }
   }
   printf("%d\n",sum);
}
int main()
{
   int i,j,start,stop;
   scanf("%d",&n);
   for(i=0;i<n;i++)
     for(j=0;j<n;j++)
         scanf("%d",&cost[i][j]);
   for(i=0;i<n;i++)
     cost[i][i]=MAX; 
   scanf("%d",&c);
   for(i=0;i<c;i++)
   {
         scanf("%d %d",&start,&stop);
         cost[start-1][stop-1]=0;
         cost[stop-1][start-1]=0;          
   }       
   prim();
   system("pause");
   return 0;
}

