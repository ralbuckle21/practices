#include<iostream>
#include<cmath>
using namespace std;
#define INF INT_MAX;
struct point 
{
    double x;
    double y;
};
point p[8];
double mul(point p1,point p2)
{
	return p1.x*p2.y-p2.x*p1.y;//2x2矩阵算法
}
double area(point p[],int s,int e)
{
	double sum=0.0;
	int i;
	for(i=s;i<e-1;i++)
		sum+=mul(p[i],p[i+1]);
	sum=0.5*(sum+mul(p[i],p[s]));//面积的求法就是一圈2x2矩阵加起来然后除以2，注意最后一条边也要加上
	return sum;
}
int main()
{
	int count=0;
	while(1){
		count++;
		for(int i=0;i<4;i++)
			scanf("%lf %lf",&p[2*i].x,&p[2*i].y);
		for(int i=0;i<3;i++){//存储中点
			p[2*i+1].x=(p[2*i].x+p[2*i+2].x)/2;
			p[2*i+1].y=(p[2*i].y+p[2*i+2].y)/2;
		}
		p[7].x=(p[0].x+p[6].x)/2;
		p[7].y=(p[0].y+p[6].y)/2;
		double sum=area(p,0,8);
		if(sum==0) break;
		double mm=INF;//存储当前和中值的最小差
		double tmm=INF;
		double temp;//存储当前处理的图形面积
		for(int i=0;i<4;i++){
			for(int j=2;j<7;j++){
				temp=area(p,i,(i+j)%9);
				mm=fabs(2*temp-sum);
				if(tmm==0){
					j=7;
					i=4;
				}
				if(mm<tmm) tmm=mm;
			}
		}
		printf("Cake %d: %.3lf %.3lf\n",count,(sum-tmm)/2,(sum+tmm)/2);
	}
}