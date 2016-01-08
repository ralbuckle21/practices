#include<cstdio>
#include<string.h>
#define MAXN 30010//每一分钱都要单独一列
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
			for(int i=1;i<=temp;i++)//这里i和j不可以颠倒，因为dp的各元素需要逐个确认
				if(i>=value[j]) dp[i]+=dp[i-value[j]];//一维的dp数组，每个元素的意义是i分钱的组成种类，每差出一个valuei，dp[i]就加上dp[i-value[j]]记录的组成方法数量
		double output=temp/100.0;
        printf("%6.2lf",output); 
        printf("%17lld\n",dp[temp]);
	}
}