#include<iostream>
using namespace std;
char c[10001][30];
int len[10001];
char mg[30];
int mlen;
int n,m;
bool match1(){
    for(int i=0;i<n;i++){
        if(mlen!=len[i]) continue;
        if(strcmp(mg,c[i])==0) return true;        
    }  
    return false;  
}
int match2(){
    for(int i=0;i<n;i++){
        if(mlen<=len[i]+1 && mlen>=len[i]-1){
             int j=0,a,b;
             while(c[i][j]==mg[j]) j++;
             if(mlen==len[i]){
                   if(c[i][j]==mg[j+1] && c[i][j+1]==mg[j]){ a=j+2; b=j+2; }
                   else { a=j+1; b=j+1; }                
             }              
             else if(mlen==len[i]+1){ a=j; b=j+1; }
             else { a=j+1; b=j; }
             while(a<len[i] && c[i][a]==mg[b]){ a++; b++; }  
             if(a==len[i]) return i;   
        }        
    }    
    return -1;
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s",c[i]);
        len[i]=strlen(c[i]);
    }
    scanf("%d",&m);
    while(m--){
         scanf("%s",mg);
         mlen=strlen(mg);
         if(match1()) printf("%s is correct\n",mg);
         else{
             int k=match2();
             if(k>=0) printf("%s is a misspelling of %s\n",mg,c[k]);
             else printf("%s is unknown\n",mg);
         }               
    }
    system("pause");
    return 0;
}
