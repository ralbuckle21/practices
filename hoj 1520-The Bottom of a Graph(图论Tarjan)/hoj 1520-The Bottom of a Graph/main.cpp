#include<iostream>
#include<stack>
using namespace std;
#define MAXN 999//MAXN一般定义为点的最大个数
int head[MAXN],num=0;//head是头结点编号集，注意[]中的值表示头结点编号，而head[]的值表示了头结点所连接的第一个节点
int time[MAXN];//记录访问次数，0表示是没有访问过的白色点
int id[MAXN];//记录点所属强连通分量的编号
int n,m;//输入的点的总数和边的总数
int sgn[MAXN];//smallest grey number节点i及其后代能达到的最小灰色点的编号
bool visited[MAXN];//记录各个点是否访问过
int index,size=0;
struct node{
	int pre;//在之前的节点编号
	int n;//这个节点的编号
}p[MAXN*MAXN];
stack<int> sta;
int min(int a,int b)
{
	if(a<b) return a;
	else return b;
}
void insert(int a,int b){
	p[++num].pre=head[a];
	p[num].n=b;
	head[a]=num;//注意，后插入的节点排在邻接链表每个头结点上
}
void tarjan(int x)
{
	time[x]=sgn[x]=++index;//index记载了访问的次数
	sta.push(x);
	visited[x]=true;
	for(int i=head[x],j;j=p[i].n,i;i=p[i].pre){//从x所连接的点开始遍历
		if(!time[j]){//如果x是白色点
			tarjan(j);
			sgn[x]=min(sgn[x],sgn[j]);
		}
		else if(visited[x]) sgn[x]=min(sgn[x],time[j]);//如果x是灰色点
	}
	if(time[x]==sgn[x]){//如果点x是强连通分量的根
		size++;
		int t;
		do{
			t=sta.top();
			printf("%d ",t);
			sta.pop();//栈顶元素不断退栈直到栈顶为x
			visited[t]=false;
			id[t]=size;
		}while(t!=x);
	}
}
void scc()
{
	index=size=0;
	//memset(p,0,sizeof(p));
	memset(visited,false,sizeof(visited));
	memset(id,0,sizeof(id));
	memset(time,0,sizeof(time));
	memset(sgn,0,sizeof(sgn));
	while(!sta.empty())
		sta.pop();
    for(int i=1;i<=n;i++)
		if(!time[i])//如果这个点还未访问过
			tarjan(i);//用tarjan算法找它的强连通回路
}
int main()
{
	int t1,t2;
    while(scanf("%d",&n)&&n!=0){
		scanf("%d",&m);
		while(m--){
			scanf("%d %d",&t1,&t2);
			insert(t1,t2);
		}
		scc();
		printf("\n");
	}
}