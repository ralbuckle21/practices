#include<iostream>
using namespace std;
int main()
{
    int n,f,i,best=0,sum=0;
    scanf("%d %d",&n,&f);
    int num[n];
    for(i=0;i<f;i++)
    {
         scanf("%d",&num[i]);
         sum=num[i]+sum;                
    }
    best=sum;
    for(i=f;i<n;i++)
    {
         scanf("%d",&num[i]);
         sum=sum+num[i]-num[i-f];
         if(sum>best)
           best=sum;            
    }
    printf("%d\n",best*1000/f);
    system("pause");
    return 0;
}
