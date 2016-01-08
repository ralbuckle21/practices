#include<iostream>
#include<cmath>
#include<cstdlib>
#include<cstring>
using namespace std;
double x[6010],y[6010];
double max(double a,double b)
{
	if(a>b) return a;
	else return b;
}
int main()
{
	int n;
	while(scanf("%d",&n)&&n!=0){
		memset(x,0.0,sizeof(x));
		memset(y,0.0,sizeof(y));
		double res=0.0;
		for(int i=1;i<=n;i++)
			scanf("%lf%lf",&x[i],&y[i]);
		for(int i=1;i<=n;i++)
			for(int j=i;j<=n;j++){
				res=max(res,sqrt(pow(abs(x[i]-x[j]),2)+pow(abs(y[i]-y[j]),2)));
			}
		printf("%.2f\n",res);
	}
}