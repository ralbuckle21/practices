#include<iostream>
using namespace std;
int n,x[1000000],y[1000000],c=0;
int main(){
    scanf("%d",&n);
    for(int i=n-1;i>=0;i--) scanf("%d%d",&x[i],&y[i]);
    for(int i=0;i<n;i++){
         x[i]+=y[i]+c;
         if(x[i]>=10){
             x[i]-=10;
             c=1;             
         }
         else c=0;       
    }       
    for(int i=n-1;i>=0;i--) printf("%d",x[i]); printf("\n");
    system("pause");
    return 0;
}
