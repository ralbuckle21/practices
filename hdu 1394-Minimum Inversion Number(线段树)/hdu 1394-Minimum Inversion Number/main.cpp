#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
struct Node
{
    int left;
    int right;
    int sum;
};
Node node[5010*4];
int n,m,num[5010],t1,t2,t3;
void TreeMake(int l,int r,int i)
{
    node[i].left=l;
    node[i].right=r;
    node[i].sum=0;
    if (node[i].left == node[i].right)
	{
        return;
    }
    int m=(l + r)/2;
    TreeMake(l,m,i*2);
    TreeMake(m+1,r,i*2+1);
}
// i 节点下标
// x 节点的值
// s 要更新的属性
void TreeUpdate(int i,int x,int s)
{
    int l = node[i].left;
    int r = node[i].right;
    int m = (l + r) / 2;
    if (node[i].sum < s)
    {
        node[i].sum = s;
    }
    if (l == x && r == x)
    {
        node[i].sum = s;
        return ;
    }
    if (x > m)
    {
        TreeUpdate(i*2+1, x, s);
    }
    else if (x <= m)
    {
        TreeUpdate(i*2, x, s);
    }
}
int TreeQuery(int i, int x, int y)
{
    int l = node[i].left;
    int r = node[i].right;
    int m = (l + r) / 2;
    int res = 0;
    if (l == x && r == y)
    {
        return node[i].sum;
    }
    if (y <= m)
    {
        res = TreeQuery(i*2, x, y);
    }
    else if (x > m)
    {
        res = TreeQuery(i*2+1, x, y);
    }
    else
    {
        res=max(TreeQuery(i*2, x, m),TreeQuery(i*2+1, m+1, y));
    }
    return res;
}
int main()
{
	scanf("%d",&n);
	TreeMake(1,n,1);
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		cin>>num[i];
		sum+=TreeQuery(1,1,n);
		TreeUpdate(1,1,n);
	}
	int ret=sum;
	for(int i=1;i<=n;i++)
	{
		sum+=(n-2*num[i]-1);
		ret=min(ret,sum);
	}
	printf("%d\n",ret);
}