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
double multi(point p1,point p2,point p0)//�������������ж������Ƿ��ߣ��������޷����������
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
		l1=dist(a,b);//�����ߵĳ���
		l2=dist(a,c);
		l3=dist(b,c);
		if(fabs(l1-l2)<1e-2&&fabs(l1-l3)<1e-2)
		printf("Equilateral ");//�жϵȱߵ���
		else
		{
			if(fabs(l1-l2)<1e-2||fabs(l1-l3)<1e-2||fabs(l2-l3)<1e-2)
			printf("Isosceles ");
			else printf("Scalene ");
		}
		a1=acos((l2*l2+l3*l3-l1*l1)/(2*l2*l3));//acos���ص���һ����ֵ�ķ����һ���ֵ������������ֵ
		a2=acos((l1*l1+l3*l3-l2*l2)/(2*l1*l3));//������ĳ�ǻ���ֵ����
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