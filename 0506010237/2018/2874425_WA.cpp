#include<iostream>
#include<stdio.h>
int main()
{
    int n,f,i,best=0,sum=0;
    scanf("%d %d",&n,&f);
    int num[1000000];
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
    float result=(best*1000)/(f);
    printf("%.0f\n",result);
    return 0;
}
