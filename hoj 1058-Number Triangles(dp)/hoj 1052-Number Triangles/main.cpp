#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int h;
	int **a;
	while(cin>>h)
	{
	a=(int**)malloc(sizeof(int)*h);
	for(int i=0;i<h;i++)
    {
        a[i]=(int*)malloc(sizeof(int)*h);
    }
	for(int i=0;i<h;i++)
		for(int j=0;j<=i;j++)
			cin>>a[i][j];
	if(h==1) cout<<a[0][0]<<endl;
	else
	{
		for(int i=h-2;i>=0;i--)//�ӵ����ڶ��㿪ʼ
		{
			for(int j=0;j<=i;j++)
				a[i][j]=max(a[i+1][j],a[i+1][j+1])+a[i][j];//����ݹ�ķ���
		}
		cout<<a[0][0]<<endl;
	}
	}
}