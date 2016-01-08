#include<iostream>
#include<stack>
using namespace std;
#define MAXN 999//MAXNһ�㶨��Ϊ���������
int head[MAXN],num=0;//head��ͷ����ż���ע��[]�е�ֵ��ʾͷ����ţ���head[]��ֵ��ʾ��ͷ��������ӵĵ�һ���ڵ�
int time[MAXN];//��¼���ʴ�����0��ʾ��û�з��ʹ��İ�ɫ��
int id[MAXN];//��¼������ǿ��ͨ�����ı��
int n,m;//����ĵ�������ͱߵ�����
int sgn[MAXN];//smallest grey number�ڵ�i�������ܴﵽ����С��ɫ��ı��
bool visited[MAXN];//��¼�������Ƿ���ʹ�
int index,size=0;
struct node{
	int pre;//��֮ǰ�Ľڵ���
	int n;//����ڵ�ı��
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
	head[a]=num;//ע�⣬�����Ľڵ������ڽ�����ÿ��ͷ�����
}
void tarjan(int x)
{
	time[x]=sgn[x]=++index;//index�����˷��ʵĴ���
	sta.push(x);
	visited[x]=true;
	for(int i=head[x],j;j=p[i].n,i;i=p[i].pre){//��x�����ӵĵ㿪ʼ����
		if(!time[j]){//���x�ǰ�ɫ��
			tarjan(j);
			sgn[x]=min(sgn[x],sgn[j]);
		}
		else if(visited[x]) sgn[x]=min(sgn[x],time[j]);//���x�ǻ�ɫ��
	}
	if(time[x]==sgn[x]){//�����x��ǿ��ͨ�����ĸ�
		size++;
		int t;
		do{
			t=sta.top();
			printf("%d ",t);
			sta.pop();//ջ��Ԫ�ز�����ջֱ��ջ��Ϊx
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
		if(!time[i])//�������㻹δ���ʹ�
			tarjan(i);//��tarjan�㷨������ǿ��ͨ��·
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