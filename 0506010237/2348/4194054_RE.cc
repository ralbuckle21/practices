#include<iostream>
using namespace std;
long long n,m;
bool win(long long a,long long b){
     if(a==0 || b==0) return false;
    if(a%b==0 || b%a==0) return true;
    if(a>b){
         long long k=1;
         while(k*b<=a){
            if(!win(a-k*b,b)) return true;
            k++;
         }        
    } 
    else{
         long long k=1;
         while(k*a<=b){
              if(!win(a,b-k*a)) return true;
              k++;
         }     
    }
    return false;
}
int main(){
    while(true){
         cin>>n>>m;
         if(n==0 && m==0) break;
         if(win(n,m)) cout<<"Stan wins"<<endl;
         else cout<<"Ollie wins"<<endl;
    }
    system("pause");
    return 0;
}
