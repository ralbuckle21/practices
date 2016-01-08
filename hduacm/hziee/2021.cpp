#include<stdio.h>
int main()
{
	int n,i,sum,m;
    while(scanf("%d",&n),n)
	{
		for(sum=0,i=0;i<n;i++)
		{
			scanf("%d",&m);
			sum+=m/100;
			m%=100;
			sum+=m/50;
			m%=50;
			sum+=m/10;
			m%=10;
			sum+=m/5;
			m%=5;
			sum+=m/2;
			m%=2;
			sum+=m;
		}
		printf("%d\n",sum);
	}
	return 0;
}

		
