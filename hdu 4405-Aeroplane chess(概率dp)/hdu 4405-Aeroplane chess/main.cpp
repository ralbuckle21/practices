#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
using namespace std;
const int MAXN=100010;
double dp[MAXN];
vector<int>vec[MAXN];
bool used[MAXN];
int main()
{
    int n,m;
    int u,v;
    while(scanf("%d%d",&n,&m))
    {
        if(n==0&&m==0)break;
        for(int i=0;i<=n;i++)vec[i].clear();
        memset(dp,0,sizeof(dp));
        while(m--)
        {
            scanf("%d%d",&u,&v);
            vec[v].push_back(u);
        }
        memset(used,false,sizeof(used));
        for(int i=0;i<vec[n].size();i++)
        {
            v=vec[n][i];
            dp[v]=0;
            used[v]=true;//这里只确定出最后一个跳板的起点并设置为true
        }
        for(int i=n-1;i>=0;i--)
        {
            if(used[i]==false)
            {
                for(int j=i+1;j<=i+6;j++)dp[i]+=dp[j]/6;//从后向前规划 
                dp[i]+=1;
                used[i]=true;
            }
            for(int j=0;j<vec[i].size();j++)//这里处理当i是跳板终点的情况，如果i不是跳板终点，vec[i].size()=0
            {
                v=vec[i][j];//找到对应的跳板起点
                dp[v]=dp[i];
                used[v]=true;
				printf("i%d v%d ",i,v);
            }
        }
        printf("%.4lf\n",dp[0]);
    }
    return 0;
}