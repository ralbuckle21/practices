#include <stdio.h>
#include <stdlib.h>
 
#define MAX 101
 
int map[MAX][MAX] = {0};
int sum;
 
void dfs(int i, int j)
{
    if (map[i][j] == 0) return;
    else if (map[i][j] == 1)
    {
        map[i][j] = 0;
        sum++;
        dfs(i + 1, j);
        dfs(i - 1, j);
        dfs(i, j + 1);
        dfs(i, j - 1);
    }
}
 
int main()
{
    int n, m, k, i, j, max;
    scanf("%d%d%d", &n, &m, &k);
    while(k--)
    {
        scanf("%d%d", &i, &j);
        map[i][j] = 1;
    }
    max = 0;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            if (map[i][j] == 1)
            {
                sum = 0;
                dfs(i, j);
            }
            if (sum > max) max = sum;
        }
    }
    printf("%d\n", max);
    getch(); 
    //system("pause");
    return 0;
}
