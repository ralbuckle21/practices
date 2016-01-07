#include<iostream>
using namespace std;
long long h[100010];
long long s[100010];
int n;
void dp(){
    long long high=0,result=0;
    s[0]=0;
    for(int i=1;i<=n;i++){
         if(h[i]<high){
             s[i]=(s[i-1]/high+1)*h[i];
             high=h[i];
         }
         else{
             if(s[i-1]+high<h[i]){
                   high=h[i];
                   s[i]=h[i];                     
             }     
             else s[i]=s[i-1]+high;
         }    
         if(s[i]>result) result=s[i];
    }     
    printf("%d\n",result);
}
int main(){
    while(true){
         scanf("%d",&n);
         if(n==0) break;
         for(int i=1;i<=n;i++) scanf("%ld",&h[i]);
         dp();            
    }
    system("pause");
    return 0;
}
