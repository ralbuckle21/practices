#include<iostream>
using namespace std;
long long a=0,b=0,c=0,n,pa,pb,pc;
long long d[10000];
int main(){
    cin>>pa>>pb>>pc>>n;
    d[0]=1;
    for(int i=1;i<=n;i++){
         if(d[a]*pa<=d[b]*pb){
             if(d[a]*pa<=d[c]*pc) d[i]=d[a]*pa;
             else d[i]=d[c]*pc;
         }
         else if(d[b]*pb<=d[c]*pc) d[i]=d[b]*pb; 
         else d[i]=d[c]*pc;
         if(d[a]*pa==d[i]) a++;
         if(d[b]*pb==d[i]) b++;
         if(d[c]*pc==d[i]) c++;      
    }
    cout<<d[n]<<endl;
    system("pause"); 
    return 0;
}
