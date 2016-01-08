#include <cstdio>
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
int n, m, d[N];
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
    if(d[t]!=inf) return d[t];
	else return -1;
}
int main() {
	int s,t;
    while (scanf("%d",&n)==1&&n!=0) {
		scanf("%d%d",&s,&t);
        for (int i=0;i<=n; i++) g[i].clear();
        for (int i=1,a;i<=n;i++){
            scanf("%d",&a);
			if(a+i<=n){
			    g[a+i].push_back(node(i,1));
				g[i].push_back(node(a+i,1));
			}
			if(i-a>0){
				g[i-a].push_back(node(i,1));
				g[i].push_back(node(i-a,1));
			}
        }
        printf("%d\n",Dijkstra(s,t));
    }
}
