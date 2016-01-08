/*Color  polya计数
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
题目要求：给出两个整数n和p，代表n个珠子，n种颜色，要求不同的项链数，并对结果mod（p）处理。

置换只有旋转一种方式，那么共有n个置换
基本知识：环的个数为gcd(n , i) , 长度L=n / gcd(n , i)   其中 i 为转的位子数
普通求法: ∑n^( gcd(n,i) )  0<=i<n  复杂度过高
优化:枚举环的长度L
枚举优化: L可以从1取到sqrt(n) ,因为L|n , n/L | n
对于每个L,我们再看有几个i满足条件
n/L = gcd(n , i) 
那么令 a=n/L = gcd(n , i) , 再设i = at
那么当且仅当gcd(L,t)=1时候，才有gcd(n,i) = a
显然满足条件的i的个数就是t的个数也就是phi(L)
那么最后统计一下就是 ∑(phi(L) * N^(L-1) ) % p  (L即枚举值) 
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
void getprime()//构建质数表
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
{//欧拉函数
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
				ans=(ans+euler(i)%p*expmod(n,n/i-1,p)+euler(n/i)%p*expmod(n,i-1,p))%p;;//这里的i-1代表已经除以整个置换数n了，原本是expmod(n,i)，最后要除以n的，
			}
		if(i*i==n)
			ans=(ans+euler(i)*expmod(n,i-1,p))%p;
		cout<<ans<<endl;
	}
}