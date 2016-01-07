#include<string.h>
#include<stdio.h>
#define INF 1000000000;
#define MAX( x, y ) (x>y?x:y)
int f[50002][3];
int main()
{
    int x, i, ans, T, n;
    scanf( "%d", &T );
    while( T-- )
    {
        scanf( "%d", &n );
        for( i = 1; i <= n; i++ )
        {
            f[i][0] = f[i][1] = -INF;
        }    
        scanf( "%d", &x );
        f[1][0] = x;
        f[1][2] = x;
        for( i = 2; i <= n; i++ )
        {
            scanf( "%d", &x );
            f[i][0] = MAX( x, f[i-1][0]+x );   
            f[i][2] = MAX( f[i-1][2], f[i][0] );
            f[i][1] = MAX( f[i-1][2]+x, MAX( f[i-1][1]+x , f[i-1][0]+x ) );
        }
        ans = -INF;
        for( i = 1; i <= n; i++ )
        {
            ans = MAX( ans, f[i][1] );
        }
        printf( "%d\n", ans );
    }
    return 0;    
} 