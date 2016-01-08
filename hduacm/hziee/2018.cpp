#include<stdio.h>
int main()
{
	int n,i,j,a[55];
	while(scanf("%d",&n)!=EOF&&n)
	{
		for(i=0;i<3&&i<n;i++)
			a[i]=i+1;;
		for(j=0;i<n;i++,j++)
			a[i]=a[j]+a[j+2];
		printf("%d\n",a[n-1]);
	}
	return 0;
}
