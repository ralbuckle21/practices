#include<stdio.h>
#include<math.h>

int main()
{
	double p=sqrt(5);
	int n,i,minus,a,b;
	while(scanf("%d",&n)!=EOF)
		for(i=0;i<n;i++)
		{
			scanf("%d %d",&a,&b);
		    minus=b-a;
			printf("%.0lf\n",(pow(1+p,minus+1)-pow(1-p,minus+1))/(pow(2,minus+1)*p));
		}
	return 0;
}