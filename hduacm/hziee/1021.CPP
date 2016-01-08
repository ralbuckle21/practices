#include<stdio.h>

int main()
{
	__int64 n,i,a,b,c;
	while(scanf("%I64d",&n)!=EOF)
	{
		a=7;
		b=11;
		if(n<2)
			printf("no\n");
		else
		{
			for(i=2;i<n;i++)
			{
			  c=a+b;
			  a=b;
			  b=c;
			}
		    if(c%3)printf("%I64d\n",c);
		    else printf("%I64d\n",c);
		}
	}
	return 0;
}

