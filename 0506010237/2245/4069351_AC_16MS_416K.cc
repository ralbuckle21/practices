#include<iostream>
using namespace std;
int a[15],b[7],n,t=0,r=6;
bool nextrcom(){
     int i=r;
     while(b[i]==n-r+i) i=i-1;
     if(i==0) return false; 
     b[i]=b[i]+1;
     for(int j=i+1;j<=r;j++) b[j]=b[i]+j-i;
     for(i=1;i<=r;i++) printf("%d ",a[b[i]]); printf("\n");
     return true;
}
int main(){
    while(true){
         scanf("%d",&n); 
         if(n==0) break;
         if(t!=0) printf("\n");
         else t++;
         for(int i=1;i<=n;i++) scanf("%d",&a[i]);
         for(int i=1;i<=r;i++){ b[i]=i; printf("%d ",a[b[i]]); }
         printf("\n");
         while(nextrcom());
    }
    system("pause");
    return 0;
}
