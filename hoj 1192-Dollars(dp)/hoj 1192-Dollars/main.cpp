#include<cstdio>
#include<string.h>
#define MAXN 30010//ÿһ��Ǯ��Ҫ����һ��
const int value[12]={0,5,10,20,50,100,200,500,1000,2000,5000,10000};
int dp[MAXN];
int main()
{
	int t1,t2,temp;
	while(scanf("%d.%d",&t1,&t2))
	{
		temp=100*t1+t2;
		if(!temp) break;
		memset(dp,0,sizeof(dp));
		dp[0]=1;
		for(int j=1;j<=11;j++)
			for(int i=1;i<=temp;i++)//����i��j�����Եߵ�����Ϊdp�ĸ�Ԫ����Ҫ���ȷ��
				if(i>=value[j]) dp[i]+=dp[i-value[j]];//һά��dp���飬ÿ��Ԫ�ص�������i��Ǯ��������࣬ÿ���һ��valuei��dp[i]�ͼ���dp[i-value[j]]��¼����ɷ�������
		double output=temp/100.0;
        printf("%6.2lf",output); 
        printf("%17lld\n",dp[temp]);
	}
}