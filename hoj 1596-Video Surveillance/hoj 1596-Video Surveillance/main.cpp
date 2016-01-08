#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
#define N 155
#define PR 1e-8
struct TPoint
{
    double x,y;
}s;
struct TPolygon
{//完整保存一组输入
    int n;
    TPoint p[N];
}ply,ans;
double maxdist;
int dblcmp(double a)
{
    if(fabs(a)<PR) return 0;
    return a>0?1:-1;
}
double MAX(double a,double b) {return a>b?a:b;}
double multi(TPoint a,TPoint b,TPoint c)//叉积
{
    double s1=b.x-a.x;
    double t1=b.y-a.y;
    double s2=c.x-a.x;
    double t2=c.y-a.y;
    return s1*t2-s2*t1;
}
double plyarea(TPolygon res)//面积
{
    int i;
    double area=0;
    res.p[res.n]=res.p[0];
    for(i=0;i<res.n;i++)
        area+=multi(s,res.p[i],res.p[i+1]);
    return area;
}
TPolygon cut(TPolygon res,TPoint s,TPoint e)//半平面交
{
    int d1,d2,i,t;
    double s1,s2;
    TPoint a;
    TPolygon b;
    b.n=0;
    res.p[res.n]=res.p[0];
    for(i=0,t=0;i<res.n;i++)
    {
        d1=dblcmp(s1=multi(res.p[i],s,e));//跨立
        d2=dblcmp(s2=multi(res.p[i+1],s,e));//跨立
        if(d1>=0) b.p[t++]=res.p[i];
        if(d1*d2<0)
        {
            a.x=(s2*res.p[i].x-s1*res.p[i+1].x)/(s2-s1);
            a.y=(s2*res.p[i].y-s1*res.p[i+1].y)/(s2-s1);
            b.p[t++]=a;
        }
    }
    b.n=t;
    return b;
}
int main()
{
    int end=1;
    while(scanf("%d",&ply.n),ply.n)
    {
        int i,j;
        for(i=0;i<ply.n;i++) scanf("%lf%lf",&ply.p[i].x,&ply.p[i].y);
        s.x=0; s.y=0;
        if((dblcmp(plyarea(ply)))<0) reverse(ply.p,ply.p+ply.n);//翻转
        ply.p[ply.n]=ply.p[0];
        ans=ply;
        for(i=0;i<ply.n;i++)//半交
            ans=cut(ans,ply.p[i],ply.p[i+1]);
        printf("Floor #%d\n",end++);
        if(ans.n) printf("Surveillance is possible.\n\n");
        else printf("Surveillance is impossible.\n\n");
    }
}