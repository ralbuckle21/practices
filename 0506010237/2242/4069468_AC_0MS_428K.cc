#include<iostream>
#include<math.h>
const double pi=3.141592653589793;
using namespace std;
struct point{
    double x,y;   
}p[3];
double a,b,c;
double mul(point u1,point u2,point u0){
    double d=(u1.x-u0.x)*(u2.y-u0.y)-(u1.y-u0.y)*(u2.x-u0.x);
    if(d<0) d=-d;
    return d;   
}
double dist2(point u,point v){
    return (u.x-v.x)*(u.x-v.x)+(u.y-v.y)*(u.y-v.y);          
}
int main(){
    while(scanf("%lf%lf",&p[0].x,&p[0].y)!=EOF){
          scanf("%lf%lf%lf%lf",&p[1].x,&p[1].y,&p[2].x,&p[2].y);
          a=dist2(p[2],p[1]); b=dist2(p[0],p[1]); c=dist2(p[0],p[2]);
          double l=pi*sqrt(a*b*c)/(mul(p[1],p[2],p[0]));
          printf("%.2lf\n",l);                                            
    }
    system("pause");
    return 0;
}
