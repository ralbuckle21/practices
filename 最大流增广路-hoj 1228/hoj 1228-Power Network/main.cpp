/*���������·
	A power network consists of nodes (power stations, consumers and dispatchers) connected by power transport lines. A node u may be supplied with an amount s(u) >= 0 of power, may produce an amount 0 <= p(u) <= pmax(u) of power, may consume an amount 0 <= c(u) <= min(s(u),cmax(u)) of power, and may deliver an amount d(u)=s(u)+p(u)-c(u) of power. The following restrictions apply: c(u)=0 for any power station, p(u)=0 for any consumer, and p(u)=c(u)=0 for any dispatcher. There is at most one power transport line (u,v) from a node u to a node v in the net; it transports an amount 0 <= l(u,v) <= lmax(u,v) of power delivered by u to v. Let Con=sum of c(u) be the power consumed in the net. The problem is to compute the maximum value of Con. 
""" 
An example is in figure 1. The label x/y of power station u shows that p(u)=x and pmax(u)=y. The label x/y of consumer u shows that c(u)=x and cmax(u)=y. The label x/y of power transport line (u,v) shows that l(u,v)=x and lmax(u,v)=y. The power consumed is Con=6. Notice that there are other possible states of the network but the value of Con cannot exceed 6.

There are several data sets in the input text file. Each data set encodes a power network. It starts with four integers: 0 <= n <= 100 (nodes), 0 <= np <= n (power stations), 0 <= nc <= n (consumers), and 0 <= m <= n^2 (power transport lines). Follow m data triplets (u,v)z, where u and v are node identifiers (starting from 0) and 0 <= z <= 1000 is the value of lmax(u,v). Follow np doublets (u)z, where u is the identifier of a power station and 0 <= z <= 10000 is the value of pmax(u). The data set ends with nc doublets (u)z, where u is the identifier of a consumer and 0 <= z <= 10000 is the value of cmax(u). All input numbers are integers. Except the (u,v)z triplets and the (u)z doublets, which do not contain white spaces, white spaces can occur freely in input. Input data terminate with an end of file and are correct.

For each data set from the input, the program prints on the standard output the maximum amount of power that can be consumed in the corresponding network. Each result has an integral value and is printed from the beginning of a separate line.

The sample input contains two data sets. The first data set encodes a network with 2 nodes, power station 0 with pmax(0)=15 and consumer 1 with cmax(1)=20, and 2 power transport lines with lmax(0,1)=20 and lmax(1,0)=10. The maximum value of Con is 15. The second data set encodes the network from figure 1.

Sample Input 2 1 1 2 (0,1)20 (1,0)10 (0)15 (1)20
7 2 3 13 (0,0)1 (0,1)2 (0,2)5 (1,0)1 (1,2)8 (2,3)1 (2,4)7
(3,5)2 (3,6)5 (4,2)7 (4,3)5 (4,5)1 (6,0)5
(0)5 (1)2 (3)2 (4)1 (5)4
Sample Output 15
6

	*/
/*BFS+ѹ���ر귨*/
//��Դ������������
//Memory  Time 
//384K    860MS  

#include<iostream>
using namespace std;

const int inf=10001;

int n;  //�ܽڵ���
int np; //��վ��
int nc; //�û���
int line;  //��·��
int cap[102][102];  //��(u,v)������
int flow[102][102];  //��(u,v)������
bool vist[102];   //��ǵ�v�Ƿ��ѱ��
int s,t;  //����Դ��������

class info   //��ǰ��v�ı����Ϣ
{
public:
	int pre;  //��ǰ��v��ǰ��u
	int lv;  //l(v)
	int nei[101];  //��ǰ���ֱ��ָ����ھӽ��
	int pn;  //�ھӽ���ָ��
}node[102];

int min(int a,int b)
{
	return a<b?a:b;
}

void back(void)
{
	int x=t;
	while(x!=s)
	{
		flow[ node[x].pre ][x] += node[t].lv;  //�Ľ�����·
		x=node[x].pre;

	}
	return;
}

bool bfs(void)
{
	memset(vist,false,sizeof(vist));
	node[s].pre=-1;
	node[s].lv=inf;
	vist[s]=true;

	int queue[102];
	int head=0;
	int tail=0;
	queue[tail++]=s;

	while(head<=tail-1)  //ע�⣬������Ҳ�Ҳ�������·�Ľ�������
	{
		int x=queue[head];
		int y;
		for(int i=0;i<node[x].pn;i++)
		{
			y=node[x].nei[i];
			if(!vist[y] && flow[x][y]<cap[x][y])   //������Ŀ��Ҫ���� δ��� & �Ǳ��ͻ�
			{
				queue[tail++]=y;

				vist[y]=true;
				node[y].pre=x;
				node[y].lv=min( node[x].lv , cap[x][y]-flow[x][y] );
			}
			if(vist[t])  //�������㱻���
				break;
		}
		if(!vist[t])
			head++;
		else
			return true;  //������һ������·
	}
	return false;
}

int main(int i,int j,int u,int v,int z,char temp)
{
	while(cin>>n>>np>>nc>>line)
	{
		/*Initial*/
		s=n;
		t=n+1;
		for(i=0;i<n+1;i++)
			node[i].pn=0;

		/*Input & Structure Maps*/

		for(i=1;i<=line;i++)
		{
			cin>>temp>>u>>temp>>v>>temp>>z;
			if(u==v)
				continue;   //����Ҫ��
			cap[u][v]=z;
			flow[u][v]=0;   //ÿ���ߵ���������ʼ��Ϊ0
			node[u].nei[ node[u].pn++ ]=v;
		}
		for(i=1;i<=np;i++)
		{
			cin>>temp>>v>>temp>>z;
			cap[s][v]=z;     //��������Դ��ָ�����е�վ
			flow[s][v]=0;
			node[s].nei[ node[s].pn++ ]=v;
		}
		for(i=1;i<=nc;i++)
		{
			cin>>temp>>u>>temp>>z;
			cap[u][t]=z;     //���������㣬�������û�ָ��
			flow[u][t]=0;
			node[u].nei[ node[u].pn++ ]=t;
		}

		/*��ŷ��������*/

		while(true)
		{
			if(bfs())  //������ѵ�������·
				back();  //�ӳ����㿪ʼ����,�Ľ�����·
			else
			{
				int max=0;        //��������
				for(i=0;i<node[s].pn;i++)
					max+=flow[s][ node[s].nei[i] ];
				cout<<max<<endl;
				break;
			}
		}
	}
	return 0;
}
