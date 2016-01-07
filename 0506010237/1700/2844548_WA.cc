#include<iostream>
using namespace std;
int num[1000];
int cmp ( const void *a , const void *b )
{
     return *(int *)a - *(int *)b;
}
int main()
{
    int t,n,count,sum=0,i,j;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
          scanf("%d",&num[i]);
        int sum=0;
        while(n>=4)  
        {
           if(2*num[2]>=num[1]+num[n-1]) 
                 sum=2*num[1]+num[n-1]+num[n];                            
           else if(2*num[2]<num[1]+num[n-1])  
                 sum=sum+2*num[2]+num[1]+num[n]; 
           n=n-2; 
      }
      if(n<=2)  
          sum=sum+num[n]; 
      else 
          sum=sum+num[2]+num[1]+num[3];
      printf("%d\n",sum);
    }
    system("pause");
    return 0;
}
