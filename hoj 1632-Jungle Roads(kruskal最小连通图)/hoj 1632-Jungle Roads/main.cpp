#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include<iostream>
using namespace std;
#define N 1002
struct node {
    int u,v,w;
    node() {}
    node(int _u, int _v, int _w):u(_u), v(_v), w(_w) {}
};
vector<node> edge;
int n, m, f[N];
bool vis[N];
bool cmp(const node &x, const node &y) {
    return x.w < y.w;
}
int find_set(int x) {
    if (f[x] == x) return x;
    return f[x] = find_set(f[x]);
}
int Kruskal() {
	memset(vis,false,sizeof(vis));
    sort(edge.begin(), edge.end(), cmp);
    for (int i=1; i<=n; i++) f[i] = i;
    int ans = 0,cnt=0;
    for (int i=0, u, v, w; i<edge.size(); i++) {
        u = edge[i].u, v = edge[i].v, w = edge[i].w;
        u = find_set(u), v = find_set(v);
        if (u == v) continue;
        f[u] = v;
		if(vis[u]==false){
			vis[u]==true;
			cnt++;
		}
        ans += w;
    }
    return ans;
}
int main(){
	char a,b;
	int c,num;
    while(scanf("%d",&n)==1&&n!=0){
		edge.clear();
		for(int i=1;i<n;i++){
			cin>>a>>num;
			while(num--){
			    cin>>b>>c;
				edge.push_back(node((int)(a-'A')+1,(int)(b-'A')+1,c));
			}
		}
		printf("%d\n", Kruskal());
    }
}
