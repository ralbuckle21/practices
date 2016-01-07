#include<iostream>
#include<stdio.h>
using namespace std;
typedef struct 
{
      int c,y;  
}node;
int main()
{
    int n,s,i;
    unsigned int com;
    scanf("%d %d",&n,&s);
    node cost[n];
    scanf("%d %d",&cost[0].c,&cost[0].y);
    com=cost[0].c*cost[0].y;
    for(i=1;i<n;i++)
    {
        scanf("%d %d",&cost[i].c,&cost[i].y);
        if(cost[i].c>cost[i-1].c+s)
         cost[i].c=cost[i-1].c+s;
        com=com+cost[i].c*cost[i].y;        
    }
    cout<<com<<endl;
    system("pause");
    return 0;
}
