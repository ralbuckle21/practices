#include<iostream>
using namespace std;
#define MAX 100010
int N,c[MAX];
int lowbit(int i)
{
    return i&(-i);
}

void modify(int i,int delta)
{
    while( i<=N)
    {
        c[i]+=delta;
        i+=lowbit(i);
	}
}//i´Ó1¿ªÊ¼
int sum(int i)
{
	int ret=0;
	while(i>0)
	{
		ret+=c[i];
		i-=lowbit(i);
	}
	return ret;
}
int main()
{
	N=9;
	for(int i=1;i<10;i++)
	{
		modify(i,3*i);
	}
	for(int i=1;i<10;i++)
	{
	    cout<<c[i]<<" ";
	}
	cout<<sum(5);
}