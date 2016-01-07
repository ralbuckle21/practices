/*
 * File:   2-sat ģ��
 * Author: xiaotian @ hnu
 * Created on 2010��10��11��, ����9:52
 * ��⣺2-sat�������
 * ��ͼ����ÿһ������ p �� p'�����ʱ p'=p+n ��
 * ��� ap �� bp ì�ܣ�����ӱߣ�(ap,bp'),(bp,ap').
 */
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<vector>
using namespace std;
#define N 1008 /*������������������Ժ��*/
#define inf 0x7ffffff
vector<int>g[N];  /*�ڽӱ�*/
int n, m;  /*������������*/
int id[N], pre[N], low[N], s[N], stop, cnt, scnt;
void tarjan(int v, int n) { /*��ǿ��ͨ������vertex: 0 ~ n-1*/
    int t, minc = low[v] = pre[v] = cnt++;
    s[stop++] = v;
    for (int i = 0; i < g[v].size(); i++) {
        if (-1 == pre[g[v][i]]) tarjan(g[v][i], n);
        if (low[g[v][i]] < minc) minc = low[g[v][i]];
    }
    if (minc < low[v]) { low[v] = minc; return; }
    do { id[t = s[--stop]] = scnt; low[t] = n; } while (t != v);
    ++scnt; /*��ͨ��������*/
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