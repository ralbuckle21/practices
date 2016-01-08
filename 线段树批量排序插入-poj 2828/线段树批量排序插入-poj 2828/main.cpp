#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int maxint=200010;
int total,dir,n;//total相当于i,是当前处理的节点号码
int answer[maxint];
struct T
{
	int pos;
	int value;
}a[maxint];
struct Tree
{
	int a,b;
	int left,right;
	int num;
}tree[maxint*8];
void maketree(int l,int r)
{
	total++;
	int now=total;
	tree[total].a=l;
	tree[total].b=r;
	tree[total].num=r-l+1;
	if(l<r)//保证左<右
	{
		int mid=(l+r)>>1;
		tree[now].left=total+1;
		maketree(l,mid);
		tree[now].right=total+1;
		maketree(mid+1,r);
	}
}
void insertseg(int v,int x)//v是初始位置，x是待插入元素
{
	int i,j,k;
	if(tree[v].a==tree[v].b)
	{
		tree[v].num--;
		answer[tree[v].a]=a[n-dir-1].value;
		dir++;
		return ;
	}
	tree[v].num--;
	if(tree[tree[v].left].num>x)
	{
		insertseg(tree[v].left,x);
	}
	else
	{
		insertseg(tree[v].right,x-tree[tree[v].left].num);
	}
}
void work()
{
	int i,j,k;
	memset(answer,0,sizeof(answer));
	dir=0;
	for(i=n-1;i>=0;i--)
		insertseg(1,a[i].pos);//在i号元素的位置插入
	for(i=0;i<n-1;i++)
		printf("%d ",answer[i]);
	printf("%d\n",answer[n-1]);
}
int main()
{
	int i,j,k,m;
	while(scanf("%d",&n)!=EOF)
	{
		total=0;
		for(i=0;i<n;i++)
			scanf("%d%d",&a[i].pos,&a[i].value);
		maketree(0,n-1);
		work();
	}
	return 0;
}