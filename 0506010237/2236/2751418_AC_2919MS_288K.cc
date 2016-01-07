#include<iostream>
using namespace std;
typedef struct
{
    int x;
    int y;
    int father;
    int sign;       
}node;
node mg[1001];
int n,d;
void init()
{
     int i;
     for(i=0;i<n;i++)
     {
       mg[i].father=i;
       mg[i].sign=0;
     }                
}
int find(int x)
{
     while(mg[x].father!=x)
        x=mg[x].father;
     return x;  
}
void unions(int p)
{
      int i=0,h;
      for(i=0;i<n;i++)
      {
          if(mg[i].sign==1)
          {
              h=find(i);
              if(h!=p)
                if((mg[p].y-mg[i].y)*(mg[p].y-mg[i].y)+(mg[p].x-mg[i].x)*(mg[p].x-mg[i].x)<=d*d)
                    mg[h].father=p;                       
          }                          
      }  
}
int main()
{
    int i,p,q;
    char c;
    scanf("%d %d",&n,&d);
    init();
    for(i=0;i<n;i++)
      scanf("%d %d",&mg[i].x,&mg[i].y);
    while(scanf("%c",&c)!=EOF)
    {
          if(c=='O')
          {
              scanf("%d",&p); 
              unions(p-1);
              mg[p-1].sign=1;          
          }
          else if(c=='S')
          {
              scanf("%d %d",&p,&q);
              if(find(p-1)==find(q-1))
                  printf("SUCCESS\n");
              else
                  printf("FAIL\n");    
          }                           
    } 
    system("pause");
    return 0;
}
