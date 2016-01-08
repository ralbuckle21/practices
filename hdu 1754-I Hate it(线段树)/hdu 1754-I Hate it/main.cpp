#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
struct Node
{
    int left;
    int right;
    int max;
	int maxval;
};
Node node[200010*4];
int cs,n,m,num,t1,t2,t3;
void TreeMake(int l, int r, int i)
{
    node[i].left = l;
    node[i].right = r;
    node[i].max = 0;
	node[i].maxval=0;
    if (node[i].left == node[i].right)
    {
        return ;
    }
    int m = (l + r)/2;
    TreeMake(l, m, i*2);
    TreeMake(m+1, r, i*2 + 1);
}
// i 节点下标
// x 节点的值
// s 要更新的属性
void TreeUpdate(int i,int x,int s)
{
    int l = node[i].left;
    int r = node[i].right;
    int m = (l + r) / 2;
    if (node[i].max < s)
    {
        node[i].max = s;
    }
    if (l == x && r == x)
    {
        node[i].max = s;
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
void insert(int i,int pos,int val)
{
	if(node[node[i].left].max==pos &&node[node[i].right].max==pos)
    {
        node[i].maxval = val; return;
    }
    int mid=(node[i].left+node[i].right)>>1;
	if (pos<=node[mid].max) insert(2*i, pos, val);
    else insert(2*i+1, pos, val);
    node[i].maxval= max(node[2*i].maxval, node[2*i+1].maxval);
}
int TreeQuery(int i, int x, int y)
{
    int l = node[i].left;
    int r = node[i].right;
    int m = (l + r) / 2;
    int res = 0;
    if (l == x && r == y)
    {
        return node[i].maxval;
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
	scanf("%d",&cs);
    while(cs--)
    {
		scanf("%d %d",&n,&m);
        TreeMake(1,n,1);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&num);
            TreeUpdate(1,i,num);
        }
        for(int i=1;i<=m;i++)
        {
            getchar();
            scanf("%c %d %d",&t1,&t2,&t3);
            if(t1=='Q')
            {
                printf("%d\n",TreeQuery(1,t2+1,t3+1));
            }
            else
                TreeUpdate(1,t2+1,t3);
        }
    }
}