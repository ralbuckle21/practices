#include <iostream>
#define INF 10000000
using namespace std;
struct In{
   int r,c;
}man[110],house[110];
const int maxn = 202;
int S, T;
int graph[maxn][maxn],flow[maxn][maxn],cost[maxn][maxn];
int pre[maxn],dist[maxn];
int EK(){
    int i, j, k, ans;
    bool quit;
    ans = 0;
    while(1){
        for (i = 0; i <= T; i++) dist[i] = INF;
        dist[S] = 0;
        quit=false;
        while(!quit){//Bellman_Ford找增广路径 
            quit = true;
            for (i = 0; i < T; i++)
              for (j = 1; j <= T;j++)
                if (flow[i][j] < graph[i][j] && dist[i] + cost[i][j] < dist[j]){
                    dist[j] = dist[i] + cost[i][j];
                    pre[j] = i; quit = false;
                }
        }
        if(dist[T] == INF) break;//已经没有增广路径了 
        int Min = INF;
        j = T; 
        while(j != S){//找出最小增量 
           i = pre[j];
           if(graph[i][j] - flow[i][j] < Min) Min = graph[i][j] - flow[i][j];
           j = i;
        }    
        j = T;
        while (j!=S){//增广 
            i = pre[j];
            flow[i][j] += Min;
            flow[j][i] = -flow[i][j];
            j = i;
        }
        ans += Min * dist[T];
    } //while       
    return ans;
}
int main ()
{
    int m,n,a,b,i,j;
    char s[110];
    while (1){
        scanf ("%d%d",&m,&n);
        if (m+n==0) break;
        a=0,b=0;
        for (i=0;i<m;i++){
            scanf ("%s",s);
            for (j=0;j<n;j++){
               if(s[j]=='m'){man[a].r=i,man[a++].c=j;}
               if (s[j]=='H') house[b].r=i,house[b++].c=j;
            }
        }
        n=a*2+1;
        for (i=0;i<=n;i++)
            for (j=0;j<=n;j++)
                 graph[i][j]=0,cost[i][j]=0,flow[i][j] = 0;
        for (i=1;i<=a;i++) graph[0][i]=1;
        for (i=a+1;i<n;i++) graph[i][n]=1;
        for (i=1;i<=a;i++)
            for (j=a+1;j<n;j++){
                graph[i][j]=1;
                cost[i][j]=abs(man[i-1].r-house[j-a-1].r)+abs(man[i-1].c-house[j-a-1].c);
                cost[j][i]=-cost[i][j];
             }
        S=0,T=n;
        printf("%d\n",EK());
    }
    system("pause");
}
