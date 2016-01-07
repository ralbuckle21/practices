#include<iostream>
using namespace std;
char mg[500010];
char c[1100][100];
int n;
bool matchint(int k){
    int len=strlen(c[k]),j=0;
    for(int i=0;i<len;i++) if(c[k][i]<'0' || c[k][i]>'9') return false;
    for(int i=0;i<len;i++) if(c[k][i]!='0') c[k][j++]=c[k][i];
    c[k][j]='\0';
    return true;      
}
void match(){
    int len=strlen(mg),j=0,i=0;
    while(i<len){
         if(mg[i]=='%'){
              if(i==len) { cout<<"ERROR"<<endl; return; }
              if(i<len-1){
                   if(mg[i+1]=='%') i=i+2;
                   else if(mg[i+1]=='s'){ 
                       if(j==n){ cout<<"ERROR"<<endl; return;}
                       j++; i=i+2;
                   }
                   else if(mg[i+1]=='d'){
                       if(j==n){ cout<<"ERROR"<<endl; return;}
                       if(!matchint(j)){ cout<<"ERROR"<<endl; return;}
                       i=i+2; j++;     
                   }
                   else{ cout<<"ERROR"<<endl; }            
              }      
         }    
         else i++;    
    }  
    if(j<n){ cout<<"ERROR"<<endl; return; }
    j=0,i=0;
    while(i<len){
         if(mg[i]=='%' && i<len-1){
              if(mg[i+1]!='%') printf("%s",c[j++]);
              else printf("%");
              i=i+2;               
         }  
         else{
             printf("%c",mg[i]);
             i++;
         }                 
    }  
}
int main(){
    cin.getline(mg,50001); n=0;
    while(cin.getline(c[n],1000) && c[n][0]!='z') n++;
    match();
    return 0;
}
