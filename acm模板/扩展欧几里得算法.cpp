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
//��ax=b (mod m) ax+my=b ���r=gcd(a,m)��b%r==0,��ͬ�෽���н�,����С��Ϊx*(b/r);
//ax+by=c ��r=gcd(a,b),�����x,y,ʹxa+yb=r;��x+=b,y-=a����Ȼ���� 