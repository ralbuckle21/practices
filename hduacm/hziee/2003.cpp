#include<stdio.h>
int main()
{
    double n,m;
	while(scanf("%lf",&n)!=EOF)
	{
        m= n>=0 ? n : -n;
		printf("%.2f\n",m);
	}
	return 0;
}