#include<cstdio>
#include<iostream>
const int MAXSIZE=30001;
int pre[MAXSIZE]//根节点，pre[i]=-num,num是该树节点数目
//非根节点j,pre[j]=k,k是j的父节点
int Find(int x)//查找+非递归路径压缩
{
	int p=x;
	while(pre[p]>0) p=pre[p];
	while(x!=p)
	{
		int temp=pre[x];
		pre[x]=p;
		x=temp;
	}
	return x;
}
void Union(int r1,int r2)
{
	int a=Find(r1);
	int b=Find(r2);
	if(a==b) return;
	//加权规则合并
	if(pre[a]<pre[b])
	{
		pre[a]+=pre[b];
		pre[b]=a;
	}
	else
	{
		pre[b]+=pre[a];
		pre[a]=b;
	}
}
void init()
{
	for(int i=0;i<N;++i) pre[i]=-1;
}
