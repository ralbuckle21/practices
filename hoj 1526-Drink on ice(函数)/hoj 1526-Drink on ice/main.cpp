#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int MAX=1100;
const int INF=1000000001;
const double PI=acos(-1.0);
const double EPS=1.0e-8;
const int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int dblcmp(double x)
{
    if(fabs(x)<EPS)return 0;
    return x<0?-1:1;
}
int main()
{
    double mw,mi,tw,ti;
    while(scanf("%lf%lf%lf%lf",&mw,&mi,&tw,&ti)!=EOF)
    {
        if(dblcmp(mw)==0&&dblcmp(mi)==0
            &&dblcmp(tw)==0&&dblcmp(ti)==0)
            break;
        double em=335+30*2.09;
        double totang=mi*(ti+30)*2.09+mw*(em+tw*4.19);
  
        double totm=mw+mi;
  
        if(dblcmp(totang/(2.09*totm)-30)<0)
        {
            printf("%.1f g of ice and 0.0 g of water at %.1f C\n"
                ,totm,totang/(2.09*totm)-30);
        }
        else if(dblcmp(totang/totm-em)>0)
        {
            printf("0.0 g of ice and %.1f g of water at %.1f C\n"
                ,totm,(totang/totm-em)/4.19);
        }
        else
        {
            double a,b,c,d,e,f;
            a=1;
            b=1;
            c=totm;
            d=30*2.09;
            e=em;
            f=totang;
  
            double det=a*e-b*d;
            double detx=c*e-b*f;
            double dety=a*f-c*d;
  
            printf("%.1f g of ice and %.1f g of water at 0.0 C\n",
                fabs(detx/det),fabs(dety/det));
  
        }
  
    }
      
    return 0;
}