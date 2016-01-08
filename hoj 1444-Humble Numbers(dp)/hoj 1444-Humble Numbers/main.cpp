#include<cstdio>
#include<iostream>
using namespace std;
#define MAX 2000000001
long long dp[6000];
int main()
{
	int prime[4]={2,3,5,7},n,i,j,k;
	dp[1]=1;
	for(i=2;i<6000;i++)
	{
		dp[i]=MAX;
		for(j=0;j<4;j++)
		{
			for(k=i-1;k>=1;k--)
            {
                if(dp[k]*prime[j]<=dp[i-1])break;//dp初始化为max,则可以采用这种判断条件
                if(dp[k]*prime[j]<dp[i]) dp[i]=dp[k]*prime[j];//从当前的i遍历回去
            } 
		}
	}
	while(cin>>n)   
    {
		if(!n) break;
        cout<<"The "<<n;
        if(n%10==1&&n%100!=11)cout<<"st ";
        else if(n%10==2&&n%100!=12)cout<<"nd ";
        else if(n%10==3&&n%100!=13)cout<<"rd ";
        else  cout<<"th ";
        cout<<"humble number is "<<dp[n]<<"."<<endl;
        
    } 
}