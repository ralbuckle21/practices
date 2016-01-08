#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#include<iostream>
using namespace std;
int n,m,maxNum,i;
int father[50005],num[50005];
void makeSet(int n)
{
	for(int j = 1; j <= n; j++)
	{
		father[j]=j;
		num[j]=1;
	}
}
int findSet(int x)
{
	if(father[x]!=x) 
	{	
		father[x]=findSet(father[x]);
	}
	return father[x]; 
}

void Union(int a, int b)
{
	int x = findSet(a);
	int y = findSet(b);
	if(x == y)
	{
		return;
	}
	if(num[x] <= num[y])
	{
		father[x] = y;
		num[y] += num[x];
		maxNum--;
	}
	else 
	{
		father[y] = x;
		num[x] += num[y];
		maxNum--;
	}
}
int main()
{
	int t1,t2,count=0;
	while(scanf("%d %d",&n,&m)!=EOF&&n!=0)
	{
		count++;
		maxNum=n;
	    makeSet(n);
		for(i=0;i<m;i++)
		{
			cin>>t1>>t2;
			Union(t1,t2);
		}
		cout<<"Case "<<count<<": "<<maxNum<<endl;
	}
}