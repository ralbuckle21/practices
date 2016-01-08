#include<iostream>
using namespace std;
int main()
{
	int n;
	int dp[10001];
	while(cin>>n&&n!=0)
	{
		memset(dp,0,sizeof(dp));
		int c,max=0;
		for(int i=0;i<n;i++)
		{
			cin>>c;
			if(dp[i]>0) dp[i+1]=dp[i]+c;
			else dp[i+1]=c;
			if(dp[i+1]>=max) max=dp[i+1];
		}
		if(max>0) cout<<"The maximum winning streak is "<<max<<"."<<endl;
		else cout<<"Losing Streak."<<endl;
	}
}