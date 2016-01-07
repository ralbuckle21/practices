#include<iostream>
using namespace std;
const int baseN=122;
bool flag[baseN*baseN*baseN];
char c[baseN];
int len;
int main(){
    bool dot=false,dot1=false;
    memset(flag,0,sizeof(flag));
    while(gets(c)){
         len=strlen(c);
         for(int i=0;i<len;i++){
             if(i>=2 && (c[i]=='i' || c[i]=='l') && c[i-1]=='f' && c[i-2]=='f'){
                   int temp=c[i-2]*baseN+c[i-1];
                   flag[temp]=false;
                   temp=temp*baseN+c[i];
                   flag[temp]=true;
                   dot=false; dot1=false;      
             }
             else if(i>=1 && (c[i]=='i' || c[i]=='l' || c[i]=='f') && c[i-1]=='f'){
                   int temp=c[i-1];
                   flag[temp]=false;
                   temp=temp*baseN+c[i];
                   flag[temp]=true;
                   dot=false; dot1=false;    
             }            
             else if(i>=1 && c[i]=='`' && dot){
                  int temp='`';
                  flag[temp]=false;
                  temp=temp*baseN+'`';
                  flag[temp]=true; 
                  dot=false; dot1=false;   
             }     
             else if(i>=1 && c[i]=='\'' && dot1){
                  int temp='\'';
                  flag[temp]=false;
                  temp=temp*baseN+'\'';
                  flag[temp]=true; 
                  dot=false; dot1=false;     
             }
             else{
                  flag[c[i]]=true;
                  if(c[i]=='`') dot=true;
                  if(c[i]=='\'') dot1=true;     
             }
         }                
    }
    int cnt=0;
    for(int i=0;i<baseN*baseN*baseN;i++) if(flag[i]) cnt++;
    printf("%d\n",cnt); 
    system("pause");
    return 0;
}
