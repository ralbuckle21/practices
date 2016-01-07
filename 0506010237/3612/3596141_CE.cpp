#include <cstdio>
#define MAXN 110000
#define MAXH 101
int h[MAXN], bes[2][MAXH], ans, huge, bes1, c, n;
inline int sqr (int x){return x*x; }
int main (){
    int i, j, pre, cur;
  //  freopen ("telewire.in", "r", stdin);
  //freopen ("telewire.out", "w", stdout);
    huge = 2100000000;
    scanf ("%d%d", &n, &c);
    for (i = 0; i<n; i++)    scanf ("%d", &h[i]);
    for (i = 0; i<MAXH; i++)
        bes[0][i] = (i>= h[0]) ? sqr(h[0]-i) : huge;
    for (i = 1; i<n; i++){
        pre = (i+1)%2;
        cur = i%2;
        for (bes1 = huge, j = 0; j<MAXH; j++){
            bes1 <?= bes[pre][j]-j*c;
            bes[cur][j] = bes1+j*c;
        }
        for (bes1 = huge, j = MAXH-1; j>= 0; j--){
            bes1 <?= bes[pre][j]+j*c;
            bes[cur][j] <?= bes1-j*c;
        }
        for (j = 0; j<MAXH; j++)
            bes[cur][j] = (j>= h[i])? (bes[cur][j] + sqr(j-h[i])) : huge;
    }
    ans = huge;
    for (i = 0; i<MAXH; i++) ans<?= bes[cur][i];
    printf ("%d\n", ans);
    return 0;
}
