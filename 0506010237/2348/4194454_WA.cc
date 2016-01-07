#include<iostream>
using namespace std;
int n,m,cnt;
void swap(int &a,int &b){
    int temp=a; a=b; b=temp;     
}
void win(int a,int b){
    if(a==b) return;
    if(a<b) swap(a,b);
    if(a/b>=2) return;
    cnt++;
    win(a-b,b);
}
int main(){
    while(true){
         cin>>n>>m;
         if(n==0 && m==0) break;
         cnt=0;
         win(n,m);
         if(n!=0 && m!=0 && !cnt%2) cout<<"Stan wins"<<endl;
         else cout<<"Ollie wins"<<endl;
    }
    system("pause");
    return 0;
}
