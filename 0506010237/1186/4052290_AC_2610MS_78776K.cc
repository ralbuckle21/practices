#include<iostream>
#include<math.h>
using namespace std;
const int base=10000000;
struct{
    int u;
    int c;   
}hash[base];
struct{
    int p;
    int k;     
}x[7];
int n,m,h,result;
int pows(int a,int b){
    int sum=1;
    for(int i=1;i<=b;i++) sum=sum*a;
    return sum;     
}
void insert(int v){
    int key=v; while(key<0) key+=base;
    if(key>=base) key=key%base;
    while(hash[key].c!=0){
         if(hash[key].u==v){ hash[key].c++; return; }
         key=(key+1)%base;            
    }     
    hash[key].c=1; hash[key].u=v;
}
int search(int v){
    int key=v; while(key<0) key+=base;
    if(key>=base) key=key%base;
    while(hash[key].c!=0){
         if(hash[key].u==v) return hash[key].c;
         key=(key+1)%base;                      
    }
    return 0;
}
void dfs(int k,int y){
    if(k==h){
          insert(y);
          return;         
    }
    for(int i=1;i<=m;i++) dfs(k+1,y+x[k].k*pows(i,x[k].p));        
}
void dfs1(int k,int y){
    if(k==n){
          result+=search(-y);
          return;   
    }
    for(int i=1;i<=m;i++) dfs1(k+1,y+x[k].k*pows(i,x[k].p));     
}
void solve(){
     memset(hash,0,sizeof(h));
    h=n/2; result=0;
    dfs(0,0); 
    dfs1(h,0);    
    printf("%d\n",result);
}
int main(){
    int a,b;
    while(scanf("%d",&n)!=EOF){
         scanf("%d",&m);
         for(int i=0;i<n;i++){
              scanf("%d%d",&a,&b);
              x[i].k=a; x[i].p=b;        
         }  
         if(n==1){
               if(x[0].k==0) result=m;
               else result=0;
               printf("%d\n",result);       
         }
         else solve();                         
    }
    system("pause");
    return 0;
}
