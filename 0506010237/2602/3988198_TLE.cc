#include<iostream>
using namespace std;
int a[1000010];
int n,x[1000000],y[1000000],c=0;
int main(){
    scanf("%d",&n);
    for(int i=n-1;i>=0;i--) scanf("%d%d",&x[i],&y[i]);
    for(int i=0;i<n;i++){
         a[i]=x[i]+y[i]+c;
         c=a[i]/10;
         a[i]=a[i]%10;       
    }       
    for(int i=n-1;i>=0;i--) printf("%d",a[i]); printf("\n");
    system("pause");
    return 0;
}
