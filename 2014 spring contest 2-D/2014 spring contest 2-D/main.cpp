#include <cstdlib>
#include <stdio.h>
using namespace std;
long f(long a,long k,long M){
    long b=1;
    while(k>=1){
        if(k%2==1){
            b=a*b%M;
        }
        a=(a%M)*(a%M)%M;
        k/=2;
    }
    return b;
}
int main(int argc, char** argv) {
    int t,n,i,j;
    long a,b,M;
    long z,ans;
    scanf("%d",&t);
    while(t--){
        scanf("%ld",&M);
        scanf("%d",&n);
        ans=0;
        for(i=0;i<n;i++){
            scanf("%ld%ld",&a,&b);
            z=f(a,b,M);
            ans=(ans+z)%M;
        }
        printf("%ld\n",ans);
    }
}
