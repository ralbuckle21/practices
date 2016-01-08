#include<stdio.h>
int main()
{
	int n, a[50], sum=0, i,avg=0;
	while(scanf("%d",&n),n)
	{
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		    avg+=a[i];
		}
		avg=avg/n;
		printf("%d",sum);
	}
	return 0;
}


