#include<cstdio>
#include<iostream>
const int MAXSIZE=30001;
int pre[MAXSIZE]//���ڵ㣬pre[i]=-num,num�Ǹ����ڵ���Ŀ
//�Ǹ��ڵ�j,pre[j]=k,k��j�ĸ��ڵ�
int Find(int x)//����+�ǵݹ�·��ѹ��
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
	//��Ȩ����ϲ�
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
