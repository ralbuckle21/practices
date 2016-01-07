#include <cstdio>
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
const int maxn = 55555;
int sum[maxn<<2];
int MAX[maxn<<2];
void PushUP(int rt) {
	sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}
void build(int l,int r,int rt) {
	if (l == r) {
		scanf("%d",&sum[rt]);
		return ;
	}
	//MAX[rt] = w;MAX的build
	int m = (l + r) >> 1;
	build(lson);
	build(rson);
	PushUP(rt);
}
void update(int p,int add,int l,int r,int rt) {//单点增减
	if (l == r) {
		sum[rt] += add;
		return ;
	}
	int m = (l + r) >> 1;
	if (p <= m) update(p , add , lson);
	else update(p , add , rson);
	PushUP(rt);
}
int query(int L,int R,int l,int r,int rt) {//区间求和
	if (L <= l && r <= R) {
		return sum[rt];
	}
	int m = (l + r) >> 1;
	int ret = 0;
	if (L <= m) ret += query(L , R , lson);
	if (R > m) ret += query(L , R , rson);
	return ret;
}
void update(int p,int sc,int l,int r,int rt) {//单点替换
	if (l == r) {
		MAX[rt] = sc;
		return ;
	}
	int m = (l + r) >> 1;
	if (p <= m) update(p , sc , lson);
	else update(p , sc , rson);
	PushUP(rt);
}
int query(int L,int R,int l,int r,int rt) {//区间最值，输入，输入，1，n，1
	if (L <= l && r <= R) {
		return MAX[rt];
	}
	int m = (l + r) >> 1;
	int ret = 0;
	if (L <= m) ret = max(ret , query(L , R , lson));
	if (R > m) ret = max(ret , query(L , R , rson));
	return ret;
}

