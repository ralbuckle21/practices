#include<iostream>
using namespace std;
#define MAX 512
#define MAXN 10086
#define MAXNUM 999999
int t,e,f;
//已知储蓄罐满时的质量f以及空时质量e,有n种硬币，每种硬币的价值为p，质量为w，求该储蓄罐中的最少有多少钱？罐子恰好放满
//完全背包问题，求最大的价值
int min(int a,int b)
{
	if(a<b) return a;
	else return b;
}
int main()
{
	cin>>t;
	while(t--)
	{
		int cnum;
		cin>>e>>f;
		cin>>cnum;
		int *p=new int[MAX];
		int *v=new int[MAX];
		int *dp=new int[MAXN];
		for(int i=0;i<cnum;i++)
			cin>>v[i]>>p[i];
		for(int i=0;i<=MAXN;i++)
			dp[i]=MAXNUM;
		dp[0]=0;
		for(int i=0;i<cnum;i++)//硬币种类
		{
			for(int j=p[i];j<=(f-e);j++)//质量
				dp[j]=min(dp[j],dp[j-p[i]]+v[i]);//每个状态=不放i硬币状态和当前状态中较小的一个
		}
		if(dp[f-e]==999999) cout<<"This is impossible."<<endl;
		else cout<<"The minimum amount of money in the piggy-bank is "<<dp[f-e]<<"."<<endl;
	}
}