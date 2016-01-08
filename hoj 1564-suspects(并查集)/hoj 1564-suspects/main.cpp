#include<cstdio>
#include<iostream>
const int MAXSIZE=500010;
int rank[MAXSIZE],x,y;//rank���������
int parent[MAXSIZE];//parent�Ǹ��ڵ�ı��
int num[MAXSIZE];//num��һ���ڵ�����������������Լ�
//��ʼ��x����
void make_set(int x)
{
    parent[x]=x;
    rank[x]=0;
	num[x]=1;
}
//����x���ڵļ���
int find_set(int x)
{
    if(parent[x]!=x) parent[x]=find_set(parent[x]);
    return parent[x];
}
//�ϲ�x��y���ڵļ��ϣ��õ�·��ѹ�������Ⱥϲ�
void Union(int x,int y)
{
    x=find_set(x);
    y=find_set(y);
    if(rank[x]>rank[y]){
        parent[y]=x;
		num[x]+=num[y];
	}
    else if(rank[x]<rank[y]){
        parent[x]=y;
		num[y]+=num[x];
	}
    else if(rank[x]==rank[y])
    {
        parent[x]=y;
        rank[y]++;
		num[y]+=num[x];
    }
}
int main()
{
	int n,m,t,t1,t2;
	while(scanf("%d %d",&n,&m)!=EOF&&n!=0)
	{
		for(int i=0;i<MAXSIZE;i++)
			make_set(i);
		for(int i=0;i<m;i++)
		{
			scanf("%d",&t);
			scanf("%d",&t1);
			for(int j=1;j<t;j++)
			{
				scanf("%d",&t2);
				Union(find_set(t1),find_set(t2));
			}
		}
		for(int i=0;i<=n;i++)
			printf("%d ",rank[i]);
		printf("\n");
		for(int i=0;i<=n;i++)
			printf("%d ",num[i]);
		printf("\n");
		for(int i=0;i<=n;i++)
			printf("%d ",parent[i]);
		printf("%d\n",num[find_set(0)]);
	}
}