#include<iostream>
#include<math.h>
const int MAXSIZE=500010;
int rank[MAXSIZE];//节点高度上界
int parent[MAXSIZE];//根节点
int num[MAXSIZE];
int FindSet(int x)
{
	if(x!=parent[x]) parent[x]=FindSet(parent[x]);
	return parent[x];
}
int Find(int x)
{
	if(x!=parent[x])
	{
	    int temp;
	    temp=parent[x];
	    parent[x]=Find(parent[x]);
	    num[x]+=num[temp];
	}
	return parent[x];
}
void Union(int root1,int root2)
{
	parent[root1]=root2;
	num[root1]=abs(root2-root1)%1000;
}
void init(void)
{
	memset(rank,0,sizeof(rank));
	for(int i=0;i<MAXSIZE;++i)
	{
		parent[i]=i;
		num[i]=0;
	}
}
int main()
{
	int t,N,c,a,b;
	char s[10];
	scanf("%d",&t);
	while(t--)
	{
		init();
		scanf("%d",&N);
		while(scanf("%s",&s)&&s[0]!='O')
		{
			if(s[0]=='E')
			{
				scanf("%d",&a);
				Find(a);
			    printf("%d\n",num[a]);
			}
			else if(s[0]=='I')
			{
				scanf("%d %d",&a,&b);
				Union(a,b);
			}
		}
	}
}