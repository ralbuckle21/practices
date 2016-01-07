#include<iostream>
#include<stdio.h>
using namespace std;
typedef struct 
{
      int c,y;  
}node;
int com[20];
void add1(int k)
{
    int i=0;
    int c=k;
    while(i<20)
    {
          com[i]=com[i]+c;
          c=com[i]/10;
          com[i]=com[i]%10;   
          i++;
          if(c==0)
               break;      
    }    
}
int main()
{
    int n,s,i;
    for(int f=0;f<20;f++)
        com[f]=0; 
    scanf("%d %d",&n,&s);
    node cost[10002];
    scanf("%d %d",&cost[0].c,&cost[0].y);
    add1(cost[0].c*cost[0].y);
    for(i=1;i<n;i++)
    {
        scanf("%d %d",&cost[i].c,&cost[i].y);
        if(cost[i].c>cost[i-1].c+s)
         cost[i].c=cost[i-1].c+s;
         add1(cost[i].c*cost[i].y);   
    }
    i=19;
    while(com[i]==0)
      i--;
    for(;i>=0;i--)
       cout<<com[i];
     cout<<endl;
    system("pause");
    return 0;
}
