#include <cstdio>
#include <cstring>
#define MAXN 200010
int kmp(char *A, char *B, int *next)
{
    int j = -1, ret = 0;
    for (int i = 0; A[i]; i++)
	{
        while (j != -1 && A[i] != B[j + 1]) j = next[j];
        if (A[i] == B[j + 1]) j++;
        if (!B[j + 1])
		{
            ret++;
            j = next[j];
        }
    }
    return ret;
}
void prekmp(char *B,int *next,int n)
{
	next[0]=-1;
	int i=0,j=-1;
	while(i<n)
    {
        while(j>=0 and B[i]!=B[j]) j=next[j];
        i++;
        next[i]=++j;
    }
}
int main()
{
	int cas,n;
	long long ans;
	char str[MAXN];
	int next[MAXN];
	scanf("%d",&cas);
	while(cas--)
	{
		scanf("%d",&n);
		scanf("%s",&str);
		ans=n;
		memset(next,0,sizeof(next));
		prekmp(str,next,n);
		for(int i=0;i<=n;i++)
        {
            if(next[i]+1!=next[i+1]) ans+=next[i];
        }
        printf("%d\n",ans%10007);
	}
}
