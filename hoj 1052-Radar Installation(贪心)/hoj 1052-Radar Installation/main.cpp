#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
#define maxn 1005
void find_point(double *xl,double *xr,int *x,int *y,int n,int d)//存储每个岛允许的雷达站x轴位置区间
{
	for(int i=0;i<n;i++){
		xl[i]=x[i]-sqrt(double(d*d-y[i]*y[i]));
		xr[i]=x[i]+sqrt(double(d*d-y[i]*y[i]));
	}
}
bool cmp(double a,double b)
{
	return a<b;
}
int main()
{
	int n,d,num=1;
	while(cin>>n>>d)
	{
		int count=1;
		if(n==0&&d==0) break;
		/*int *x=new int[n];
		int *y=new int[n];*/
		int x[maxn],y[maxn];
		bool flag=false;
		for(int i=0;i<n;i++){
			cin>>x[i]>>y[i];
			if((y[i]>d)||(y[i]<-d)){
				flag=true;
			}
		}
		if(flag)
			cout<<"Case "<<num<<": -1\n";
		else{
		double xl[maxn],xr[maxn];
		find_point(xl,xr,x,y,n,d);
		double ttemp;  
        for(int i=0;i<num-1;i++)  
            for(int j=0;j<num-i-1;j++)  //将点从左到右排序
                if(x[j]>x[j+1])  
                {  
                    ttemp=x[j];  
                    x[j]=x[j+1];  
                    x[j+1]=ttemp;  
                    ttemp=y[j];  
                    y[j]=y[j+1];  
                    y[j+1]=ttemp;  
                }  
		double temp=xr[0];
		for(int i=1;i<n;i++){
			if(xl[i]>temp){//需要新的雷达站
				count++;
				temp=xr[i];
			}
			if(xr[i]<temp)
				temp=xr[i];
		}
		printf("Case %d: %d\n",num,count);
		}
		num++;
	}
}


