#include<stdio.h>
__int64 count( int n)
{
	__int64 sum=0;
	if(n==1)return 2;
	else
	{
		sum+=3*count(n-1);
		sum+=2;
		return sum;
	}
}
//3µÄ´Î·½-1

int main()
{
	int n;
	__int64 m=0;
   while(scanf("%d",&n)!=EOF)
   {
	   m=count(n);
	   printf("%I64d\n",m);
   }
   return 0;
}





