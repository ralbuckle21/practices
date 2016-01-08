#include<cstdio>
#include<time.h>
#include<stdlib.h>
#include<cstring>
#define MAXN 1000500
unsigned int ans,st,ed;
unsigned int prime[MAXN];
void power(unsigned int a,unsigned int b,unsigned int n)
{
	if(b==1)
	{
		ans=a;
		return;
	}
	power(a,b/2,n);
	if(b%2==0)  ans=ans*ans%n;
    else  ans=(ans*ans%n)*a%n;
}
bool miller_rabbin(unsigned int n)
{
	unsigned int a;
	a=(rand()*rand()%10)%(n-1)+1;
	power(a,n-1,n);
	if(ans%n!=1) return false;
	else return true;
}
void table(unsigned int st,unsigned int ed)
{
	unsigned int n,maxdis=0,mindis=999999999;
	int max1=-1,max2=-1,min1=-1,min2=-1;
	memset(prime,0,sizeof(prime));
	unsigned int count=0;
	for(n=st;n<=ed;n++)
	{
		bool flag=true;
		unsigned int t=3;
		if(n<=1) flag=false;
		else if(n==2||n==3) flag=true;
		else if(n%6==0||n%6==2||n%6==3||n%6==4) flag=false;
		else 
		{
			while(t--&&flag)
			    if(!miller_rabbin(n)) 
					flag=false;
		}
		if(flag)
		{
			prime[count]=n;
			count++;
			if(count>1)
			{
				if((prime[count-1]-prime[count-2])>maxdis)
				{
					max1=prime[count-2];
					max2=prime[count-1];
					maxdis=prime[count-1]-prime[count-2];
				}
				if((prime[count-1]-prime[count-2])<mindis)
				{
					min1=prime[count-2];
					min2=prime[count-1];
					mindis=prime[count-1]-prime[count-2];
				}
			}
		}
	}
	if(max1!=-1) printf("%ld,%ld are closest, %ld,%ld are most distant.\n",min1,min2,max1,max2);			
	else printf("There are no adjacent primes.\n");
}
int main()
{
	while(scanf("%ld %ld",&st,&ed))
	{
		table(st,ed);
	}
}