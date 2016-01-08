#include<stdio.h>
int main()
{
	int i,n,m,k,j,signal;
	__int64 tol,sum,p;
	scanf("%d",&k);
	for(i=0;i<k;i++)
	{
		scanf("%d %d",&n,&m);
		tol=1;
		signal=1;
		p=0;
		sum=1;
		for(j=n;j<=n-m+1;j--)
			tol*=j;
		for(j=2;j<=m;j++)
		{
		  sum*=j;
		  p-=signal*tol/sum;
		  signal*=-1;
		}
	    printf("%I64d\n",p);
	}
	return 0;
}