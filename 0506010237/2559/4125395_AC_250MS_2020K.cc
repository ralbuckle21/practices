#include<iostream>
using namespace std;
long long h[100010];
long long r[100010];
int n;
void dp(){
    long long result=0;
    long long k;
    memset(r,0,sizeof(r));
    for(int j=0;j<n;j++){
        r[j] = j;
        while(r[j]!=0 && h[int(r[j])-1]>=h[j])  r[j]=r[int(r[j])-1];//求出前驱 
    }
    for(int j=n-1;j>=0;j--){ //注意方向 
        k = j;
        while(k<n-1 && h[k+1]>=h[j]) k=r[k+1];
        if((k-r[j]+1)*h[j]>result ) result=(k-r[j]+1)*h[j]; //由后继减前驱相当于向2个方向扩展 
        r[j] = k; //变为后继 
    }
    cout<<result<<endl;
}
int main(){
    while(true){
         scanf("%d",&n);
         if(n==0) break;
         for(int i=0;i<n;i++) scanf("%ld",&h[i]);
         dp();            
    }
    system("pause");
    return 0;
}
