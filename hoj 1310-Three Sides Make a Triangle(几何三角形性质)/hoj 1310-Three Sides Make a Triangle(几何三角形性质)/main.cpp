#include<stdio.h>
#include<math.h>
struct point
{
	double x,y;
}a,c,b;
double dist(point p1,point p2)
{
	return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
double multi(point p1,point p2,point p0)//计算叉积，用于判断三点是否共线，共线则无法组成三角形
{
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
int main()
{
	double l1,l2,l3,a1,a2,a3;
	while(scanf("%lf %lf %lf %lf %lf %lf",&a.x,&a.y,&b.x,&b.y,&c.x,&c.y)==6)
	{ 
		if(fabs(multi(a,b,c))<1e-2)
		{
			printf("Not a Triangle\n");
			continue;
		}
		l1=dist(a,b);//三条边的长度
		l2=dist(a,c);
		l3=dist(b,c);
		if(fabs(l1-l2)<1e-2&&fabs(l1-l3)<1e-2)
		printf("Equilateral ");//判断等边等腰
		else
		{
			if(fabs(l1-l2)<1e-2||fabs(l1-l3)<1e-2||fabs(l2-l3)<1e-2)
			printf("Isosceles ");
			else printf("Scalene ");
		}
		a1=acos((l2*l2+l3*l3-l1*l1)/(2*l2*l3));//acos返回的是一个数值的反余弦弧度值。参数是余弦值
		a2=acos((l1*l1+l3*l3-l2*l2)/(2*l1*l3));//三角形某角弧度值的求法
		a3=acos((l1*l1+l2*l2-l3*l3)/(2*l2*l1));
		if(fabs(cos(a1))<1e-3||fabs(cos(a2))<1e-3||fabs(cos(a3))<1e-3)
		printf("Right\n");
		else
		{
			if(cos(a1)<0||cos(a2)<0||cos(a3)<0) printf("Obtuse\n");
			else printf("Acute\n");
		}
	}
	printf("End of Output\n");
}