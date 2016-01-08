/*#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
#define N 1002
#define inf 0x3f3f3f3f
struct node {
    int v, w;
    node() {}
    node(int _v, int _w):v(_v), w(_w) {}
};
vector<node> g[N];
int n, m,t, d[N];
int cnt;
bool vis[N];
int Dijkstra(int s, int t) {
    memset(d, 0x3f, sizeof(d));
    memset(vis, false, sizeof(vis));
    d[s] = 0;
    for (int i=0; i<n; i++) {
        int k = 0, mi = inf;
        for (int j=1; j<=n; j++) if (!vis[j] && d[j] < mi)
            mi = d[j], k = j;
        if (k == 0) break;
        vis[k] = true;
        for (int j=0, v, w; j<g[k].size(); j++) {
            v = g[k][j].v, w = g[k][j].w;
            if (!vis[v] && d[v] > d[k] + w)
                d[v] = d[k] + w;
        }
    }
    return d[t];
}
int main() {
	int t1,ans=inf;
    while (scanf("%d%d%d",&n,&m,&t)==3&&n!=0){
        for (int i=0; i<=n; i++) g[i].clear();
        for (int i=0, a, b, c; i<n; i++) {
            scanf("%d%d%d",&a,&b,&c);
            g[a+1].push_back(node(b+1,c));
            g[b+1].push_back(node(a+1,c));
        }
		while(m--){
			scanf("%d",&t1);
			g[t1+1].push_back(node(1,0));
			g[1].push_back(node(t1+1,0));
		}
		while(t--){
			scanf("%d",&t1);
			if(ans>Dijkstra(1,t1+1)) ans=Dijkstra(1,t1+1);
		}
        printf("%d\n",ans);
	}
}
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
#define N 105
#define inf 0x3f3f3f3f
struct node {
    int v, w;
    node() {}
    node(int _v, int _w):v(_v), w(_w) {}
};
vector<node> g[N];
int n, m,t, d[N];
int cnt=0;
bool vis[N],c[N][N];
int Dijkstra(int s, int t) {
    memset(d, 0x3f, sizeof(d));
    memset(vis, false, sizeof(vis));
	memset(c, false, sizeof(c));
    d[s] = 0;
    for (int i=0; i<n; i++) {
        int k = 0, mi = inf;
        for (int j=1; j<=n; j++) if (!vis[j] && d[j] < mi)
            mi = d[j], k = j;
        if (k == 0) break;
        vis[k] = true;
        for (int j=0, v, w; j<g[k].size(); j++) {
            v = g[k][j].v, w = g[k][j].w;
            if (!vis[v] && d[v] >= d[k] + w){
                d[v]=d[k]+w;
				c[v][k]=true;
				c[v][v]=true;
				for(int x=1;x<=n;x++){
					c[v][x]=c[v][x]||c[k][x];
				}
				//printf("%d %d %d\n",v,k,w);
			}
        }
    }
    return d[t];
}
int main() {
	int t1,ans=inf;
    while (scanf("%d",&n)==1&&n!=0){
		if(n==1){
			printf("1\n");
			continue;
		}
		cnt=0;
        for (int i=0;i<=n;i++) g[i].clear();
		int t;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				scanf("%d",&t);
				if(t>0){
					g[i].push_back(node(j,t));
					g[j].push_back(node(i,t));
				}
			}
		}
		ans=Dijkstra(1,n);
		for(int i=1;i<=n;i++){
			//printf("%d ",c[n][i]);
			cnt+=c[n][i];
		}
		printf("%d\n",cnt);
	}
}
