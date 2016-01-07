#include<iostream>
using namespace std;
typedef struct
{
     int v;
     int left;
     int right;
     bool visit;       
}node;
int n,best=100000000;
void f(node mg[100],int sum,int k)
{
     if(sum>=best)
        return;
     if(k==n-2)
     {
         if(sum<best)
           best=sum;
           return;          
     }
     for(int i=1;i<n-1;i++)
     {
          if(mg[i].visit==false)
          {
               mg[i].visit=true;
               mg[mg[i].left].right=mg[i].right;
               mg[mg[i].right].left=mg[i].left;
               f(mg,sum+mg[i].v*mg[mg[i].left].v*mg[mg[i].right].v,k+1);
               mg[i].visit=false;
               mg[mg[i].left].right=i;
               mg[mg[i].right].left=i;                      
          }        
     }
}
int main()
{
    scanf("%d",&n);
    node mg[n];
    scanf("%d",&mg[0].v);
    for(int i=1;i<n;i++)
    {
         scanf("%d",&mg[i].v);
         mg[i].left=i-1;
         mg[i-1].right=i;    
         mg[i].visit=false;    
    }
    f(mg,0,0);
    printf("%d\n",best);
    system("pause");
    return 0;
}
