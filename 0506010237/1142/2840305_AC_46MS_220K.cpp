#include<stdio.h>
#include <iostream>
#include<math.h>
using namespace std;
int c;
int num[300];
int k=0,sum=0;
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
     for(int i=3;i<=10000;i++)
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
int qiuhe(int b[],int n)
{  
    sum=0;
 for(int i=0;i<=n;i++)
  do
 {
  sum+=b[i]%10;
  b[i]=b[i]/10;
 }while(b[i]);

 return sum;
}
int qiuhe1(int b)
{ sum=0;
  do
 {
  sum+=b%10;
  b=b/10;
 }while(b);
 return sum;
}
int main()
{
    prime[0]=2;
    setprime();
    int n;
	scanf("%d",&n);
    while(n)
	{
	  while(n)
	{   k=0;
		n++;
	     for(int i=0;i<300;i++)
		   num[i]=0;
        fenjie(n);
		if(k==0)
			continue;
	    c=qiuhe(num,k);
	    if(c==qiuhe1(n))
	   {
	    cout<<n<<endl;
	     break;
	   }
       
	 }
	scanf("%d",&n);
	}
    return 0;
}
