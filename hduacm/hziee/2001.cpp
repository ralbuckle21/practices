#include<stdio.h>
#include<math.h>
int main()
{
	float a,b,c,d;
    while(scanf("%f %f %f %f",&a,&b,&c,&d)!=EOF)
	  printf("%.2f\n",sqrt((a-c)*(a-c)+(b-d)*(b-d)));
 return 0;
}
