# include<iostream>
using namespace std;
#define maxn 121
struct Node
{
	int in ;
	int out ;
};
int no_in(Node *p,const int &n)
{
	int i,j=maxn,x;
	for(i = 1;i <= n;i++)
	{
		if(p[i].in < j)
		{
			j = p[i].in;
			x = i;	
		}
	}
	return x;
}
void main()
{
	Node node[maxn];
	int street[maxn][maxn];
	int set,noden,streetn;
	scanf("%d",&set);
	int i,j,min,pn;
	int sk,ek;
	int m_in,x;
	while(set-- != 0)
	{
		scanf("%d%d",&noden,&streetn);
		for(i = 1;i <= noden;i++)		//初始化node[],street[]
		{
			for(j =1;j<= noden;j++)
			{
				street[i][j] = 0;
			}
			node[i].in = 0;
			node[i].out = 0;
		}
		for(i = 0;i<streetn;i++ )
		{
			scanf("%d%d",&sk,&ek);
			node[sk].out++;
			node[ek].in++;
			street[sk][ek] = 1;	
		}
		i = 0;
		pn = 0;
		for(;i < noden;)		//选择路径
		{
		
			min = no_in(node,noden);
			i++;
			node[min].in = maxn;
			pn++;
			//深度优先搜索，	
			while(node[min].out > 0)
			{
				if(node[min].out > 1)
				{
					m_in = maxn;x = 1;
					for(j = 1;j <= noden;j++)
					{
						if(street[min][j] == 1 && node[j].in < maxn )
						{
							if(node[j].in < m_in)
							{
								m_in = node[j].in;
								x = j;
							}
							else if(node[j].in == m_in)
							{
								if(node[j].out > node[x].out)
									x = j;
							}
							node[j].in--;
						}
					}
					if(m_in != maxn)
					{
						min = x;
						i++;
						node[min].in = maxn;
						for(j = 1;j <= noden;j++)
						{
							if(street[j][min] == 1)
							{
								node[j].out --;
							}
						}
					}
				}
				else
				{
					for(j = 1;j <= noden;j++)
					{
						if(street[min][j] == 1 && node[j].in < maxn)
						{
							min = j;
							i++;
							break;
						}
					}
					if(j > noden)
						break;
					node[min].in = maxn;	
					for(j = 1;j <= noden;j++)
					{
						if(street[j][min] == 1)
						{
							node[j].out--;
						}
					}
				}
			}
		}
		printf("%d\n",pn);
	}
	system("pause");
}
