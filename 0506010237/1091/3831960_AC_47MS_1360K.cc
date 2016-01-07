/*   欧拉函数一般形式:  设n=p^k; 则phi(n)=p^k-p^(k-1)=(p-1)p^(k-1)
     当 n 为素数时: phi(n) = n-1
     当 n 为合数时: phi(n) = n∏(1-1/p) 其中(p为n的素数因子)
     求我们求 x1..xn,m这样的序列的个数，其中xi(1<=i<=n), 使 gcd(x1, ..,xn,m)=1;
     当 n 为素数时: phi(m,n) = m^n-1
     当 n 为合数时: phi(m,n) = m^n∏(1-1/p^n) 其中(p为n的素数因子)
*/
#include <iostream>
using namespace std;
typedef __int64 llong;
const llong MAXN = 110000;
llong tf[MAXN], su[MAXN], ns, num[MAXN], nn;
void  init() { //求出质数 
    llong i, j;
    for (i=2; i<MAXN; i++) {
        if (!tf[i]) {
            su[ns++]=i;
            for (j=i*i; j<MAXN; j+=i) tf[j]=1;
        }
    }
}
llong ppow(llong a, llong b) {
    llong ret=a;
    llong i;
    for (i=1; i<b; i++) ret *= a;
    return ret;
}

int main() {
    llong n, m, i, p;
    llong ans=0;
    init();
    while (scanf("%I64d%I64d", &n, &m)!=EOF) {
        p=m; nn=0; ans=0;
        for (i=0; i<ns; i++) {//整数因子分解 
            if (p%su[i]==0) {
                while (p%su[i]==0) p/=su[i];
                num[nn++]=su[i];
            }
            if (p==1) break;
        }
        if (!nn) {
            ans = ppow(m,n)-1;
        } else {
            ans = ppow(m,n);
            for (i=0; i<nn; i++) {
                ans = ans/ppow(num[i],n)*(ppow(num[i],n)-1);
            }
        }
        printf("%I64d\n", ans);
    }
    return 0;
}