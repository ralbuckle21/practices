/*Asteroids  二分图最大匹配匈牙利
	Description

Bessie wants to navigate her spaceship through a dangerous asteroid field in the shape of an N x N grid (1 <= N <= 500). The grid contains K asteroids (1 <= K <= 10,000), which are conveniently located at the lattice points of the grid.

Fortunately, Bessie has a powerful weapon that can vaporize all the asteroids in any given row or column of the grid with a single shot.This weapon is quite expensive, so she wishes to use it sparingly.Given the location of all the asteroids in the field, find the minimum number of shots Bessie needs to fire to eliminate all of the asteroids.
Input

* Line 1: Two integers N and K, separated by a single space. 
* Lines 2..K+1: Each line contains two space-separated integers R and C (1 <= R, C <= N) denoting the row and column coordinates of an asteroid, respectively.
Output

* Line 1: The integer representing the minimum number of times Bessie must shoot.
Sample Input

3 4
1 1
1 3
2 2
3 2
Sample Output

2
Hint

INPUT DETAILS: 
The following diagram represents the data, where "X" is an asteroid and "." is empty space: 
X.X 
.X. 
.X. 

OUTPUT DETAILS: 
Bessie may fire across row 1 to destroy the asteroids at (1,1) and (1,3), and then she may fire down column 2 to destroy the asteroids at (2,2) and (3,2).
	*/
#include <stdio.h>
#include<iostream>
using namespace std;
#define maxn 501
//一个小行星，要么清理该行，要么该列。所以也就是每个小行星对应的行列中至少选择一样来清理。下面建图，如果我们把每行看成集合一中的点，每列看成集合二中的点，一个小行星看成是其对应行列的连线，那么也就是说不能存在某一条连线两边的点都没有被选中的情况。这恰好就是二分图最小点集覆盖的要求。
//交错路：设P是图G的一条路，如果P的任意两条相邻的边一定是一条属于M而另一条不属于M，就称P是一条交错路。
//可增广路：两个端点都是未盖点的交错路叫做可增广路。
/*
bool 寻找从k出发的对应项出的可增广路
{
	while (从邻接表中列举k能关联到顶点j)
	{
		if (j不在增广路上)
		{
			把j加入增广路;
			if (j是未盖点 或者 从j的对应项出发有可增广路)
			{
				修改j的对应项为k;
				则从k的对应项出有可增广路,返回true;
			}
		}
	}
	则从k的对应项出没有可增广路,返回false;
}
 
void 匈牙利hungary()
{
	for i->1 to n
	{
		if (则从i的对应项出有可增广路)
			匹配数++;
	}
	输出 匹配数;
}
*/
struct Edge{
    int v;
};
int n, k, map[maxn][maxn];
int vis[maxn], connect[maxn];
void input()
{
    int i;
    for (i =0; i < k; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        a--;
        b--;
        map[a][b] =1;
    }
}

int work(int a)
{
    int i;
    for (i =0; i < n; i++)
        if (map[a][i] &&!vis[i])
        {
            vis[i] =1;
            if (connect[i] ==-1|| work(connect[i]))
            {
                connect[i] = a;
                return 1;
            }
        }
    return 0;
}
int main()
{
    scanf("%d%d", &n, &k);
    input();
    int i;
    memset(connect, -1, sizeof(connect));
    for (i =0; i < n; i++)
    {
        memset(vis, 0, sizeof(vis));
        work(i);
    }
    int ans =0;
    for (i =0; i < n; i++)
        if (connect[i] !=-1)
            ans++;
    printf("%d", ans);
}