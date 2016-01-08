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
vector<node> g[N],p[N];
int n, m, d[N],z[N],ans;
bool vis[N];
int Dijkstra(int s, int t) {
    memset(d, 0x3f, sizeof(d));
    memset(vis, false, sizeof(vis));
	memset(z,0,sizeof(z));
    d[s]=0;
    for (int i=0; i<n; i++) {
        int k = 0, mi = inf;
        for (int j=1; j<=n; j++) 
			if(!vis[j]&& d[j]<mi){
				mi=d[j];
				k=j;
			}
        if(k==0) break;
        vis[k]=true;
        for (int j=0,v,w,vi,wi;j<g[k].size();j++) {
            v = g[k][j].v,w=g[k][j].w;
			vi=p[k][j].v;
			wi=p[k][j].w;
            if(!vis[v]&&d[v]>d[k]+w){
                d[v]=d[k]+w;
				z[v]=z[k]+wi;
			}
			else if(!vis[v]&&d[v]==d[k]+w){
				if(z[v]>z[k]+wi) z[v]=z[k]+wi;
			}
        }
    }
	ans=z[t];
	printf("%d %d\n",d[t],ans);
    return d[t];
}
int main() {
    while (scanf("%d%d",&n, &m) == 2&&n!=0) {
        for (int i=0; i<=n; i++) g[i].clear();
		for (int i=0; i<=n; i++) p[i].clear();
		ans=0;
        for (int i=0, a, b, c,d; i<m; i++) {
            scanf("%d%d%d%d", &a, &b, &c,&d);
            g[a].push_back(node(b,c));
            g[b].push_back(node(a,c));
			p[a].push_back(node(b,d));
			p[b].push_back(node(a,d));
        }
        int s,t;
        scanf("%d%d",&s,&t);
        //printf("%d %d\n",Dijkstra(s,t),ans);
		Dijkstra(s,t);
	}
}
*/
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
int n, m,t, d[N];
int cnt=0;
bool vis[N],c[N];
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
            if (!vis[v] && d[v] >= d[k] + w)
                d[v] = d[k] + w;
        }
    }
    return d[t];
}
int main() {
	int t1,ans=inf;
    while (scanf("%d",&n)==1&&n!=0){
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
		printf("%d\n",cnt);
	}
}
