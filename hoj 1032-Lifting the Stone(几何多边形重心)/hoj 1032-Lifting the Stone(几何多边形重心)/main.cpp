#include<iostream>
#include<cstdlib>
#include<cstring>
struct point{
	double x,y;
};
double area(point a,point b,point c)//�������������
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
			scanf("%lf%lf",&c.x,&c.y);//������ε�����ת��Ϊ����������ĺ�
			double temp=area(a,b,c);
			resa+=temp;
			resx+=(a.x+b.x+c.x)*temp;
			resy+=(a.y+b.y+c.y)*temp;
			b=c;//123�㴦����������134��
		}
		printf("%.2lf %.2lf\n",resx/resa/3,resy/resa/3);
	}
}