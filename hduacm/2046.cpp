#include<stdio.h>
#include<math.h>

int main()
{
	double p=sqrt(5);
	int n;
	while(scanf("%d",&n)!=EOF)
	printf("%.0lf\n",(pow(1+p,n+1)-pow(1-p,n+1))/(pow(2,n+1)*p));
	return 0;
}
