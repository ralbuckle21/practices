#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const int NMAX = 100000;
const int LOGNMAX = 17 +1;
int sortseq[LOGNMAX][NMAX];
int num[NMAX];
struct node {
    int l,r,d;
    node * pl,* pr;
}mem[(NMAX<<1)+100];
int mempos,n,m;
node * root;
node * make_tree(int l,int r,int d) {
    node * rt = mem+(mempos ++);
    rt->l = l; rt->r = r; rt->d = d;
    if (l == r) {
        sortseq[d][l] = num[l];
        return rt;
    }
    int mid = (l+r) >> 1;
    rt->pl = make_tree(l,mid,d+1);
    rt->pr = make_tree(mid+1,r,d+1);
    int i=l,j=mid+1,k=l;
    while (i<=mid && j<=r) {
        if (sortseq[d+1][i] < sortseq[d+1][j]) sortseq[d][k++] = sortseq[d+1][i++];
        else sortseq[d][k++] = sortseq[d+1][j++];
    }
    while (i<=mid) sortseq[d][k++] = sortseq[d+1][i++];
    while (j<=r) sortseq[d][k++] = sortseq[d+1][j++];
    return rt;
}
int s,t,rank;
int query(node * rt,int val) {
    int i,mid,ret;
    if (s <= rt->l && rt->r <= t) {
        if (val <= sortseq[rt->d][rt->l]) return 0;
        else if (sortseq[rt->d][rt->r] < val) return rt->r - rt->l +1;
        else if (sortseq[rt->d][rt->r] == val) return rt->r - rt->l;
        int l = rt->l, r = rt->r, mid;
        while (l <= r) {
            mid = (l+r) >> 1;
            if (val <= sortseq[rt->d][mid]) r = mid-1;
            else l = mid+1;
        }
        return l - rt->l;
    }
    else {
        ret = 0;
        mid = (rt->l+rt->r) >> 1;
        if (s <= mid) ret += query(rt->pl,val);
        if (mid+1 <= t) ret += query(rt->pr,val);
        return ret;
    }
}
int get_val() {
    int ret = 0;
    char ch;
    bool dot = false,neg = false;
    while (((ch=getchar()) > '9' || ch < '0') && ch != '-') ;
    if (ch == '-') {
        neg = true;
        ch = getchar();
    }
    do {
        ret = ret*10 + (ch-'0');
    } while ((ch=getchar()) <= '9' && ch >= '0') ;
    return (neg? -ret : ret);
}int main() {
    int i,j,l,r;
    n = get_val(); m = get_val();
    for (i=0;i<n;i++) num[i] = get_val();
    mempos = 0;
    root = make_tree(0,n-1,0);
    while (m --) {
        s = get_val()-1; t = get_val()-1; rank = get_val()-1;
        l = 0, r = n-1;
        while (l <= r) {
            int mid = (l+r) >> 1;
            int pos = query(root,sortseq[0][mid]);
            if (rank < pos) r = mid-1;
            else l = mid+1;
        }
        printf("%d\n",sortseq[0][r]);
    }
}
