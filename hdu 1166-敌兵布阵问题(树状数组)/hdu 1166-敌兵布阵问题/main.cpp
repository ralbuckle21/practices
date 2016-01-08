#include<iostream>
#define MAX 50005
int t,man,t1,t2,N,c[MAX];
char st[50];
int lowbit(int i)
{
    return i&(-i);
}
void modify(int i,int delta)//��i�ڵ��ֵ����delta
{
    while(i<=N)
    {
        c[i]+=delta;
        i+=lowbit(i);
	}
}//i��1��ʼ
int sum(int i)//��¼��iΪֹ����ֵ
{
	int ret=0;
	while(i>0)
	{
		ret+=c[i];
		i-=lowbit(i);
	}
	return ret;
}
void init()
{
    for(int i=0;i<=N;i++)
		c[i]=0;
}
int main()
{
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		init();
		scanf("%d",&N);
		for(int j=1;j<=N;j++)
		{
			scanf("%d",&man);
			modify(j,man);//Ϊj�ڵ�����man��
		}
		printf("Case %d:\n",i+1);
		while(scanf("%s",st)&&st[0]!='E')
		{
			scanf("%d%d",&t1,&t2);
			if(st[0]=='A')
				modify(t1,t2);//Ϊt1�ڵ�����t2��
			else if(st[0]=='S')
				modify(t1,-t2);//Ϊt1�ڵ����t2��
			else
				printf("%d\n",sum(t2)-sum(t1-1));
		}
	}
}