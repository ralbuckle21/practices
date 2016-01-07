#include<iostream>
using namespace std;
const int baseN=127;
int flag[baseN*baseN*baseN];
char c[baseN];
int len;
/*void print(int x){
    if(x>=baseN) print(x/baseN);
    cout<<char(x%baseN);     
}*/
int main(){
    bool dot=false,dot1=false,fdot=false;
    memset(flag,0,sizeof(flag));
    while(gets(c)){
         len=strlen(c);
         for(int i=0;i<len;i++){
             if(c[i]==' '){ 
                   dot=false; dot1=false; fdot=false;           
             }
             else if(i>=2 && (c[i]=='i' || c[i]=='l') && c[i-1]=='f' && c[i-2]=='f'){
                   int temp=c[i-2]*baseN+c[i-1];
                   flag[temp]--;
                   temp=temp*baseN+c[i];
                   flag[temp]++;
                   dot=false; dot1=false; fdot=false;    
             }
             else if(i>=1 && (c[i]=='i' || c[i]=='l') && c[i-1]=='f'){
                   int temp=c[i-1];
                   flag[temp]--;
                   temp=temp*baseN+c[i];
                   flag[temp]++;
                   dot=false; dot1=false; fdot=false;   
             }     
             else if(i>=1 && c[i]=='f' && fdot){
                   int temp=c[i-1];
                   flag[temp]--;
                   temp=temp*baseN+c[i];
                   flag[temp]++;
                   dot=false; dot1=false; fdot=false;       
             }       
             else if(i>=1 && c[i]=='`' && dot){
                  int temp='`';
                  flag[temp]--;
                  temp=temp*baseN+'`';
                  flag[temp]++; 
                  dot=false; dot1=false; fdot=false;  
             }     
             else if(i>=1 && c[i]=='\'' && dot1){
                  int temp='\'';
                  flag[temp]--;
                  temp=temp*baseN+'\'';
                  flag[temp]++; 
                  dot=false; dot1=false; fdot=false;     
             }
             else{
                  flag[c[i]]++;
                  dot=false; dot1=false; fdot=false;
                  if(c[i]=='`') dot=true;
                  else if(c[i]=='\'') dot1=true;
                  else if(c[i]=='f') fdot=true;     
             }
         }                
    }
    int cnt=0;
    for(int i=1;i<baseN*baseN*baseN;i++) if(flag[i]>0){
             cnt++;
        // print(i);  
         //cout<<" ";       
    }
    printf("%d\n",cnt); 
    system("pause");
    return 0;
}
