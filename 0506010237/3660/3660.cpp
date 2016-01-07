#include <iostream>
using namespace std ;

const int MaxSize=100+2 ;
const int INF=0xffffff ;
int n, m, map[MaxSize][MaxSize] ;

void floyd()
{
    int i, j, k ;
    for( i=1; i<=n; ++i ){
        for( j=1; j<=n; ++j ){
            for( k=1; k<=n; ++k ){
                if( map[j][i]==1 && map[i][k]==1 ){
                    map[j][k] = 1 ;
                    map[k][j] = -1 ;
                }
                else if( map[j][i]==-1 && map[i][k]==-1 ){
                    map[j][k] = -1 ;
                    map[k][j] = 1 ;
                }
            }
        }
    }
}

void output()
{
    int i, j, ans=0 ;
    for( i=1; i<=n; ++i ){
        bool flag = true ;
        for( j=1; j<=n; ++j ){
            if( i == j )
                continue ;
            if( map[i][j]!=1 && map[i][j]!=-1 ){
                flag = false ;
                break ;
            }
        }
        if( flag )
            ++ans ;
    }
    printf("%d\n", ans ) ;
}

int main()
{
    freopen("in.txt", "r", stdin ) ;
    freopen("out.txt", "w", stdout ) ;
    
    scanf("%d%d", &n, &m ) ;
    int i, j, from, to ;
    for( i=0; i<=n; ++i ){
        for( j=i+1; j<=n; ++j )
            map[i][j] = map[j][i] = INF ;
        map[i][i] = 0 ;
    }
    for( i=1; i<=m; ++i ){
        scanf("%d%d", &from, &to ) ;
        // 1表示打败，-1表示被打败 
        map[from][to] = 1 ;
        map[to][from] = -1 ;
    }
    floyd() ;
    output() ;
    return 0 ;
}
