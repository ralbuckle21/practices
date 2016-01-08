/*#include <iostream>  
#include <cmath>  
using namespace std;  
double const eps = 1e-6;  
struct Point  
{
    double x,y;
    Point(double a=0, double b=0)  
    {
        x=a,y=b;  
    }
};
double dblcmp(double r)  
{  
    if(fabs(r)<eps) return 0;  
    return r>0?1:-1;  
}
Point operator + (Point a,Point b)  
{  
    return Point(a.x+b.x,a.y+b.y);  
}   
Point operator - (Point a, Point b)  
{  
    return Point(a.x-b.x,a.y-b.y);  
}  
Point operator * (Point a, double b)  
{  
    return Point(a.x*b,a.y*b);  
}
double dist(Point a, Point b)  
{  
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);  
} 
Point findCenter(Point a, Point b)  
{  
    Point c=b-a;  
    Point mid=(a+b)*0.5;  
    double x=dist(a,mid);  
    double y=sqrt(1-x);  
    Point center;  
    if(dblcmp(c.y)==0)  
    {  
        center.x=mid.x;  
        center.y=mid.y+y;  
    }
    else
    {
        double angle=atan(-c.x/c.y);  
        center.x=mid.x+y*cos(angle);  
        center.y=mid.y+y*sin(angle);  
    }
    return center;  
} 
int main()  
{  
    int n;  
    Point point[305],temp;  
    while(cin>>n,n)  
    {  
        for(int i=0;i<n;i++)  
        {  
            cin>>point[i].x>>point[i].y;  
        }  
        int maxPoint=1,count;  
        for(int i=0;i<n;i++)  
        {  
            for(int j=i+1;j<n;j++)  
            {  
                if(dblcmp(dist(point[i],point[j])-4.0)<= 0)  
                {  
                    count=0;  
                    temp=findCenter(point[i],point[j]);  
                    for(int k=0;k<n;k++)  
                    {  
                        if(dblcmp(dist(temp, point[k]) - 1.0) <= 0)  
                        {  
                            count++;  
                        }  
                    }
                    maxPoint = max(maxPoint, count);  
                }
            }
		}
        cout<<maxPoint<<endl;  
    }
}*/
//����������Ƚ�Ч��
#include<cstdio>
#include<cstdlib>
#include<cmath>
#define MINN 1e-6
struct point{
	double x,y;
};
point p[305];
double dist(point a,point b)  
{  
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);//Ѱ����������ƽ��
}
point find(point p1,point p2)//�󱻵�λԲ���ǵĻ����������
{
	point pt,mid,start;
	double d,a;
	pt.x=p2.x-p1.x;
	pt.y=p2.y-p1.y;
	mid.x=(p1.x+p2.x)/2;
	mid.y=(p1.y+p2.y)/2;
	d=sqrt(1-dist(p1,mid));//�����ҵ�һ��
	if(fabs(pt.y)<MINN){//�����ߴ�ֱ��x��
		start.x=mid.x;
		start.y=mid.y+d;
	}
	else{
		a=atan(-pt.x/pt.y);//�����ҵ�tan��
		start.x=mid.x+d*cos(a);
		start.y=mid.y+d*sin(a);
	}
	return start;
}
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF&&n!=0){
		int res=1,temp;
		point pt;
		for(int i=0;i<n;i++)
			scanf("%lf%lf",&p[i].x,&p[i].y);
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++){
				if(dist(p[i],p[j])>4) continue;//�����Բ���ཻ
				temp=0;//��λ���౻���Ǵ���
				pt=find(p[i],p[j]);//�ཻ�������
				for(int k=0;k<n;k++){//�������ڴ���Ļ��������㱻���ǵĴ���
					double tmp=dist(pt,p[k]);
					if(tmp<=1+MINN) temp++;
				}
				if(res<temp) res=temp;
			}
		printf("%d\n",res);
	}
}
