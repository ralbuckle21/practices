//dijkstra本质：按路径长度递增依次产生最短路径
/*
1.初始化所有结点并将起始点设为标记，进入以下循环
2.在到达某点的最短路径中找最小且未标记的点（可以用一维数组表示）
3.标记找到的点，以此标记点为中间点重新计算所有未标记点的最短路径（更新最短路径表）
4.循环1.2步至n-1次（n为顶点数，若最后还有未被标记的，说明无法到达此点）
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
#define N 105
#define inf 0x3f3f3f3f
//模板下标从1开始
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
            mi = d[j], k = j;//找最小未标记
        if (k == 0) break;
        vis[k] = true;//标记点
        for (int j=0, v, w; j<g[k].size(); j++) {
            v = g[k][j].v, w = g[k][j].w;
            if (!vis[v] && d[v] > d[k] + w)
                d[v] = d[k] + w;//更新所有未标记点的最短路径
        }
    }
    return d[t];
}
int main() {
	scanf("%d",&n);
	for(int i=0;i<=n;i++) g[i].clear();
	for(int i=1;i<=n;i++){
        for(int j=1;j<=i-1;j++){
              char ch[20];
              scanf("%s",ch);
              if(ch[0]!='x'){
				  int temp=atoi(ch);
				  g[i].push_back(node(j,temp));
				  g[j].push_back(node(i,temp));
			  }
        }
    }
	int res=0;
	for(int i=2;i<=n;i++){
          res=max(res,Dijkstra(1,i));
      }
      printf("%d\n",res) ;
}
