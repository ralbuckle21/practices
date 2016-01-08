//dijkstra���ʣ���·�����ȵ������β������·��
/*
1.��ʼ�����н�㲢����ʼ����Ϊ��ǣ���������ѭ��
2.�ڵ���ĳ������·��������С��δ��ǵĵ㣨������һά�����ʾ��
3.����ҵ��ĵ㣬�Դ˱�ǵ�Ϊ�м�����¼�������δ��ǵ�����·�����������·����
4.ѭ��1.2����n-1�Σ�nΪ���������������δ����ǵģ�˵���޷�����˵㣩
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
#define N 105
#define inf 0x3f3f3f3f
//ģ���±��1��ʼ
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
            mi = d[j], k = j;//����Сδ���
        if (k == 0) break;
        vis[k] = true;//��ǵ�
        for (int j=0, v, w; j<g[k].size(); j++) {
            v = g[k][j].v, w = g[k][j].w;
            if (!vis[v] && d[v] > d[k] + w)
                d[v] = d[k] + w;//��������δ��ǵ�����·��
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
