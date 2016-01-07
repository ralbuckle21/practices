#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#define N 110
#define inf 1000000000

struct node
{
    int price;
    int rank;
}goods[N];
int g[N][N];

int dijkstra(int v, int n, int limit, int max)
{
    int i, j, min, minid, k, sum=inf;
    int dis[N], mark[N];

    for(i=1; i<=n; i++)
    {
        mark[i] = 0;
        dis[i] = g[v][i];

        /*去掉那些不能用的点*/
        if((goods[i].rank > max) || (max-goods[i].rank > limit))  
            mark[i] = 1;
    }

    mark[v] = 1;
    
    for(i=1; i<n; i++)
    {
        min = inf;
        minid = 0;

        for(j=1; j<=n; j++)
        {
            if(!mark[j] && dis[j] < min)
            {
                min = dis[j];
                minid = j;
            }
        }
        if(!minid)
            break;
        mark[minid] = 1;

        if(minid == 1)
        {
            sum = dis[1];
            break;
        }
        for(j=1; j<=n; j++)
        {
            if(!mark[j] && (min+g[minid][j] < dis[j]))
            {
                dis[j] = min + g[minid][j];
            }
        }
    }
    return sum;
}

int cmp(const void *p, const void *q)
{
    return *(int *)p > *(int *)q ? -1 : 1;
}

int main()
{
    int i, j, k;
    int gonum, n, x, limit, r, result, ranklist[N];

    freopen("in.txt", "r", stdin);
    scanf("%d%d", &limit, &gonum);

    for(i=1; i<=gonum+1; i++)
        for(j=1; j<=gonum+1; j++)
            g[i][j] = inf;
    for(i=1; i<=gonum; i++)        
    {
        scanf("%d%d%d", &goods[i].price, &goods[i].rank, &n);
        ranklist[i] = goods[i].rank;
        for(j=1; j<=n; j++)
        {
            scanf("%d", &x);
            scanf("%d", &g[x][i]);
        }
    }
    qsort(ranklist, gonum+1, sizeof(ranklist[1]), cmp);
    for(i=1; i<=gonum; i++)
        g[gonum+1][i] = goods[i].price;
    goods[gonum+1].rank = goods[1].rank;
    result = goods[1].price;

/*枚举每个不相同rank，作为最高等级*/
    for(i=0; i<gonum+1; i++)
    {
        r = dijkstra(gonum+1, gonum+1, limit, ranklist[i]);
        if(r < result)
            result = r;
        while(ranklist[i+1] == ranklist[i] && i<gonum+1)
            i++;
    }
    printf("%d\n", result);
    getch();
    return 0;
}
