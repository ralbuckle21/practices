#include<stdio.h>
#define PI 3.1415927
int main()
{
	double r;
	while(scanf("%lf",&r)!=EOF)
		printf("%.3f\n",r*r*r*4*PI/3);
	return 0;
}