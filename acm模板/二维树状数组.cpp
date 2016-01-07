#include<iostream>
using namespace std;
#define MAXN 10005
int N,c[MAXN][MAXN];
int lowbit(int x)
{
	return x&(-x);
}
void modify(int x,int y,int delta)
{
	int i,j;
	for(i=x;i<=N;i+=lowbit(i)){
		for(j=y;j<=N;j+=lowbit(j)){
			c[i][j]+=delta;
		}
	}
}
int sum(int x,int y)
{
	int res=0,i,j;
	for(i=x;i>0;i-=lowbit(i)){
		for(j=y;j>0;j-=lowbit(j)){
			res+=c[i][j];
		}
	}
	return res;
}