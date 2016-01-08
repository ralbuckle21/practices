#include <cstdio>
#include<math.h>
#define keyTree (ch[ch[root][1]][0])
const int maxn = 222222;
int min4(int a,int b,int c,int d)
{
	int t1,t2;
	if(a<b) t1=a;
	else t1=b;
	if(c<d) t2=c;
	else t2=d;
	if(t1<t2) return t1;
	else return t2;
}
int min2(int a,int b)
{
	if(a<b) return a;
	else return b;
}
struct SplayTree{
	int sz[maxn];//sz:����ڵ�����
	int ch[maxn][2];//������/������
	int pre[maxn];
	int root,top1,top2;
	int ss[maxn] , que[maxn];
	inline void Rotate(int x,int f) {
		int y = pre[x];
		ch[y][!f] = ch[x][f];
		pre[ ch[x][f] ] = y;
		pre[x] = pre[y];
		if(pre[x]) ch[ pre[y] ][ ch[pre[y]][1] == y ] = x;
		ch[x][f] = y;
		pre[y] = x;
		push_up(y);
	}
	inline void Splay(int x,int goal) {
		while(pre[x] != goal) {
			if(pre[pre[x]] == goal) {
				Rotate(x , ch[pre[x]][0] == x);
			} else {
				int y = pre[x] , z = pre[y];
				int f = (ch[z][0] == y);
				if(ch[y][f] == x) {
					Rotate(x , !f) , Rotate(x , f);
				} else {
					Rotate(y , f) , Rotate(x , f);
				}
			}
		}
		push_up(x);
		if(goal == 0) root = x;
	}
	inline void RotateTo(int k,int goal) {//�ѵ�kλ����ת��goal�±�
		int x = root;
		while(sz[ ch[x][0] ] != k) {
			if(k < sz[ ch[x][0] ]) {
				x = ch[x][0];
			} else {
				k -= (sz[ ch[x][0] ] + 1);
				x = ch[x][1];
			}
		}
		Splay(x,goal);
	}
	inline void erase(int x) {//����xΪ���Ƚ��ɾ���Ž��ڴ��,�����ڴ�
		int father = pre[x];
		int head = 0 , tail = 0;
		for (que[tail++] = x ; head < tail ; head ++) {
			ss[top2 ++] = que[head];
			if(ch[ que[head] ][0]) que[tail++] = ch[ que[head] ][0];
			if(ch[ que[head] ][1]) que[tail++] = ch[ que[head] ][1];
		}
		ch[ father ][ ch[father][1] == x ] = 0;
		push_up(father);
	}
	//����һ�㲻�޸�//////////////////////////////////////////////////////////////////////////////
	void debug() {printf("%d\n",root);Treaval(root);}
	void Treaval(int x) {
		if(x) {
			Treaval(ch[x][0]);
			printf("���%2d:����� %2d �Ҷ��� %2d ����� %2d size = %2d ,mm=%2d\n",x,ch[x][0],ch[x][1],pre[x],sz[x],mm[x]);
			Treaval(ch[x][1]);
		}
	}
	//����Debug
	//��������Ŀ���ض�����:
	inline void NewNode(int &x,int c) {
		if (top2) x = ss[--top2];//��ջ�ֶ�ѹ���ڴ��
		else x = ++top1;
		ch[x][0] = ch[x][1] = pre[x] = 0;
		sz[x] = 1;
		if(c>0) val[x]=c;
		else val[x]=maxn;
		mm[x]=c;
	}
	inline void push_up(int x) 
	{
		sz[x]=1+sz[ch[x][0]]+sz[ch[x][1]];
		mm[x]=min4(mm[x],abs(val[x]-val[ch[x][0]]),abs(val[ch[x][1]]-val[x]),abs(val[pre[x]]-val[x]));
		mm[ch[x][0]]=min2(mm[ch[x][0]],abs(val[x]-val[ch[x][0]]));
		mm[ch[x][1]]=min2(mm[ch[x][1]],abs(val[x]-val[ch[x][1]]));
		mm[pre[x]]=min2(mm[pre[x]],abs(val[pre[x]]-val[x]));
		for(int i=0;i<11;i++)
			printf("%d %d %d %d\n",val[i],val[ch[x][0]],val[ch[x][1]],mm[i]);
	}
	/*��ʼ��*/
	inline void makeTree(int &x,int l,int r,int f) {//makeTree������splay�������õݹ�
		if(l > r) return ;
		int m = (l + r)>>1;
		NewNode(x,num[m]);/*num[m]Ȩֵ�ĳ���Ŀ�����*/
		makeTree(ch[x][0],l,m-1,x);
		makeTree(ch[x][1],m+1,r,x);
		pre[x]=f;
		push_up(x);
	}
	inline void init(int n) 
	{
		ch[0][0]=ch[0][1]=pre[0]=sz[0]=0;
		mm[0]=maxn;
		root = top1 = 0;
		//Ϊ�˷��㴦��߽�,�������߽綥��
		NewNode(root,-1);
		NewNode(ch[root][1],-1);
		pre[top1]=root;
		sz[root]=2;
		for (int i=0;i<n;i++) scanf("%d",&num[i]);//����Ȩֵ
		makeTree(keyTree , 0 , n-1 , ch[root][1]);
		push_up(ch[root][1]);
		push_up(root);
	}
	inline void query(int n) 
	{
		for(int i=0;i<n+5;i++)
			printf("%d %d\n",val[i],mm[i]);
	}
	/*������Ŀ�ض�����*/
	int num[maxn];
	int mm[maxn];
	int val[maxn];
}spt;
int main()
{
	int n;
	scanf("%d",&n);
	spt.init(n);
	spt.debug();
	printf("\n");
	//spt.query(n);
	return 0;
}