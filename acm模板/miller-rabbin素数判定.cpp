#include<cstdio>
#include<time.h>
#include<stdlib.h>
unsigned int unsigned int ans;
void power(unsigned int unsigned int a,unsigned int unsigned int b,unsigned int unsigned int n) //快速求幂
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
bool miller_rabbin(unsigned int unsigned int n)//核心Miller rabin
{
	unsigned int unsigned int a;
	a=rand()%(n-1)+1;
	power(a,n-1,n);
	if(ans%n!=1) return false;
	else return true;
}
int main()
{
	unsigned int unsigned int n;
	while(scanf("%lld",&n)!=EOF)
	{
		bool flag=true;
		int t=3;
		if(n<=1) flag=false;
		else if(n==2||n==3) flag=true;
		else if(n%6==0||n%6==2||n%6==3||n%6==4) flag=false;
		else 
		{
			while(t--&&flag)
			    if(!miller_rabbin(n)) 
					flag=false;
		}
		if(flag) printf("YES\n");
		else printf("NO\n");
	}
}