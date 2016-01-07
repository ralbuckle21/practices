#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include<iostream>
#include<math.h>
using namespace std;
#define N 1002
struct node {
    int u,v;
	double w;
    node() {}
    node(int _u, int _v, double _w):u(_u), v(_v), w(_w) {}
};
vector<node> edge;
int n, m, f[N];
int cx[52],cy[52],vx[52],vy[52];
bool vis[N];
bool cmp(const node &x, const node &y) {
    return x.w < y.w;
}
int find_set(int x) {
    if (f[x] == x) return x;
    return f[x] = find_set(f[x]);
}
double dis(int xa,int ya,int xb,int yb){
	return sqrt((xa-xb)*(xa-xb)+(ya-yb)*(ya-yb));
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
	int a,b;
	while(scanf("%d %d",&a,&b)&&a!=0){
		for(int i=0;i<a;i++)
			scanf("%d",&cx[i]);
		for(int i=0;i<a;i++)
			scanf("%d",&cy[i]);
		for(int i=0;i<b;i++)
			scanf("%d",&vx[i]);
		for(int i=0;i<b;i++)
			scanf("%d",&vy[i]);
		for(int i=0;i<a;i++)
			for(int j=0;j<b;j++)
				edge.push_back(node(i,a+j,dis(cx[i],cy[i],vx[j],vy[j])));
		for(int i=0;i<b;i++)
			for(int j=0;j<b;j++){
				if(i!=j)
					edge.push_back(node(a+i,a+j,dis(vx[i],vy[i],vx[j],vy[j])));
			}
	}
	/*char a,b;
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
    }*/
}
