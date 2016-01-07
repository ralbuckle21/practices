#include<iostream>
using namespace std;
int n,m;
bool win(int a,int b){
    if(a%b==0 || b%a==0) return true;
    if(a>b){
         int k=1;
         while(k*b<a){
            if(!win(a-k*b,b)) return true;
            k++;
         }        
    } 
    else{
         int k=1;
         while(k*a<b){
              if(!win(a,b-k*a)) return true;
              k++;
         }     
    }
    return false;
}
int main(){
    while(true){
         scanf("%d%d",&n,&m);
         if(n==0 && m==0) break;
         if(n!=0 && m!=0 && win(n,m)) cout<<"Stan wins"<<endl;
         else cout<<"Ollie wins"<<endl;
    }
    system("pause");
    return 0;
}
