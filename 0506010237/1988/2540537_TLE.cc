#include<iostream>
using namespace std;
struct
{
       int sum;
       int counts;
       int com[160]; //以空间换时间 
       int father;
       int lev;
}node[30001];
void init()
{
     for(int i=1;i<=30000;i++)
     {     
          node[i].counts=0;
          node[i].sum=1;
          node[i].father=i;
     }
}
void mov(int a,int b)//b for a child
{
     while(b!=node[b].father)
       b=node[b].father;
     node[a].counts++;
     node[a].com[node[a].counts]=b;
     node[b].father=a;
     node[b].lev=node[a].counts;
     while(a!=node[a].father)
     {
         node[a].sum=node[a].sum+node[b].sum;
         a=node[a].father;
     }
     node[a].sum=node[a].sum+node[b].sum;
}
int find(int x)
{
     int c=node[x].sum;
     while(node[x].father!=x)
     {
          int lev=node[x].lev;
          x=node[x].father;
          for(int i=lev+1;i<=node[x].counts;i++)
              c=node[node[x].com[i]].sum+c;
     }
     return c;
}
int main()
{
    int p,x,y;
    cin>>p;
    init();
    while(p--)
    {
         char c;
         cin>>c;  
         switch(c)
          {
               case 'M':             
                   cin>>x;
                   cin>>y;
                   mov(x,y);           
                   break;
               case 'C':
                   cin>>x;
                   cout<<find(x)-1<<endl;        
                   break;
          }
    
    }
    return 0;
}
