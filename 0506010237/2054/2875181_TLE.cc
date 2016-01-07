#include<iostream>
using namespace std;
typedef struct
{
    bool visit;
    int parent;
    int cost;       
}node;
int n,start,best=10000000;
void f(node mg[1000],int sum,int t)
{
     if(sum>=best)
        return;
     if(t==n+1)
     {
        if(sum<best)
          best=sum;
        return;          
     }
     for(int i=0;i<n;i++)
     {
          if(mg[mg[i].parent].visit==true && mg[i].visit==false)
          {
                
                mg[i].visit=true;
                f(mg,sum+t*mg[i].cost,t+1);
                mg[i].visit=false;                 
          } 
     }        
}
int main()
{
     int a,b,i;
     while(true)
     {
        scanf("%d %d",&n,&start);
        if(n==0)
          break;
        node mg[n];
        for(i=0;i<n;i++)
        {
            scanf("%d",&mg[i].cost);  
            mg[i].visit=false;
            mg[i].parent=i;     
        }
        mg[start-1].visit=true;
        for(i=1;i<n;i++)
        {
            scanf("%d %d",&a,&b);
            mg[b-1].parent=a-1;    
        } 
        f(mg,mg[start-1].cost,2);
        printf("%d\n",best);  
        best=10000000;       
     }
    system("pause");
    return 0;
}
