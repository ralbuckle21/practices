#include<iostream>
#include<string>
using namespace std;
string mg;
string c[1100];
int n;
bool matchint(int k){
     char dd[50005];
    int i,len=c[k].size(),j=0;
    for(i=0;i<len;i++) if(c[k][i]<'0' || c[k][i]>'9') return false;
    for(i=0;i<len;i++) if(c[k][i]!='0') break; 
    for(;i<len;i++) dd[j++]=c[k][i];
    dd[j]='\0';
    c[k]=dd;
    return true;      
}
void match(){
    int len=mg.size(),j=0,i=0;
    while(i<len){
         if(mg[i]=='%'){
              if(i==len-1) { cout<<"ERROR"<<endl; return; }
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
              if(mg[i+1]!='%')cout<<c[j++];
              else printf("%");
              i=i+2;               
         }  
         else{
             printf("%c",mg[i]);
             i++;
         }                 
    }  
    cout<<endl;
}
int main(){
    getline(cin,mg); n=0;
    while(getline(cin,c[n]) && c[n]!="eof") n++;
    match();
    system("pause");
    return 0;
}
