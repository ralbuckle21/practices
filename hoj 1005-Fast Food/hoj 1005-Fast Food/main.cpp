#include <stdio.h>
#include<algorithm>
#define inf 9999999
#define maxn 210
int food[maxn],dp[36][maxn],dis[maxn][maxn];
int  main()
{
    int  n,m,i,j,k,mid,minn,p=1;
    while(scanf("%d%d", &n, &m)&&n){
        for(i=1;i<=n;i++)
            scanf("%d",&food[i]);
		memset(dis,0,sizeof(dis));
        for(i=1;i<=n;i++){
            for(j=i;j<=n;j++){
                for(k=i;k<=j; k++)
                    dis[i][j]+=abs(food[k]-food[(i+j)/2]) ;
            }
        }
        for( i=1;i<=n; i++){
            dp[1][i]=dis[1][i];
        }
        for(i=2; i<=m; i++ ){
            for(j=i; j<=n; j++){
                dp[i][j] = inf ;
                for(k=i-1; k<j; k++ )
                    if(dp[i][j]>dp[i-1][k]+dis[k+1][j] )
                        dp[i][j]=dp[i-1][k]+dis[k+1][j] ;
            }
        }
        printf("Chain %d\nTotal distance sum = %d\n\n",p++, dp[m][n]);
    }
}