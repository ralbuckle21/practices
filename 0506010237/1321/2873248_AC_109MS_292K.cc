#include<iostream>
#include<math.h>
using namespace std;
int sum=0;
int n,k;
int x[8];
char mg[8][8];
bool place(int f)
{
   for(int j=0;j<f;j++)
     if(x[j]==x[f])
           return false;
     return true;         
}
void backtrack(int t,int count)
{
    if(count==k)
    {
      sum++;
      return;
    }
    if(t>=n)
      return;
    for(int i=0;i<n;i++)
    {
             x[t]=i;
             if(mg[t][i]=='#' && place(t))
               backtrack(t+1,count+1);;     
    }
    x[t]=-1;
    backtrack(t+1,count); 
}
int main()
{
    while(true)
    {
       scanf("%d %d",&n,&k);
       if(n==-1 && k==-1)
         break;
       for(int i=0;i<n;i++)
          scanf("%s",mg[i]);
       backtrack(0,0);
       printf("%d\n",sum);
       sum=0;
    }
    system("pause");
    return 0;
}

