#include<iostream>
using namespace std;
int n,k,m;
int main(){
    int s;
    while(true){
         scanf("%d%d%d",&n,&k,&m);
         if(n==0) break; s=0; 
         for(int i=2;i<n;i++) s=(s+k)%i;//由于第一个人已知相当于是N-1个人的游戏 
         s=(s+m)%n; 
         printf("%d\n",s+1);            
    }
    system("pause");
    return 0;
}
