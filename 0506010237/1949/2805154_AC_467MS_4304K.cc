#include<iostream>
using namespace std;
typedef struct
{
    int c[100];
    int k;
    int v; 
    bool visit;      
}node;
node num[10000];
int sum=0;
int getresult(int x)
{
      if(num[x].visit==0)
      {
          int maxs=0;
          for(int j=0;j<num[x].k;j++)
          {
            int h=getresult(num[x].c[j]);
            if(h>maxs)
              maxs=h;
          }       
          num[x].v=maxs+num[x].v;
          num[x].visit=1;
      }
      return num[x].v;
}
int main()
{
    int n,v,k,maxs;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
       scanf("%d %d",&num[i].v,&num[i].k);
       num[i].visit=0;
       for(int j=0;j<num[i].k;j++)
       {
           scanf("%d",&num[i].c[j]);
           num[i].c[j]--;
       }      
    }
    num[0].visit=1;
    for(int i=0;i<n;i++)
    {
        int maxs=0;
        for(int j=0;j<num[i].k;j++)
        {
            int h=getresult(num[i].c[j]);
            if(h>maxs)
              maxs=h;
        }
        num[i].v=maxs+num[i].v;
        num[i].visit=1;
        if(num[i].v>sum)
          sum=num[i].v;            
    }
    printf("%d\n",sum);
    system("pause");
    return 0;
}
