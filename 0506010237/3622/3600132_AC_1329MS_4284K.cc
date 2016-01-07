#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
vector < pair <int,int> > c,f;
set < pair <int,int> > a;
int main () {
    int n, m, i, q, w;
    scanf("%d %d",&n,&m);
    for (i=0; i<n; i++) {
       scanf ("%d %d",&q,&w);
       c.push_back(make_pair(w,q));
    }
    for (i=0; i<m; i++) {
        scanf("%d %d",&q,&w);
        f.push_back(make_pair(w,q));
    }
    sort (c.begin(),c.end());
    sort (f.begin(),f.end());
    int r = m - 1;
    long long ans = 0;
    a.clear();
    for(i=n-1;i>=0;i--){
        while(r>=0 && f[r].first >= c[i].first){
                a.insert(make_pair(f[r].second,r));
                r--;
        }
        set<pair<int,int> >::iterator d=a.lower_bound(make_pair(c[i].second,-1));
        if(d == a.end()){
            printf("-1\n");
            system("pause");
            return 0;
        }
        ans +=  (*d).first;
        a.erase(d);
    }
    cout<<ans<<endl;
    system("pause");
    return 0;
}

