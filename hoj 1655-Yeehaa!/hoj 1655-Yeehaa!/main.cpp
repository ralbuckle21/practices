#include<iostream>
#include <cmath>
#include <algorithm>
using namespace std;
#define PI 3.1415926536
int main()
{
	int count;
	scanf("%d",&count);
	for(int i=1;i<=count;i++){
		double R,n,ang,a,b;
		scanf("%lf %lf",&R,&n);
		ang=PI/n;//每个圆的角度
		a=R*sin(ang);
		b=1+sin(ang);
		printf("Scenario #%d:\n%.3f\n\n",i,a/b);
	}
}
