#include<iostream>
using namespace std;
#define MAX 512
#define MAXN 10086
#define MAXNUM 999999
int t,e,f;
//��֪�������ʱ������f�Լ���ʱ����e,��n��Ӳ�ң�ÿ��Ӳ�ҵļ�ֵΪp������Ϊw����ô�����е������ж���Ǯ������ǡ�÷���
//��ȫ�������⣬�����ļ�ֵ
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
		for(int i=0;i<cnum;i++)//Ӳ������
		{
			for(int j=p[i];j<=(f-e);j++)//����
				dp[j]=min(dp[j],dp[j-p[i]]+v[i]);//ÿ��״̬=����iӲ��״̬�͵�ǰ״̬�н�С��һ��
		}
		if(dp[f-e]==999999) cout<<"This is impossible."<<endl;
		else cout<<"The minimum amount of money in the piggy-bank is "<<dp[f-e]<<"."<<endl;
	}
}