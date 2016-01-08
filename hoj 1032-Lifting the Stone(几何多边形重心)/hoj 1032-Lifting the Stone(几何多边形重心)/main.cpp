#include<iostream>
#include<cstdlib>
#include<cstring>
struct point{
	double x,y;
};
double area(point a,point b,point c)//计算三角形面积
{
	double res=a.x*b.y+b.x*c.y+c.x*a.y-b.x*a.y-c.x*b.y-a.x*c.y;
	return res;
}
int main()
{
	int cas,n;
	point a,b,c;
	scanf("%d",&cas);
	while(cas--){
		double resx=0,resy=0,resa=0;
		scanf("%d",&n);
		scanf("%lf%lf",&a.x,&a.y);
		scanf("%lf%lf",&b.x,&b.y);
		for(int i=2;i<n;i++){
			scanf("%lf%lf",&c.x,&c.y);//将多边形的问题转化为三角形问题的和
			double temp=area(a,b,c);
			resa+=temp;
			resx+=(a.x+b.x+c.x)*temp;
			resy+=(a.y+b.y+c.y)*temp;
			b=c;//123点处理后继续处理134点
		}
		printf("%.2lf %.2lf\n",resx/resa/3,resy/resa/3);
	}
}