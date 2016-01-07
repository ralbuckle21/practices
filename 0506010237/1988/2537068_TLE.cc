#include<iostream>
using namespace std;
struct
{
     int rank;
     int father;
     int son;   
}node[30000];
void init()
{
     for(int i=1;i<=30000;i++)
     {
          node[i].father=i;
          node[i].son=i;
          node[i].rank=1;        
     }
}
int father(int x)
{
    while(x!=node[x].father)
       x=node[x].father;                           
    return x;
}
int son(int x)
{ 
    while(x!=node[x].son)
       x=node[x].son;                         
    return x;
}
void mov(int a,int b)
{
     int m=father(b);
     int n=son(a);
     node[m].father=n;
     node[n].son=m;
     while(n!=node[n].father)
     {
         node[n].rank=node[m].rank+node[n].rank;
         n=node[n].father;               
     }
     node[n].rank=node[m].rank+node[n].rank;
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