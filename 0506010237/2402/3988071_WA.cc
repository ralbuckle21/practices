#include<iostream>
using namespace std;
__int64 f[21],w[21];
int v[51],len,n;
void init(){
    f[0]=0; f[1]=9; f[2]=9;
    w[0]=0; w[1]=10; w[2]=10;
    for(int i=3;i<=20;i++){
       f[i]=f[i-2]*10;
       w[i]=w[i-2]*10;
    }     
}
void find(int k,int s,int d){
    if(k==len){
         if(k>2){
             for(int i=1;i<=9;i++)
                 if(w[k-2]<n) n-=w[k-2];
                 else{ v[s]=v[d]=i; find(k-2,s+1,d-1); break; }
         }           
         else v[s]=v[d]=n;
    }     
    else{
         if(k>2){
             for(int i=0;i<=9;i++)
                 if(w[k-2]<n) n-=w[k-2];
                 else{ v[s]=v[d]=i; find(k-2,s+1,d-1); break; }
         }           
         else v[s]=v[d]=n-1;   
    }
}
int main(){
    init();
    while(scanf("%d",&n)!=EOF){
       len=1;
       while(f[len]<n){ n-=f[len]; len++;}
       find(len,0,len-1);
       for(int i=0;i<len;i++) cout<<v[i];cout<<endl;
    }
    system("pause");
    return 0;
}
