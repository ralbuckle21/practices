#include<iostream>
using namespace std;
int a[22];
int n;
void solve(){
    for(int i=1;i<n;i++) a[0]=a[0]^a[i];
    if(a[0]!=0) printf("Yes\n");
    else printf("No\n");     
}
int main(){
    while(scanf("%d",&n)!=EOF){
         for(int i=0;i<n;i++) scanf("%d",&a[i]);
         solve();            
    }
    system("pause");
    return 0;
}
