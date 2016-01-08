#include<iostream>
#include<cmath>
using namespace std;
#define MINN 1e-6
struct point{
	double x;
	double y;
};
double area(point p1,point p2,point p3)//三个点计算三角形面积的算法
{
	double r=p2.x*p3.y-p1.x*p3.y-p2.x*p1.y-p3.x*p2.y+p1.x*p2.y+p3.x*p1.y;
	if(r<0) r=-r;
	return r;
}
bool same(double a,double b)
{
	if(a-b>MINN||b-a>MINN) return 0;
	return 1;
}
int main()
{
	point p1,p2,p3,p;
	while(scanf("%lf%lf%lf%lf%lf%lf",&p1.x,&p1.y,&p2.x,&p2.y,&p3.x,&p3.y)){
		if(p1.x==0&&p1.y==0&&p2.x==0&&p2.y==0&&p3.x==0&&p3.y==0) break;
		int res=0;
		for(int i=1;i<100;i++)
			for(int j=1;j<100;j++){
				p.x=i;
				p.y=j;
				double t1=area(p1,p2,p3);//原三角形面积
				double t2=area(p,p2,p3)+area(p1,p,p3)+area(p1,p2,p);//测试点和起重两条边组成的三角形面积之和
				if(same(t1,t2)) res++;
			}
		printf("%4d\n",res);
	}
}