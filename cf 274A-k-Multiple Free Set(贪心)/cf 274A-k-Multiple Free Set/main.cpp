#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	long long n,k;
	cin>>n>>k;
	long long *a=new long long[n];
	bool *visited=new bool[n];
	long long *chain=new long long[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	    visited[i]=false;//��ʼ��
		chain[i]=1;//ע��chain��ʼ��Ϊ1
	}
	sort(a,a+n);//���򷽱�����
	for(int i=0;i<n;i++)
	{
		if(visited[i]==false)
		{
			long long temp=a[i];
			while(1)
			{
			    int left=0,right=n-1,mid;
			    while(left!=right)//������ֵ����temp*k�Ľڵ�
			    {
				    mid=(left+right)/2;
					if(a[mid]==temp*k)
					{
						left=mid;
						break;
					}
                    else if(a[mid]<temp*k)
					    left=mid+1;
					else
					    right=mid;
			    }
			    if(a[left]==temp*k&&k!=1)
			    {
				    visited[left]=true;//left��������һ���ڵ�
				    chain[i]++;
				    chain[left]--;
				    temp=temp*k;
			    }
				else
					break;
			    visited[i]=true;
			}
		}
	}
	long long count=0;
	for(long long i=0;i<n;i++)
		count+=(chain[i]+1)/2;//һ��������5���㣬�Ϳ���������������������
	cout<<count;
}