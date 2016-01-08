/*#include<cstdio>
#include<time.h>
#include<stdlib.h>
long long ans;
void power(long long a,long long b,long long n) //快速求幂
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
bool miller_rabbin(long long n)//核心Miller rabin
{
	long long a;
	a=rand()%(n-1)+1;
	power(a,n-1,n);
	if(ans%n!=1) return false;
	else return true;
}
int main()
{
	long long n;
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
}*/
#include <stdlib.h>
#include<iostream>
#ifdef WIN32
typedef __int64 i64;
#else
typedef long long i64;
#endif
int modular_exponent(int a,int b,int n){ //a^b mod n
	int ret;
	for (;b;b>>=1,a=(int)((i64)a)*a%n)
		if (b&1)
			ret=(int)((i64)ret)*a%n;
	return ret;
}
// Carmicheal number: 561,41041,825265,321197185
int miller_rabin(int n,int time=10){
	if (n==1||(n!=2&&!(n%2))||(n!=3&&!(n%3))||(n!=5&&!(n%5))||(n!=7&&!(n%7)))
		return 0;
	while (time--)
		if (modular_exponent(((rand()&0x7fff<<16)+rand()&0x7fff+rand()&0x7fff)%(n-1)+1,n-1,n)!=1)
			return 0;
	return 1;
}
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF){
		printf("%d\n",miller_rabin(n,10));
	}
}