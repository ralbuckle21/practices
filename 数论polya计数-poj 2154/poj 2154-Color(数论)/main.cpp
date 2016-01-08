/*Color  polya����
	Beads of N colors are connected together into a circular necklace of N beads (N<=1000000000). Your job is to calculate how many different kinds of the necklace can be produced. You should know that the necklace might not use up all the N colors, and the repetitions that are produced by rotation around the center of the circular necklace are all neglected. 

You only need to output the answer module a given number P. 
Input

The first line of the input is an integer X (X <= 3500) representing the number of test cases. The following X lines each contains two numbers N and P (1 <= N <= 1000000000, 1 <= P <= 30000), representing a test case.
Output

For each test case, output one line containing the answer.
Sample Input

5
1 30000
2 30000
3 30000
4 30000
5 30000
Sample Output

1
3
11
70
629
��ĿҪ�󣺸�����������n��p������n�����ӣ�n����ɫ��Ҫ��ͬ�������������Խ��mod��p������

�û�ֻ����תһ�ַ�ʽ����ô����n���û�
����֪ʶ�����ĸ���Ϊgcd(n , i) , ����L=n / gcd(n , i)   ���� i Ϊת��λ����
��ͨ��: ��n^( gcd(n,i) )  0<=i<n  ���Ӷȹ���
�Ż�:ö�ٻ��ĳ���L
ö���Ż�: L���Դ�1ȡ��sqrt(n) ,��ΪL|n , n/L | n
����ÿ��L,�����ٿ��м���i��������
n/L = gcd(n , i) 
��ô�� a=n/L = gcd(n , i) , ����i = at
��ô���ҽ���gcd(L,t)=1ʱ�򣬲���gcd(n,i) = a
��Ȼ����������i�ĸ�������t�ĸ���Ҳ����phi(L)
��ô���ͳ��һ�¾��� ��(phi(L) * N^(L-1) ) % p  (L��ö��ֵ) 
*/
#include<iostream>
#include <stdlib.h>
#include <algorithm>
#include <stdio.h>
#include<vector>
using namespace std;
const int MAXN=1000000000;
int isprime[50001];
int prime[8001];
int num,n,p;
void getprime()//����������
{
	num=0;
	for(int i=2;i<=50000;i++)if(!isprime[i])
	{
		prime[num++]=i;
		for(int j=1;j*i<=50000;j++)
		{
			isprime[i*j]=1;
		}
	}
}
int euler(int x)
{//ŷ������
	int res=x;
	for(int i=0;i<num&&prime[i]*prime[i]<=x;i++)
	{
		if(x%prime[i]==0)
		{
			res=res/prime[i]*(prime[i]-1);
			while(x%prime[i]==0)
			{
				x/=prime[i];
			}
		}
	}
	if(x>1) res=res/x*(x-1);
	return res;
}
int expmod(int a,int b,int mod)
{
    int ret=1;
    a=a%mod;
    while(b>0)
    {
        if(b&1)ret=(ret*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return ret;
}

int main()
{
	int Case;
	getprime();
	scanf("%d",&Case);
	while(Case--)
	{
		scanf("%d%d",&n,&p);
		int ans=0,i;
		for(i=1;i*i<n;i++)
			if(n%i==0){
				ans=(ans+euler(i)%p*expmod(n,n/i-1,p)+euler(n/i)%p*expmod(n,i-1,p))%p;;//�����i-1�����Ѿ����������û���n�ˣ�ԭ����expmod(n,i)�����Ҫ����n�ģ�
			}
		if(i*i==n)
			ans=(ans+euler(i)*expmod(n,i-1,p))%p;
		cout<<ans<<endl;
	}
}