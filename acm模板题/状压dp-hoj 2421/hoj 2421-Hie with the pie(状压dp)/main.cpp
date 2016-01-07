/*hie with the pie状压dp
	The Pizazz Pizzeria prides itself in delivering pizzas to its customers as fast as possible. Unfortunately, due to cutbacks, they can afford to hire only one driver to do the deliveries. He will wait for 1 or more (up to 10) orders to be processed before he starts any deliveries. Needless to say, he would like to take the shortest route in delivering these goodies and returning to the pizzeria, even if it means passing the same location(s) or the pizzeria more than once on the way. He has commissioned you to write a program to help him. 

Input 

Input will consist of multiple test cases. The first line will contain a single integer n indicating the number of orders to deliver, where 1 ≤ n ≤ 10. After this will be n+1 lines each containing n+1 integers indicating the times to travel between the pizzeria (numbered 0) and the n locations (numbers 1 to n). The jth value on the ith line indicates the time to go directly from location i to location j without visiting any other locations along the way. Note that there may be quicker ways to go from i to j via other locations, due to different speed limits, traffic lights, etc. Also, the time values may not be symmetric, i.e., the time to go directly from location i to j may not be the same as the time to go directly from location j to i. An input value of n = 0 will terminate input. 

Output 

For each test case, you should output a single number indicating the minimum time to deliver all of the pizzas and return to the pizzeria. 

Sample Input 


3
0 1 10 10
1 0 1 2
10 1 0 10
10 2 10 0
0

Sample Output 


8


	*/
#include<iostream>
using namespace std;
#define inf 99999999
#define maxn 1<<11+1
int dp[11][maxn],d[11][11];
int n,ans;
void cal_dis(){
	for(int i = 0;i <= n;i++)   
           for(int j=0;j<=n;j++)   
                for(int k=0;k<=n;k++)   
                    if(d[j][k]>d[j][i] + d[i][k])   
                        d[j][k] = d[j][i] +d[i][k];
}
void solve(){
	for (int j=0;j<(1<<n);j++)  //枚举所有状态，用位运算表示
              for (int i=1;i<=n;i++)  
                  if (j==(1<<(i-1))) dp[i][j]=d[0][i];  //状态S只经过城市I，最优解自然是从0出发到i的dis,这也是DP的边界  
                  else   //如果S有经过多个城市
                       if (j&(1<<(i-1))) {
                                     dp[i][j] =inf;  
                                     for (int k=1;k<=n;k++)  
                                         if ((k!=i) && (j&(1<<(k-1))))  //枚举不是城市I的其他城市,寻找更合适的中间点
                                            dp[i][j]=min(dp[i][j],dp[k][j^(1<<(i-1))]+d[k][i]);  
                       }  
          ans =inf;  
          for (int i=1;i<=n;i++)  
              ans = min(ans, dp[i][(1<<n)-1]+d[i][0]);  
          printf("%d\n",ans);  
}  
int main()
{
	while(scanf("%d",&n) &&n>0){
		for (int i=0;i<=n;i++)  
              for (int j=0;j<=n;j++){
                  if (i==j) d[i][j]=0;  
                  else d[i][j]=inf;
			  }
		for(int i=0;i<=n;i++)
			for(int j=0;j<=n;j++)
				scanf("%d",&d[i][j]);
		cal_dis();
		solve();
	}
}