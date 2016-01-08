#include<cstdio>
#include<cstring>
int w,h;
long long dp[12][1<<12];
int lowbit(int a)
{
	return a&(-a);
}
void swap(int a,int b)
{
	 int t=a;
	 a=b;
	 b=t;
}
bool ok(int t)
{
    t=t+(1<<w);
    int c=0;
    while(c<w)
    {
        int lb=lowbit(t);
        int w=0;
        while(lb!=0)
            w++,c++,lb>>=1;
        if (w%2==0)
            return 0;
        t>>=w;
    }
    return 1;
}
void cal()
{
	if(w%2&&h%2) 
	{
		printf("0\n");
		return;
	}
    dp[0][0]=1;
	for(int i=1;i<=h;i++)
	{
	    for(int j=0;j<(1<<w);j++)
		{
			dp[i][j]=0;
			for(int k=0;k<(1<<w);k++)
			{
	            if(!(j&k)&&ok(j|k)) 
					dp[i][j]+=dp[i-1][k];
			}
		}
	}
	printf("%lld\n",dp[h][0]);
}
int main()
{
	while(scanf("%d %d",&h,&w)!=EOF)
	{
		if(h==0||w==0) break;
		if(h<w) swap(h,w);
		memset(dp,0,sizeof(dp));
		cal();
	}
}