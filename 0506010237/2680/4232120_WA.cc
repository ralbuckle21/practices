#include<iostream>
using namespace std;
int f[1005][1800];
int len[1005];
int n;
void mul(int k){
    int c=0; len[k]=len[k-1];
    for(int i=0;i<len[k];i++){
         f[k][i]=f[k-1][i]*2+c;
         c=f[k][i]/10;
         f[k][i]=f[k][i]%10;        
    }     
    if(c>0) f[k][len[k]++]=c;
}
void dec(int k){
    f[k][0]--;
    int i=0;
    while(f[k][i]<0){
        f[k][i]+=10;
        f[k][i+1] -= 1;  
        i++;      
    }
    if(f[k][len[k]-1]==0) len[k]--;  
}
void add(int k){
     f[k][0]++;
     int i=0;
     while(f[k][i]>9){
          f[k][i]-=10;
          f[k][i+1]+=1;
          i++;                 
     }     
     if(f[k][len[k]]>0) len[k]++;
}
void init(){
    f[1][0]=0; 
    f[2][0]=1; len[2]=1;
    for(int i=3;i<=1000;i++){
        mul(i);
        if(i%2==1) dec(i);
        else add(i);
    }      
}
void print(int k){
    for(int i=len[k]-1;i>=0;i--) printf("%d",f[k][i]);  
    printf("\n");   
}
int main(){
    init();
    while(scanf("%d",&n)!=EOF) print(n);
    system("pause");
    return 0;
}
