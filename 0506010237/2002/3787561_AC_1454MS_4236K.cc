#include <stdio.h>
#include <stdlib.h>
#include <math.h>
const int LEN = 1005;
typedef struct
{
    int x;
    int y;
}type;
type p[LEN];
int cmp ( const void *a, const void *b ){
    type *c = ( type * )a;
    type *d = ( type * )b;
    int ans = c->x - d->x;
    if ( ! ans ) ans = c->y - d->y;
    return ans;
}
int hash[LEN][LEN];
void inith ( int n ){
    for ( int i=0; i<n; i++ )
        for ( int j=0; j<n; j++ )
            hash[i][j] = 0;
}
int ser ( type *a, type *b, int n ) /**//*二分查找函数*/{
    int c;
    int l, r, mid;
    l = 0;r = n-1;
    while ( l <= r ){
        mid = ( l + r ) / 2;
        if ( cmp ( a, &p[mid] ) >= 0 ) l = mid + 1;
        else r = mid - 1;
    }
    if ( r<0 || cmp ( a, &p[r] ) ) return -1;
    c = r;  
    l = 0;r = n-1;
    while ( l <= r ){
        mid = ( l + r ) / 2;
        if ( cmp ( b, &p[mid] ) >= 0 ) l = mid + 1;
        else  r = mid - 1;
    }
    if ( r<0 || cmp ( b, &p[r] ) )return -1;
    return c;
}
int check ( int s, type *a, type *b, int n ){
    type c, d;
    int disx, disy;
    int k = ( a->x - b->x ) * ( a->y - b->y );
    disx = abs (a->x - b->x);
    disy = abs (a->y - b->y);
    /*if ( k > 0 ){
        c.x = a->x - disy;
        c.y = a->y + disx;
        d.x = b->x - disy;
        d.y = b->y + disx;
    }*/
    if(k<=0){
        c.x = a->x + disy;
        c.y = a->y + disx;
        d.x = b->x + disy;
        d.y = b->y + disx;
    }
    else c.x=a->x-1;
    if ( a->x >= c.x ) return 0;
    int ans = ser ( &c, &d, n);
    if ( ans == -1 )  return 0;
    else{
        hash[s][ans] = 1;
        return 1;
    }
}
int main ()
{
    int n;
    int count;
    while ( scanf ( "%d", &n ) != EOF && n ){
        for ( int i=0; i<n; i++ ) scanf ( "%d%d", &p[i].x, &p[i].y );
        qsort ( p, n, sizeof ( type ), cmp );
        count = 0;
        inith ( n );
        for (int i=0; i<n; i++ )
            for ( int j=i+1; j<n; j++ )
                //if (!hash[i][j])
                    count +=check(i,&p[i],&p[j],n);
        printf ( "%d\n", count );
    }
    return 0;
}
