#include<iostream>
using namespace std;
struct
{
     int rank;
     int father;
     int son;   
}node[30001];
void init()
{
     for(int i=1;i<=30000;i++)
     {
          node[i].father=i;
          node[i].son=i;
          node[i].rank=1;
     }
}
void mov(int a,int b)
{
     while(b!=node[b].father)
       b=node[b].father;
     while(a!=node[a].son)
       a=node[a].son; 
     node[b].father=a;
     node[a].son=b;
     while(a!=node[a].father)
     {
         node[a].rank=node[a].rank+node[b].rank;
         a=node[a].father;               
     }
     node[a].rank=node[b].rank+node[a].rank;
}
int main()
{
    int p;
    cin>>p;
    init();
    for(int i=1;i<=p;i++)
    {
         char c;
         cin>>c;
         if(c=='M')
         {
             int x,y;
             cin>>x;
             cin>>y;
             mov(x,y);          
         } 
         else if(c=='C')
         {
              int x;
              cin>>x;
              cout<<node[x].rank-1<<endl;     
         }       
    }
    return 0;
}
