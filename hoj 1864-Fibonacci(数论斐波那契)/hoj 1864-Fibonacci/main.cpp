#include<iostream>
using namespace std;
int dig(long long a)
{
	int y=0;
	for(int i=0;a!=0;++i){
		a=a/10;
		y=i+1;
    }
	return y;
}
long long fib(long long a,long long b, long long n)
{
 if(n == 1)
  return a;
 else if (n == 2)
  return b;
 else
  return fib(a, b, n-1)+fib(a, b, n-2);
}
int main()
{
	int cas,temp;
	scanf("%d",&cas);
	while(cas--)
	{
		scanf("%d",&temp);
		printf("%d\n",dig(fib(1,1,temp)));
	}
}