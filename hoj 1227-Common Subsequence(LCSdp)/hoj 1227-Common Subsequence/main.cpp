/*#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
#define MAX 1000
int main()
{
	char s1[MAX],s2[MAX];
	int **dp;
	while(cin>>s1>>s2)
	{
		dp=(int**)malloc(sizeof(int)*strlen(s1));
	    for(int i=0;i<strlen(s1);i++)
        {
            dp[i]=(int*)malloc(sizeof(int)*strlen(s2));
        }
		for(int i=0;i<strlen(s1);i++)
		{
			for(int j=0;j<strlen(s2);j++)
				dp[i][j]=0;
		}
		for(int i=0;i<strlen(s1);i++)
		{
			for(int j=0;j<strlen(s2);j++)
			{
				int t1,t2,t3;
				if(i>0) t2=dp[i-1][j];
				else t2=0;
				if(j>0) t3=dp[i][j-1];
				else t3=0;
				if(i>0&&j>0) t1=dp[i-1][j-1];//max(dp[i][j-1],dp[i-1][j]);
				else t1=0;
				if(s1[i]==s2[j]) 
				{
					dp[i][j]=t1+1;
				}
				else dp[i][j]=max(t2,t3);
			}
		}
		cout<<dp[strlen(s1)-1][strlen(s2)-1]<<endl;
	}
}*/
#include <iostream>
#include<stdio.h>
using namespace std;
#define MAXV 1000

int same(int a,int b){
	return a==b?1:0;
}//判断两个字符是否相等

int max(int a,int b, int c){
	if(a>=b && a>=c) return a;
	if(b>=a && b>=c) return b;
	return c;
}

int dp[MAXV][MAXV];
char s1[MAXV],s2[MAXV];

int main(){
	int len1,len2,i,j;
	while(scanf("%s %s",s1,s2)!=EOF){
		memset(dp,0,sizeof(dp));
		len1=strlen(s1);
		len2=strlen(s2);
		for(i=1;i<=len1;i++){
			for(j=1;j<=len2;j++){//i和j代表当前考虑到的位置，即字符串的1--i位和1---j位
				dp[i][j]=max( dp[i-1][j-1]+same(s1[i-1],s2[j-1]) , dp[i-1][j] , dp[i][j-1]);
			}
		}
		printf("%d\n",dp[len1][len2]);
	}
}