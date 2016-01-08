#include<iostream>
#include<algorithm>
using namespace std;
int score[5][5]={ 5, -1, -2, -1, -3,
                 -1,  5, -3, -2, -4,
                 -2, -3,  5, -2, -2,
                 -1, -2, -2,  5, -1,
                 -3, -4, -2, -1,  0};
int dp[101][101];
int trans(char i)
{
	switch(i)
	{
	case 'A':return 0;
	case 'C':return 1;
	case 'G':return 2;
	case 'T':return 3;
	}
}
int find_max(int len1,char *s1,int len2,char *s2)
{
	dp[0][0]=0;
	for(int i=1;i<=len1;i++)
		dp[i][0]=score[trans(s1[i-1])][4]+dp[i-1][0];
	for(int i=1;i<=len2;i++)
		dp[0][i]=score[4][trans(s2[i-1])]+dp[0][i-1];
	for(int i=1;i<=len1;i++)
	{
		for(int j=1;j<=len2;j++)
		{
			int t1,t2,t3;
			t1=dp[i-1][j]+score[trans(s1[i-1])][4];
			t2=dp[i][j-1]+score[4][trans(s2[j-1])];
			t3=dp[i-1][j-1]+score[trans(s1[i-1])][trans(s2[j-1])];
			dp[i][j]=max(t1,max(t2,t3));
		}
	}
	return dp[len1][len2];
}
int main()
{
	int  n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int len1,len2;
		char s1[101],s2[101];
		cin>>len1>>s1>>len2>>s2;
		cout<<find_max(len1,s1,len2,s2)<<endl;
	}
}