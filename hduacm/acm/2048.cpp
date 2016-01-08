#include<stdio.h>
int main()
{
	int n,i,j,m,sum;
	double p,signal=1.0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&m);
		p=0;
		sum=1;
		signal=1;
	    for(j=2;j<=m;j++)
		{
		  sum*=j;
		  p+=signal/sum;
		  signal*=-1;
		}
	p*=100;
	printf("%.2f%c\n",p,'\%');
	}
	return 0;
}