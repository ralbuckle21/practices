#include<iostream>
using namespace std;
typedef struct 
{
	int x,y;
}pointt;
int mul(pointt p1,pointt p2,pointt p0)
{
   return((p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y));
}
int main()
{
    int n,total=2,c;
    while(true)
    {
        scanf("%d",&n);
        if(n==0)
          break;
        pointt mg[n];
        for(int i=0;i<n;i++)
         scanf("%d %d",&mg[i].x,&mg[i].y); 
        for(int i=0;i<n;i++)
        {
          for(int j=i+1;j<n;j++)
          {
               c=2;
               if((n-j)<total)
                  continue;
               for(int k=j+1;k<n;k++)
               {
                  if((c+n-k)<=total)
                    break; 
                  if(mul(mg[k],mg[j],mg[i])==0)
                     c++;
               }
               if(c>total)
                  total=c;   
          }
        }          
        printf("%d\n",total);
        total=2;
    }
    system("pause");
    return 0;
}
