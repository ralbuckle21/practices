/*Radar Installation 贪心算法
	Assume the coasting is an infinite straight line. Land is in one side of coasting, sea in the other. Each small island is a point locating in the sea side. And any radar installation, locating on the coasting, can only cover d distance, so an island in the sea can be covered by a radius installation, if the distance between them is at most d. 
We use Cartesian coordinate system, defining the coasting is the x-axis. The sea side is above x-axis, and the land side below. Given the position of each island in the sea, and given the distance of the coverage of the radar installation, your task is to write a program to find the minimal number of radar installations to cover all the islands. Note that the position of an island is represented by its x-y coordinates.




""" 
Input

The input consists of several test cases. The first line of each case contains two integers n (1 n 1000) and d, where n is the number of islands in the sea and d is the distance of coverage of the radar installation. This is followed by n lines each containing two integers representing the coordinate of the position of each island. Then a blank line follows to separate the cases.

The input is terminated by a line containing pair of zeros.


Output

For each test case output one line consisting of the test case number followed by the minimal number of radar installations needed. "-1" installation means no solution for that case. 


Sample Input

3 2
1 2
-3 1
2 1

1 2
0 2

0 0

Sample Output

Case 1: 2
Case 2: 1

	*/
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


