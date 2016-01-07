#include<iostream>
#include<math.h>
using namespace std;
int n;
int parent[11],child[1000][11],result[1000],lens[1000],c=0;
int len1,len2;
int maxs(int a,int b){
     return a>b?a:b;   
}
bool cmpxy(){
    int j=len2-1;
    for(int i=len1-1;i>=0;i--){
        if(parent[i]==child[c][j]) j--;
        if(j<0) return true;        
    }    
    return false;
}
void output(){
       printf("%d\n",c);
       for(int i=0;i<c;i++){
             printf("%d + ",result[i]);
             for(int j=lens[i]-1;j>=0;j--) printf("%d",child[i][j]);
             printf(" = %d\n",n); 
       }   
}
int main()
{
    scanf("%d",&n);
    int h=n,t=0;
    while(h){
        h=h/10;
        t++;         
    }
    h=n-pow(10,t)/10;
    if(h>n/2) h=n/2;
    for(int i=maxs(h,10);i<=n;i++){
        len1=0,len2=0;
        int x=i,y=n-x;
        while(x){
            parent[len1++]=x%10;
            x=x/10;
        }
        while(y){
            child[c][len2++]=y%10;
            y=y/10;
        }
        if(len1==len2) continue;
        while(len2+1<len1) child[c][len2++]=0;
        if(cmpxy()){ 
             result[c]=i;
             lens[c]=len2;
             c++;    
        }        
    }
    output();
    system("pause");
    return 0;
}
