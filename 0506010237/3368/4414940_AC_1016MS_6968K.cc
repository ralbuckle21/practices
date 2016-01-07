#include <stdio.h>
#include <algorithm>
using namespace std;
int v[100000];
int n, m;
struct node{
	int l, r;
	int st, ed;
	int lmax, rmax, max;
}root[200000];
int cnt;
int next[100000], prev[100000];
int max(int a, int b){
	return a < b ? b : a;
}
int min(int a, int b){
	return a < b ? a : b;
}
void create(int no, int l, int r){
	int mid = (l + r) >> 1;
	root[no].st = l;root[no].ed = r;
	if(l == r){
		root[no].l = -1;
		root[no].r = -1;
		root[no].lmax = root[no].rmax = root[no].max = 1;
		return ;
	}
	int L, R;
	L = root[no].l = ++cnt;
	create(cnt, l, mid);
	R = root[no].r = ++cnt;
	create(cnt, mid + 1, r);
	root[no].lmax = min(next[l], r + 1) - l;
	root[no].rmax = r - max(l - 1, prev[r]);
	root[no].max = max(max(root[no].lmax, root[no].rmax), max(root[L].max, root[R].max));
	root[no].max = max(root[no].max, (root[L].rmax + root[R].lmax) * (v[mid] == v[mid + 1]));
}
int ans;
void find_ans(int no, int l, int r){
	if (root[no].st == l && root[no].ed == r){
		ans = max(ans, root[no].max);
		return ;
	}
	int mid = (root[no].st + root[no].ed) >> 1;
	if (l > mid) find_ans(root[no].r, l, r);
	else if (r <= mid) find_ans(root[no].l, l, r);
	else{
		 find_ans(root[no].l, l, mid);
	     find_ans(root[no].r, mid + 1, r);
	     if (v[mid] == v[mid + 1]){
		     int left = mid - max(prev[mid], l - 1);
			 int right = min(next[mid + 1] - 1, r) - mid;
			 ans = max(left + right, ans);
	     }
	}
}

int main(){
	int i, l, r, m;
	while (scanf("%d", &n) == 1, n){
		scanf("%d", &m);
		for (i = 0; i < n; scanf("%d", &v[i++]));
		next[n - 1] = n;
		for (i = n - 2; i >= 0; i--){
			if (v[i + 1] == v[i])	next[i] = next[i + 1];
			else next[i] = i + 1;
		}
		prev[0] = -1;
		for (i = 1; i < n; i++){
			if (v[i - 1] == v[i]) prev[i] = prev[i - 1];
			else prev[i] = i - 1;
		}
		create(cnt = 0, 0, n - 1);
		while (m--){
			scanf("%d%d", &l, &r);
			ans = 0;
			find_ans(0, l - 1, r - 1);
			printf("%d\n", ans);
		}
	}
	return 0;
}

