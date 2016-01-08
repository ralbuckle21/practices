/*BellmanFord��Ȩ���·
	A friend of yours, an inventor,  built a spaceship recently and wants to explore space with it. During his first voyages, he discovered that the universe is full of wormholes created by some alien race. These wormholes allow one to travel to places far, far away, but moreover, they can also send you to times long ago or in the distant future. Having mapped these wormholes and their respective end points, you and your friend boldly decide to board his spaceship and go to some distant place you��d like to visit. Of course, you want to arrive at your destination as early as possible. The question is: what is this earliest arrival time? 

InputThe first line of input contains an integer c (1 �� c �� 200), the number of test cases. Each test case starts with a line containing two coordinate triples x0,y0,z0 and x1,y1,z1, the space coordinates of your departure point and destination. The next line contains an integer n (0 �� n �� 50), the number of wormholes. Then follow n lines, one for each wormhole, with two coordinate triples xs,ys,zs and xe,ye,ze, the space coordinates of the wormhole entry and exit points, respectively, followed by two integers t,d (-1000000 �� t,d �� 1000000), the creation time t of the wormhole and the time shift d when traveling through the wormhole. All coordinates are integers with absolute values smaller than or equal to 10000 and no two points are the same. Note that, initially, the time is zero, and that tunneling through a wormhole happens instantly. For simplicity, the distance between two points is defined as their Euclidean distance (the square root of the sum of the squares of coordinate differences) rounded up to the nearest integer. Your friend��s spaceship travels at speed 1. OutputFor each test case, print a single line containing an integer: the earliest time you can arrive at your destination. 


Sample Input2  
0 0 0 100 0 0  
2  
1 1 0 1 2 0 -100 -2  
0 1 0 100 1 0 -150 10  
0 0 0 10 0 0  
1  
5 0 0 -5 0 0 0 0
Sample Output-89  
10

	*/
//BellmanFord�㷨����Ȩ����ͼ�����·�����ؼ��������ɳ�
//�����ڵ�Դ���·�� ���Լ��ϵͳ
/*��һ����ʼ�����е㡣ÿһ���㱣��һ��ֵ����ʾ��ԭ�㵽�������ľ��룬��ԭ���ֵ��Ϊ0�������ĵ��ֵ��Ϊ����󣨱�ʾ���ɴ��
�ڶ�������ѭ����ѭ���±�Ϊ��1��n��1��n����ͼ�е�ĸ���������ѭ���ڲ����������еıߣ������ɳڼ��㡣
�ɳڣ�����ÿһ����e(u, v)�����Distant[u] + w(u, v) < Distant[v]������Distant[v] = Distant[u]+w(u, v)
����������;�����еıߣ�edge��u��v�������ж��Ƿ�������������
d��v�� > d (u) + w(u,v)
�򷵻�false����ʾ;�д��ڴ�Դ��ɴ��ȨΪ���Ļ�·*/
#include<iostream>
#include<stdio.h>
using namespace std;

#define MAX 0x3f3f3f3f
#define N 2510
#define MN 250005
int nodenum, edgenum, original; //�㣬�ߣ����

typedef struct Edge //��
{
	int u, v;
	int cost;
}Edge;

Edge edge[N];
int dis[MN], pre[MN];

bool Bellman_Ford()
{
	for(original=1;original<=nodenum;original++){
	for(int i = 1; i <= nodenum; ++i) //��ʼ��
		dis[i] = (i == original ? 0 : MAX);
	for(int i = 1; i <= nodenum - 1; ++i)
		for(int j = 1; j <= edgenum; ++j)
			if(dis[edge[j].v] > dis[edge[j].u] + edge[j].cost) //�ɳڣ�˳��һ�����ܷ�~��
			{
				dis[edge[j].v] = dis[edge[j].u] + edge[j].cost;
				pre[edge[j].v] = edge[j].u;
			}
			bool flag = 1; //�ж��Ƿ��и�Ȩ��·
			for(int i = 1; i <= edgenum; ++i)
				if(dis[edge[i].v] > dis[edge[i].u] + edge[i].cost)
				{
					return 0;
				}
	}
	return 1;
}

void print_path(int root) //��ӡ���·��·��������
{
	while(root != pre[root]) //ǰ��
	{
		printf("%d-->", root);
		root = pre[root];
	}
	if(root == pre[root])
		printf("%d\n", root);
}

int main()
{
	int cas;
	scanf("%d",&cas);
	while(cas--){
		int ta,tb,tc;
	    scanf("%d%d%d", &ta, &tb, &tc);
	    nodenum=ta;
		edgenum=2*tb+tc;
		original=1;
		pre[original] = original;
		for(int i = 1; i <= tb+tc; ++i){
			scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].cost);
			if(i>tb)
				edge[i].cost=-edge[i].cost;
			else{
				int j=i+tb+tc;
				edge[j].v=edge[i].u;
				edge[j].u=edge[i].v;
				edge[j].cost=edge[i].cost;
			}
		}
		if(Bellman_Ford())
			printf("NO\n");
		else
			printf("YES\n");
	}
}