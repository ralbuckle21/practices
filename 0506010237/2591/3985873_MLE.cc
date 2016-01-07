#include<iostream>
using namespace std;
int n,a=1,b=1;
long long c[10000001];
int main(){
    c[1]=1; 
    for(int len=2;len<=10000000;len++){
          if(c[a]*2<c[b]*3) c[len]=c[a]*2+1;
          else c[len]=c[b]*3+1;
          if(c[a]*2+1==c[len]) a++;
          if(c[b]*3+1==c[len]) b++;         
    }  
    while(scanf("%d",&n)!=EOF){    
         cout<<c[n]<<endl;                       
    }
    system("pause");
    return 0;
}
