#include<stdio.h>
#include<math.h>

int main()
{
	double p=sqrt(3);
	int n;
	__int64 resut;
	while(scanf("%d",&n)!=EOF)
	{
     resut=(__int64)(((2+p)*pow(1+p,n)-(2-p)*pow(1-p,n))/(2*p));
     printf("%I64d\n",resut);
	}
	return 0;
}




