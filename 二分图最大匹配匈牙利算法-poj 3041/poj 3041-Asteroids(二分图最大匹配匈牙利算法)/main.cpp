/*Asteroids  ����ͼ���ƥ��������
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
//һ��С���ǣ�Ҫô������У�Ҫô���С�����Ҳ����ÿ��С���Ƕ�Ӧ������������ѡ��һ�����������潨ͼ��������ǰ�ÿ�п��ɼ���һ�еĵ㣬ÿ�п��ɼ��϶��еĵ㣬һ��С���ǿ��������Ӧ���е����ߣ���ôҲ����˵���ܴ���ĳһ���������ߵĵ㶼û�б�ѡ�е��������ǡ�þ��Ƕ���ͼ��С�㼯���ǵ�Ҫ��
//����·����P��ͼG��һ��·�����P�������������ڵı�һ����һ������M����һ��������M���ͳ�P��һ������·��
//������·�������˵㶼��δ�ǵ�Ľ���·����������·��
/*
bool Ѱ�Ҵ�k�����Ķ�Ӧ����Ŀ�����·
{
	while (���ڽӱ����о�k�ܹ���������j)
	{
		if (j��������·��)
		{
			��j��������·;
			if (j��δ�ǵ� ���� ��j�Ķ�Ӧ������п�����·)
			{
				�޸�j�Ķ�Ӧ��Ϊk;
				���k�Ķ�Ӧ����п�����·,����true;
			}
		}
	}
	���k�Ķ�Ӧ���û�п�����·,����false;
}
 
void ������hungary()
{
	for i->1 to n
	{
		if (���i�Ķ�Ӧ����п�����·)
			ƥ����++;
	}
	��� ƥ����;
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