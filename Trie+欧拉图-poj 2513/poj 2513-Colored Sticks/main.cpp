/* TrieTree + MergeSet + EulerPath*/
/*colored stick  Trie+ŷ��ͼ
	Description

You are given a bunch of wooden sticks. Each endpoint of each stick is colored with some color. Is it possible to align the sticks in a straight line such that the colors of the endpoints that touch are of the same color?
Input

Input is a sequence of lines, each line contains two words, separated by spaces, giving the colors of the endpoints of one stick. A word is a sequence of lowercase letters no longer than 10 characters. There is no more than 250000 sticks.
Output

If the sticks can be aligned in the desired way, output a single line saying Possible, otherwise output Impossible.
Sample Input

blue red
red violet
cyan blue
blue magenta
magenta cyan
Sample Output

Possible
Hint

Huge input,scanf is recommended.*/
//trie���� 
#include<iostream>
using namespace std;  
const int large=500000;  //25W�����ӣ���50W���˵�
class TrieTree_Node   //�ֵ������
{
	public:
		bool flag;   //��ǵ��ֵ����Ӹ�����ǰ��������ɵ��ַ����Ƿ�Ϊһ��(��ɫ)����
		int id;     //��ǰ��ɫ(���)�ı��
		TrieTree_Node* next[27];
		TrieTree_Node()   //initial
		{
			flag=false;
			id=0;
			memset(next,0,sizeof(next));  //0 <-> NULL
		}
}root;   //�ֵ������ڵ�

int color=0;  //��ɫ���ָ�룬����Ϊ��ɫ�ܸ���

int degree[large+1]={0};   //��id�������ܶ���
int ancestor[large+1];   //��id���������


/*Ѱ��x������������*/

int find(int x)
{
	if(ancestor[x]!=x)
		ancestor[x]=find(ancestor[x]);   //·��ѹ��
	return ancestor[x];
}

/*�ϲ�a��b��������*/

void union_set(int a,int b)
{
	int pa=find(a);
	int pb=find(b);
	ancestor[pb]=pa;   //ʹa������ ��Ϊ b������
	return;
}

//�����ֵ��������ַ���s�����int��ӳ��

int hash(char *s)  
{
	TrieTree_Node* p=&root;  //��TrieTree�ĸ��ڵ������������(���ʲ������򴴽�)

    int len=0;
    while(s[len]!='\0')
    {
		int index=s[len++]-'a';  //��Сд��ĸa~zӳ�䵽���ֵ�1~26����Ϊ�ֵ�����ÿһ�������

        if(!p->next[index])  //������������ʱ����������
			p->next[index]=new TrieTree_Node;

		p=p->next[index];
    }

	if(p->flag)  //��ɫ�����Ѵ���
		return p->id;  //��������
	else   //���򴴽�����
	{
		p->flag=true;
		p->id=++color;
		return p->id;   //���ط��������ɫ�ı��
	}
}

int main(void)  
{
	/*Initial the Merge-Set*/

    for(int k=1;k<=large;k++)   //��ʼ����ÿ�������Ϊһ����������
		ancestor[k]=k;  //����ֻ��һ�����x�ļ��ϣ�x�����Ⱦ���������

	/*Input*/

	char a[11],b[11];
    while(cin>>a>>b)  
    {
		/*Creat the TrieTree*/

		int i=hash(a);
		int j=hash(b);  //�õ�a��b��ɫ�ı��

		/*Get all nodes' degree*/

        degree[i]++;
        degree[j]++;   //��¼a��b��ɫ���ֵĴ���(�ܶ���)

		/*Creat the Merge-Set*/

		union_set(i,j);
	}

	/*Judge the Euler-Path*/

	int s=find(1);  //��ͼΪ��ͨͼ����sΪ���н�������
	                    //��ͼΪ����ͨͼ��sΪ���������е�����һ������

	int num=0;  //����Ϊ�����Ľ�����

	for(int i=1;i<=color;i++)
	{
		if(degree[i]%2==1)
			num++;
				
		if(num>2)   //����Ϊ�����Ľ��������3��ŷ��·�ز�����
		{
			cout<<"Impossible"<<endl;
			return 0;
		}

		if(find(i)!=s)   //���ڶ�����ȣ�ͼΪɭ�֣�����ͨ
		{
			cout<<"Impossible"<<endl;
			return 0;
		}
	}

	if(num==1) //����Ϊ�����Ľ��������1��ŷ��·�ز�����
		cout<<"Impossible"<<endl;
	else       //����Ϊ�����Ľ����ǡ�õ���2�򲻴��ڣ�����ŷ��·
		cout<<"Possible"<<endl;
}