#include<iostream>
using namespace std;
int n,m,sum,maxs=0;
int a[100000];
bool ok(int v){
    int value=0,c=0;
    for(int i=0;i<n;i++){
         if(value+a[i]<=v) value+=a[i];
         else{
              value=a[i];
              c++;     
         }        
    } 
    if(c<=m) return true;
    return false;   
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){ 
        scanf("%d",&a[i]); 
        sum+=a[i]; 
        if(a[i]>maxs) maxs=a[i];
    }
    int left=maxs,right=sum,mid;
    while(left<right){
         mid=(left+right)/2;
         if(!ok(mid)) left=mid+1;
         else right=mid;                   
    }
    printf("%d\n",left);
    system("pause");
    return 0;
}
