#include<iostream>
using namespace std;
int a[1000011];
int n;
int main(){
    int x=0,c=0;
    scanf("%d",&n);
    for(int i=n-1;i>=0;i--){
         scanf("%d%d",&a[i],&x);
         a[i]+=x;   
    }
    for(int i=0;i<n;i++){
         a[i]+=c;
         if(a[i]>9){ c=1; a[i]-=10; }
         else c=0;       
    }
    while(c) a[n++]=c;
    for(int i=n-1;i>=0;i--) printf("%d",a[i]);
    printf("\n");
    system("pause");
    return 0;
}
