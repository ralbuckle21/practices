#include<iostream>
using namespace std;
int n,len=2,a=1,b=1;
long c[10000010];
void getv(){
     for(;len<=n;len++){
          if(c[a]*2<c[b]*3) c[len]=c[a]*2+1;
          else c[len]=c[b]*3+1;
          if(c[a]*2+1==c[len]) a++;
          if(c[b]*3+1==c[len]) b++;         
     }     
}
int main(){
    c[1]=1; 
    while(scanf("%d",&n)!=EOF){
         getv();    
         cout<<c[n]<<endl;                       
    }
    system("pause");
    return 0;
}
