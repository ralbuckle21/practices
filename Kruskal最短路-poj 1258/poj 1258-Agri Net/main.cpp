/*Agri Net
Description Kruskal���·

Farmer John has been elected mayor of his town! One of his campaign promises was to bring internet connectivity to all farms in the area. He needs your help, of course. 
Farmer John ordered a high speed connection for his farm and is going to share his connectivity with the other farmers. To minimize cost, he wants to lay the minimum amount of optical fiber to connect his farm to all the other farms. 
Given a list of how much fiber it takes to connect each pair of farms, you must find the minimum amount of fiber needed to connect them all together. Each farm must connect to some other farm such that a packet can flow from any one farm to any other farm. 
The distance between any two farms will not exceed 100,000. 
Input

The input includes several cases. For each case, the first line contains the number of farms, N (3 <= N <= 100). The following lines contain the N x N conectivity matrix, where each element shows the distance from on farm to another. Logically, they are N lines of N space-separated integers. Physically, they are limited in length to 80 characters, so some lines continue onto others. Of course, the diagonal will be 0, since the distance from farm i to itself is not interesting for this problem.
Output

For each case, output a single integer length that is the sum of the minimum length of fiber required to connect the entire set of farms.
Sample Input

4
0 4 9 21
4 0 8 17
9 8 0 16
21 17 16 0
Sample Output

28
	*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include<iostream>
using namespace std;
#define N 1002
#define INF 999999
/*
Kruskal�㷨ֻ����й�
�㷨���̣�
1.��ͼ���߰���Ȩֵ��������
2.��ͼ����һ�Σ��ҳ�Ȩֵ��С�ıߣ����������˴��ҳ��ı߲��ܺ��Ѽ�����С���������ϵı߹��ɻ������������������������С�������ļ����С��������������������ͼ��Ѱ����һ����СȨֵ�ıߡ�
3.�ݹ��ظ�����1��ֱ���ҳ�n-1����Ϊֹ����ͼ��n����㣬����С�������ı���ӦΪn-1�������㷨�������õ��ľ��Ǵ�ͼ����С��������
*/
struct node {
    int u, v, w;
    node() {}
    node(int _u, int _v, int _w):u(_u), v(_v), w(_w) {}
};
vector<node> edge;
int n, m, f[N];
bool cmp(const node &x, const node &y) {
    return x.w < y.w;
}
int find_set(int x) {
    if (f[x] == x) return x;
    return f[x] = find_set(f[x]);
}

int Kruskal() {
    sort(edge.begin(), edge.end(), cmp);
    for (int i=1; i<=n; i++) f[i] = i;
    int ans = 0;
    for (int i=0, u, v, w; i<edge.size(); i++) {
        u = edge[i].u, v = edge[i].v, w = edge[i].w;
        u = find_set(u), v = find_set(v);
        if (u == v) continue;
        f[u] = v;
		printf("%d %d\n",u,v);
        ans+=w;
    }
    return ans;
}
int main() {
	int c;
	while(scanf("%d",&n)==1&&n!=0){
		edge.clear();
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cin>>c;
				if(c==-1) c=INF;
				if(i!=j) edge.push_back(node(i,j,c));
			}
		}
		printf("%d\n", Kruskal());
	}
}