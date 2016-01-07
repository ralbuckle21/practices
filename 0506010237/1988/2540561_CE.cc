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
     while(b!=node[b].father && a!=node[a].son)
     {
          b=node[b].father;
          a=node[a].son; 
     }
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
    int x,y;
    for(int i=1;i<=p;i++)
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
    system("pause");
    return 0;
}
