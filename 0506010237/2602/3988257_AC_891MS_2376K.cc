#include<iostream>
using namespace std;
int n;
char x[1000001],y[1000000];
int main(){
    scanf("%d",&n);
    for(int i=n-1;i>=0;i--){
         x[i]=getchar();
         while(x[i]>'9' || x[i]<'0') x[i]=getchar();
         x[i]-='0';
         y[i]=getchar();
         while(y[i]>'9' || y[i]<'0') y[i]=getchar();
         y[i]-='0';
         x[i]+=y[i];
    }
    for(int i=0;i<n;i++){
         if(x[i]>=10){
             x[i]-=10;
             x[i+1]++;
         }       
    }       
    for(int i=n-1;i>=0;i--) printf("%d",x[i]); printf("\n");
    system("pause");
    return 0;
}
