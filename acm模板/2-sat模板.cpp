/*
 * File:   2-sat 模板
 * Author: xiaotian @ hnu
 * Created on 2010年10月11日, 上午9:52
 * 题解：2-sat问题求解
 * 建图：将每一个点拆成 p 和 p'（编号时 p'=p+n ）
 * 如果 ap 和 bp 矛盾，则添加边：(ap,bp'),(bp,ap').
 */
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<vector>
using namespace std;
#define N 1008 /*顶点总数，包括拆点以后的*/
#define inf 0x7ffffff
vector<int>g[N];  /*邻接表*/
int n, m;  /*顶点数，边数*/
int id[N], pre[N], low[N], s[N], stop, cnt, scnt;
void tarjan(int v, int n) { /*求强连通分量，vertex: 0 ~ n-1*/
    int t, minc = low[v] = pre[v] = cnt++;
    s[stop++] = v;
    for (int i = 0; i < g[v].size(); i++) {
        if (-1 == pre[g[v][i]]) tarjan(g[v][i], n);
        if (low[g[v][i]] < minc) minc = low[g[v][i]];
    }
    if (minc < low[v]) { low[v] = minc; return; }
    do { id[t = s[--stop]] = scnt; low[t] = n; } while (t != v);
    ++scnt; /*联通分量个数*/
}
bool _2sat() {
    stop = cnt = scnt = 0;
    memset(pre, -1, sizeof (pre));
    for (int i = 0; i < n; ++i) if (-1 == pre[i]) tarjan(i, n);
    n /= 2;
    for (int i = 0; i < n; i++) if (id[i] == id[i + n]) return 0;
    return 1;
}
void build() { /**/ }
int main() {
    while (scanf("%d%d", &n, &m) != EOF) {
        build();
        int ans = _2sat();
        if(ans){ /**/ }
        else{ /**/ }
    }
    return 0;
}