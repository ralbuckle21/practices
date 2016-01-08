#include<stdio.h>
int main()
{
	int i,j,t,m,s,n;
	int a[100];
	while(scanf("%d",&n)!=EOF && n)
	{
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(i=0;i<n-1;i++)
			for(j=0;j<n-1-i;j++)
			{   
				t=a[j]<0 ? -a[j] : a[j];
				s=a[j+1]<0 ? -a[j+1] : a[j+1];
				if(s>t)
				{
					m=a[j+1];
					a[j+1]=a[j];
					a[j]=m;
				}
			}
		for(i=0;i<n;i++)
		{
			printf("%d",a[i]);
			if(i<n-1)printf(" ");
		}
		printf("\n");
	}
    return 0;
}
		


		


