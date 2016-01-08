#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,l,h) for(int i=(l);i<=(h);++i)
#define FORD(i,h,l) for(int i=(h);i>=(l);--i)

#define lson l,m,rt<<1
#define rson m+1,r,rt<<1 | 1

#define N 500010

int tree[N<<2];
const int antiprime[]={1,2,4,6,12,24,36,48,60,120,180,240,360,720,840,
1260,1680,2520,5040,7560,10080,15120,20160,25200,27720,
45360,50400,55440,83160,110880,166320,221760,277200,
332640,498960,554400,665280};//反素数
const int factorNum[]={1,2,3,4,6,8,9,10,12,16,18,20,24,30,32,36,40,48,60,64,72,80,84,
90,96,100,108,120,128,144,160,168,180,192,200,216,224};//反素数所对应的约数个数
struct child
{
	char name[15];
	int val;
}c[N];
void build(int l,int r,int rt)
{
	tree[rt]=r-l+1;
	if(l==r)	return;
	int m=(l+r)>>1;
	build(lson);
	build(rson);
}
int update(int p,int l,int r,int rt)
{
	tree[rt]--;
	if(l==r)	return l;
	int m=(l+r)>>1;
	if(p<=tree[rt<<1])	return update(p,lson);
	return update(p-tree[rt<<1],rson);
}
int main(void)
{
	int n,k,&mod=tree[1];
	while(scanf("%d%d",&n,&k)==2)
	{
		FOR(i,1,n)	scanf("%s%d",c[i].name,&c[i].val);
		build(1,n,1);//很长跪的初始化
		int cnt=0;
		while(cnt<35 && antiprime[cnt]<=n)	cnt++;
		cnt--;//找到反素数
		int pos=0;
		c[pos].val=0;
		REP(i,antiprime[cnt])
		{
			if(c[pos].val>0)	k=((k+c[pos].val-2)%mod+mod)%mod+1;
			else	k=((k+c[pos].val-1)%mod+mod)%mod+1;
			pos=update(k,1,n,1);
		}
		printf("%s %d\n",c[pos].name,factorNum[cnt]);
	}
	return 0;
}