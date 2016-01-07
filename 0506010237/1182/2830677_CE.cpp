#include <memory.h>
#include <stdio.h>
const int MAXN =  50010;
int v[3*MAXN];
int n, k;
int FIND(int x)
{
    if ( x!=v[x] )
        v[x] = FIND(v[x]);
    return v[x];
}
int next(int x)//找后继
{
    return (x+n)%(3*n);
}
int prev(int x)//找前驱。
{
    return (x+2*n)%(3*n);
}
int same(int x, int y)
{
    int a = FIND(x);
    int b = FIND(y);
    if ((a%n)==(b%n))
    {
        if((a!=b))
          return 1;
        else
          return 0;
    }
    v[b] = a;
    v[prev(b)] = prev(a);
    v[next(b)] = next(a);
    return 0;
}
int kill(int x, int y)
{
    int a = FIND(next(x));
    int b = FIND(y);
    if ((a%n)==(b%n))
    {
        if(a!=b)
          return 1; 
        else
          return 0;
    }
    a = FIND(x);//把它合到ROOT三角行上
    v[b] = next(a);
    v[prev(b)] = a;
    v[next(b)] = prev(a);
    return 0;
}
int main()
{
    scanf("%d %d", &n, &k);
    int i;
    int d, x, y;
    int res = 0;
    for(i = 0; i < 3*n; i++)
            v[i] = i;//前0~n-1是自身，后n~2*n-1是next, //2*n~3*n是pre;
    for(i = 0; i < k; i++)
    {
        scanf("%d %d %d", &d, &x, &y);
        x--; y--;
        if ( x>=n||y>=n )
        {
            res++;
            continue;
        }
        if ( d==1 )
        { 
            if(x==y)
               continue; 
            res += same(x, y);
        }
        else 
        {
            if(x==y)
            {
                  res++;
                  continue;
            }     
            res += kill(x, y);
        }
    }
    printf("%d\n", res);
    system("pause");
    return 0;
}
