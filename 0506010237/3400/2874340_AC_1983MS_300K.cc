#include<iostream>
#include<iomanip>
using namespace std;
typedef struct
{
    int v;
    int w;
    int sign;    
}node;
int n,d,best=0;
void f(node mg[10],int wa,int wb,int s,int r,int ab,int x)
{
    /*if(s+r<=best)
      return;*/
    if(x==n)
    {
        if(s>best)        
          best=s;
        return;
    }
    if(ab==1)
    {
        for(int i=0;i<n;i++)
            if(mg[i].sign==0)
            {
                mg[i].sign=1;
                if(mg[i].w+wa>wb+d)
                  f(mg,mg[i].w+wa,wb,s,r-mg[i].v,ab+1,x+1);
                else
                   f(mg,mg[i].w+wa,wb,s,r-mg[i].v,ab,x+1);   
                mg[i].sign=0;               
            }        
    }    
    else
    {
          for(int i=0;i<n;i++)
            if(mg[i].sign==0)
            {
                mg[i].sign=2;
                if(mg[i].w+wb>wa+d)
                  f(mg,wa,wb+mg[i].w,s+mg[i].v,r-mg[i].v,1,x+1);  
                else
                  f(mg,wa,wb+mg[i].w,s+mg[i].v,r-mg[i].v,ab,x+1);   
                mg[i].sign=0;               
            }    
    }
}
int main()
{
    scanf("%d %d",&n,&d);
    node mg[n];
    int sum=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&mg[i].w,&mg[i].v); 
        mg[i].sign=0;     
        sum=sum+mg[i].v;
    }
    f(mg,0,0,0,sum,1,0);
    printf("%d\n",best);
    system("pause");
    return 0;
}


