#include<iostream>
using namespace std;
int p[65][30];
int len[65];
long long n;
void mul(int k){
    int r=0;
    len[k]=len[k-1];
    for(int i=0;i<len[k];i++){
         p[k][i]=p[k-1][i]*3+r;
         r=p[k][i]/10;
         p[k][i]=p[k][i]%10;        
    }     
    if(r) p[k][len[k]++]=r;
}
void init(){
   p[0][0]=1; len[0]=1;
   for(int i=1;i<65;i++) mul(i);     
}
void print(int k){
    for(int i=len[k]-1;i>=0;i--)  
    printf("%d",p[k][i]);   
}
int main(){
    int k,x;
    init();
    while(true){
        cin>>n;
        if(n==0) break;
        if(n==1)printf("{ }\n");
        else{
           n--;
           x=-1;
           printf("{ ");
           while(true){
                k=n%2; x++; n=n>>1;
                if(k){ print(x); break;}            
           }
           while(n!=0){
               k=n%2; x++; n=n>>1;  
               if(k){ printf(", "); print(x); }          
           }
           printf(" }\n");
        }            
    }
    system("pause");
    return 0;
}
