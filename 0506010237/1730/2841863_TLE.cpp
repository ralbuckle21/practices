#include<iostream>
#include<math.h>
using namespace std;
int num[100];
int k=0;
int prime[100000],x=1;
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
     for(int i=3;i<=63000;i++)
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
}
int main()
{
    prime[0]=2;
    setprime();
    int n;
    while(true)
    {
       scanf("%d",&n);
       fenjie(n);
       int i=1,c=1,max=100;
       while(i<=k)
       {
           if(num[i]==num[i-1])
              c++;
           else
           {
                if(c<max)
                  max=c;
                c=1;       
           }      
           i++; 
       }
       if(c<max)
           max=c;
       printf("%d\n",max);
       k=0;
    }
    system("pause");
    return 0;
}
