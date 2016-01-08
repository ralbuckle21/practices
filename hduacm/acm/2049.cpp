#include<stdio.h>
int main()
{
	int n,i,j,m,k;
	__int64 d[21],sum,tol;
	d[1]=0;
	d[2]=1;
	for(i=3;i<=21;i++)
		d[i]=(i-1)*(d[i-1]+d[i-2]);
    scanf("%d",&k);
	for(i=0;i<k;i++)
	{
		scanf("%d %d",&n,&m);
		tol=n;
		sum=m;
	    for(j=1;j<m;j++)
		{
			tol*=(n-j);
			sum*=j;
		}
		tol=(tol/sum)*d[m];
        printf("%I64d\n",tol);
	}
	return 0;
}