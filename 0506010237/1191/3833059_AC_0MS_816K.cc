#include <iostream>
#include <cmath>
using namespace std; 
const int maxint = 2000000000;
# define N 8
double ans;
int map[ N+1 ][ N+1 ], n;
int sum[ N+1 ][ N+1 ];
int f[16][ N+1 ][ N+1 ][ N+1 ][ N+1 ];
void init(){
     for (int i = 1; i <= N; i ++)
         for (int j = 1; j <= N; j++)
             scanf("%d", &map[i][j]);
}
void output(){  printf("%.3lf\n", ans); }
int cal_sum(int x1, int y1, int x2, int y2){
     int tmp = sum[x2][y2]+sum[x1-1][y1-1] - sum[x1-1][y2]-sum[x2][y1-1];
     return tmp*tmp;
}
void dp(){
     memset(sum, 0, sizeof(sum));
     int tmp;
     sum[0][0] = 0;
     for (int i = 1; i <= N; i ++)
         for (int j = 1; j <= N; j ++)
             sum[i][j] = sum[i][j-1]+sum[i-1][j] - sum[i-1][j-1] + map[i][j];
     memset(f, 0, sizeof(f));
     for(int x1 = 1; x1 <= N; x1 ++)
         for (int y1 = 1; y1 <= N; y1 ++)
             for (int x2 = x1; x2 <= N; x2 ++)
                 for (int y2 = y1; y2 <= N; y2 ++)
                     f[1][x1][y1][x2][y2] = cal_sum(x1, y1, x2, y2);
     for (int k = 2; k <= n; k ++)
         for (int x1 = 1; x1 <= N; x1 ++)
             for (int y1 = 1; y1 <= N; y1 ++)
                 for (int x2 = x1; x2 <= N; x2 ++)       
                     for (int y2 = y1; y2 <= N; y2 ++){ 
                         f[k][x1][y1][x2][y2] = maxint;
                         for (int x = x1; x < x2; x ++){
                             tmp = min(f[k-1][x1][y1][x][y2] + cal_sum(x+1, y1, x2, y2), 
                                        f[k-1][x+1][y1][x2][y2] + cal_sum(x1, y1, x, y2)); 
                             if (f[k][x1][y1][x2][y2] > tmp) f[k][x1][y1][x2][y2] = tmp;
                         }
                         for (int y = y1; y < y2; y ++){
                             tmp = min( f[k-1][x1][y1][x2][y] + cal_sum(x1, y+1, x2, y2), 
                                        f[k-1][x1][y+1][x2][y2] + cal_sum(x1, y1, x2, y) ); 
                             if (f[k][x1][y1][x2][y2] > tmp) f[k][x1][y1][x2][y2] = tmp;
                         }
                     }
     ans = sqrt( f[n][1][1][N][N]/(double)n - sum[N][N]*sum[N][N]/(double)(n*n));
}
int main()
{
     while (scanf("%d", &n) != EOF){
         init();
         dp();
         output();
     }
     return 0;
}
