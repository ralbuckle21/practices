#include<stdio.h>
int main()
{
	int a[100],i,sum;
	while(scanf("%d",&a[0])!=EOF)
	{
		for(i=1;i<=a[0];i++)
			scanf("%d",&a[i]);
		for(i=1,sum=1;i<=a[0];i++)
			if(a[i]%2)sum*=a[i];
			printf("%d\n",sum);
	}
}
