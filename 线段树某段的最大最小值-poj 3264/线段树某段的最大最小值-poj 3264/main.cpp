/*balanced lineup  �߶���ĳ�������Сֵ
	For the daily milking, Farmer John's N cows (1 �� N �� 50,000) always line up in the same order. One day Farmer John decides to organize a game of Ultimate Frisbee with some of the cows. To keep things simple, he will take a contiguous range of cows from the milking lineup to play the game. However, for all the cows to have fun they should not differ too much in height.

Farmer John has made a list of Q (1 �� Q �� 200,000) potential groups of cows and their heights (1 �� height �� 1,000,000). For each group, he wants your help to determine the difference in height between the shortest and the tallest cow in the group.

Input

Line 1: Two space-separated integers, N and Q. 
Lines 2..N+1: Line i+1 contains a single integer that is the height of cow i 
Lines N+2..N+Q+1: Two integers A and B (1 �� A �� B �� N), representing the range of cows from A to B inclusive.
Output

Lines 1..Q: Each line contains a single integer that is a response to a reply and indicates the difference in height between the tallest and shortest cow in the range.
Sample Input

6 3
1
7
3
4
2
5
1 5
4 6
2 2
Sample Output

6
3
0
	*/
#include <iostream>
using namespace std;
#define MAXV 50100
#define MAXT 1<<18
#define max(a,b) a>b?a:b
#define min(a,b) a>b?b:a
int a[MAXV],TL[MAXT],TR[MAXT],TMAX[MAXT],TMIN[MAXT];
//TL��TR������v�����������ұߵ��������������ѯ
//TMAX,TMIN��������v�����ֵ����Сֵ
void createTree(int v,int f,int t)//f,t����������������
{
	TL[v]=f;
	TR[v]=t;
	if(f==t)
	{
		TMAX[v]=a[f];
		TMIN[v]=a[f];
		return;
	}
	int mid=(f+t)>>1;
	createTree(v<<1,f,mid);
	createTree((v<<1)|1,mid+1,t);
	TMAX[v]=max(TMAX[v<<1],TMAX[(v<<1)|1]);//������ʱ����еݹ���ʽ�ĳ�ʼ��
	TMIN[v]=min(TMIN[v<<1],TMIN[(v<<1)|1]);
}
int queryTree(int v,int L,int R,int flag)
{//��ѯ��ʱ��ֻ��return�����ֽ�
	if(L==TL[v] && R==TR[v])
	{
		return (flag?TMIN[v]:TMAX[v]);//������query�е�return
	}
	int mid=(TL[v]+TR[v])>>1;
	if(R<=mid)
		return queryTree(v<<1,L,R,flag);
	else if(L>mid)
		return queryTree((v<<1)|1,L,R,flag);//return�ݹ飬��������R<mid,L>midʱ�ĵݹ飬��mid�޹�
	else
	{
		if(flag) return min(queryTree(v<<1,L,mid,flag),queryTree((v<<1)|1,mid+1,R,flag));
		else return max(queryTree(v<<1,L,mid,flag),queryTree((v<<1)|1,mid+1,R,flag));
	}
}
int main()
{
	int N,Q,L,R,i;
	while(scanf("%d%d",&N,&Q)!=EOF)
	{
		for(i=1;i<=N;i++)
			scanf("%d",&a[i]);
		createTree(1,1,N);
		while(Q--)
		{
			scanf("%d%d",&L,&R);
			printf("%d\n",queryTree(1,L,R,0)-queryTree(1,L,R,1));
		}
	}
	return 0;
}
