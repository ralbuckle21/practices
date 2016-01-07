#include<iostream>
using namespace std;
const int base=100000;
const int maxs=12500000;
struct{
     int cnt;
     int v;       
}hash[base];
int a[5];
int num[101];
__int64 r=0;
int abv(int x){ return x>=0?x:-x; }
void insert(int x){
    int key=x%base;
    while(hash[key].v!=0){
        if(hash[key].v==x){ hash[key].cnt++; return;}
        key=(key+1)%base;
    }
    hash[key].v=x;
    hash[key].cnt=1;
}
void find(int x){
   int key=x%base;
   while(hash[key].v!=0){
         if(hash[key].v==x)
              r+=hash[key].cnt;
         key=(key+1)%base;                      
   }
}
void getr(){
    for(int i=-50;i<=50;i++)
          if(i!=0)
          for(int j=-50;j<=50;j++)
               if(j!=0)
               for(int k=-50;k<=50;k++){  
                     if(k==0) continue;      
                     int sum=a[0]*num[i+50]+a[1]*num[j+50]+a[2]*num[k+50];
                     if(sum<-12500000) continue;
                     if(sum> 12500000) continue;
                     find(maxs-sum);
               }     
}
int main(){
    for(int i=-50;i<=50;i++) num[i+50]=i*i*i;
    for(int i=0;i<5;i++){ scanf("%d",&a[i]); a[i]=abv(a[i]); }
    for(int i=-50;i<=50;i++){
          if(i==0) continue;
          for(int j=-50;j<=50;j++){
               if(j==0) continue; 
               int sum=a[3]*num[i+50]+a[4]*num[j+50];
               insert(sum+maxs);            
          }
    }
    getr();
    cout<<r<<endl;
    system("pause");
    return 0;
}
