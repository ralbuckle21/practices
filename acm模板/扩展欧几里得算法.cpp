#include <iostream>
using namespace std;
int x,y,q;
int exgcd(int a,int b,int &x,int &y)
{
	if(b==0) {x=1;y=0;return a;}
	int r=exgcd(b,a%b,y,x);
	y-=x*(a/b);
	return r;
}
int main()
{
	int a,b;
	cin>>a>>b;
	if(a<b)
		swap(a,b);
	int c=exgcd(a,b,x,y);
	cout<<c;
}
//求ax=b (mod m) ax+my=b 如果r=gcd(a,m)且b%r==0,则同余方程有解,其最小解为x*(b/r);
//ax+by=c 如r=gcd(a,b),则存在x,y,使xa+yb=r;当x+=b,y-=a后仍然成立 