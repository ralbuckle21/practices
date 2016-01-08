/*Anniversary party  树形dp
	Description

There is going to be a party to celebrate the 80-th Anniversary of the Ural State University. The University has a hierarchical structure of employees. It means that the supervisor relation forms a tree rooted at the rector V. E. Tretyakov. In order to make the party funny for every one, the rector does not want both an employee and his or her immediate supervisor to be present. The personnel office has evaluated conviviality of each employee, so everyone has some number (rating) attached to him or her. Your task is to make a list of guests with the maximal possible sum of guests' conviviality ratings.
Input

Employees are numbered from 1 to N. A first line of input contains a number N. 1 <= N <= 6 000. Each of the subsequent N lines contains the conviviality rating of the corresponding employee. Conviviality rating is an integer number in a range from -128 to 127. After that go N – 1 lines that describe a supervisor relation tree. Each line of the tree specification has the form: 
L K 
It means that the K-th employee is an immediate supervisor of the L-th employee. Input is ended with the line 
0 0 
Output

Output should contain the maximal sum of guests' ratings.
Sample Input

7
1
1
1
1
1
1
1
1 3
2 3
6 4
7 4
4 5
3 5
0 0
Sample Output

5
	*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int father[6005],vis[6005],dp[6005][2],t;
//dp[x][0]代表不选x时x所在子树最大值  dp[x][1]代表选x时x所在子树最大值
void dfs(int node)
{
    int i,j;
    vis[node] = 1;
    for(i = 1;i<=t;i++){
       if(!vis[i] && father[i] == node){
           dfs(i);
           dp[node][1]+=dp[i][0];//node去,则i必不能去
           dp[node][0]+=max(dp[i][0],dp[i][1]);//node不去，取i去或不去的最大值
       }
    }
}

int main()
{
    int i,j,l,k,root;
    while(scanf("%d",&t)&&t>0){
        for(i = 1;i<=t;i++)
        scanf("%d",&dp[i][1]);
        root = 0;
        while(scanf("%d%d",&l,&k),l+k>0){
            father[l] = k;//记录上司
            root = k;
        }
        memset(vis,0,sizeof(vis));
        dfs(root);//从根节点开始dfs
        printf("%d\n",max(dp[root][1],dp[root][0]));
    }
}
