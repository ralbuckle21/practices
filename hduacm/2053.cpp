#include<stdio.h>
#include<math.h>
int main()
{
	int n,m;
	double p;
	while(scanf("%d",&n)!=EOF)
	{
		p=sqrt(n);
		m=(int)p;
		p==m ?printf("1\n") :printf("0\n");
	}
	return 0;
}


