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
            used[v]=true;//����ֻȷ�������һ���������㲢����Ϊtrue
        }
        for(int i=n-1;i>=0;i--)
        {
            if(used[i]==false)
            {
                for(int j=i+1;j<=i+6;j++)dp[i]+=dp[j]/6;//�Ӻ���ǰ�滮 
                dp[i]+=1;
                used[i]=true;
            }
            for(int j=0;j<vec[i].size();j++)//���ﴦ��i�������յ����������i���������յ㣬vec[i].size()=0
            {
                v=vec[i][j];//�ҵ���Ӧ���������
                dp[v]=dp[i];
                used[v]=true;
				printf("i%d v%d ",i,v);
            }
        }
        printf("%.4lf\n",dp[0]);
    }
    return 0;
}