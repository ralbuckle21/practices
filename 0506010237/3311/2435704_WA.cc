#include<iostream>
using namespace std;
int totalcount=1000000;
void shortt(int v,int cost[11][11],int n)
{
     int u;
     bool s[11];
     int dist[11];
     for(int i=0;i<n;i++)
     {
        s[i]=0;
        dist[i]=cost[v][i];       
     }    
     s[v]=1;
     for(int i=1;i<n;i++)
     {
        int min=100000;
        for(int j=0;j<n;j++)
        { 
            if(s[j]==0 && j!=v && dist[j]<min)
            {   
               min=dist[j];
               u=j;     
            }
        }
        s[u]=1;
        for(int w=0;w<n;w++)
        {
            if(s[w]==0 && dist[w]>dist[u]+cost[u][w])
              dist[w]=dist[u]+cost[u][w];        
        }
     }
     for(int w=0;w<n;w++)
     {
           cost[v][w]=dist[w];
     }
}
void swap(char c[],int i,int k)
{
    char temp;
    temp=c[i];
    c[i]=c[k];
    c[k]=temp;
}
void perm(int cost[11][11],char c[],int k,int m)
{
   if(k==m)
    {
        int total=0;
        for(int i=1;i<=m;i++)
        {
            total=cost[int(c[i])-1][int(c[i])]+total;        
        }
        total=cost[m][0]+total;
        if(total<totalcount)
           totalcount=total;
    }
   else
   {
      for(int i=k;i<=m;i++)
      {
         swap(c,k,i);
         perm(cost,c,k+1,m);
         swap(c,k,i);
      }
   }
}
void path(int cost[11][11],int n)
{
     char c[11];
     for(int i=0;i<n;i++)
     {
        shortt(i,cost,n);
        c[i]=char(i);
     }
     perm(cost,c,1,n-1);
     cout<<totalcount<<endl<<endl;
}
int main()
{
       int n;
       int cost[11][11];
       cin>>n;
       while(n)
       {
       n=n+1;
       for(int i=0;i<n;i++)
          for(int j=0;j<n;j++)
          {
             cin>>cost[i][j];        
          }
       path(cost,n);
       cin>>n;
      }    
       system("pause");
       return 0;
}