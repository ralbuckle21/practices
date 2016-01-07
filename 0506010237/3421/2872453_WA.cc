#include<iostream>
#include<math.h>
using namespace std;
int num[100],num1[50];
int k=0,t=0,k1=0;
long long int sum=0;
int prime[10000],x=1;
void isprime(int n)
{
     int i=0;
     while(i<x && prime[i]<=sqrt(n))
     {
         if(n%prime[i]==0)
           return;   
         i++;       
     }    
     prime[x++]=n;
}
void setprime()
{
     for(int i=3;i<=1050;i++)
        isprime(i);  
}
void fenjie(int n)
{
    int i=0; 
    while(true)
    {
         if(i==x || prime[i]==n)
           break;
         if(n%prime[i]==0)
         {
              n=n/prime[i];
              num[k++]=prime[i];     
         } 
         else
           i++;         
    }   
    num[k]=n;
    t=0;
    i=0;
    k1=0;
   while(i<=k)
    {
        while(i<=k && num[t]==num[i])
           i++;
        num1[k1++]=i-t;
        t=i;              
    }
}
long long int qiuc(int n)
{
    long long int x=1;
    for(int i=2;i<=n;i++)
          x=x*i;
    return x;
}
int main()
{
    int n;
    prime[0]=2;
    setprime();
    while(scanf("%d",&n)!=EOF)
    {
       fenjie(n);
       sum=qiuc(k+1);
       cout<<sum<<endl;
       for(int i=0;i<k1;i++)
         sum=sum/qiuc(num1[i]);
      cout<<k+1<<" "<<sum<<endl;
       sum=0;
       k=0;
    }  
    system("pause");
    return 0;
}