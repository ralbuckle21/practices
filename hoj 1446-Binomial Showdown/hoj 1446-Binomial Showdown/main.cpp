#include<iostream>
using namespace std;
double comb(int n,int k)//��double���־���
{
	double ans = 1;
	for(int i=1;i<=k;i++)
	{
		ans*=(double)(n-i+1)/(double)i;
	}
	return ans;
}
int main()
{
	int n,m;
	while(scanf("%d %d",&n,&m)&&n){
		m=m<(n-m)?m:(n-m);
		printf("%.0f\n",comb(n,m));//�ܾ�����С��
	}
}