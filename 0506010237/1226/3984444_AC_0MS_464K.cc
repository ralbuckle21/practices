#include<iostream>
#include<string>
using namespace std;
char c[110][110];
int n,t;
void strrev(char d[110],int h){
     int i=0,j=h-1; 
     while(i<j){ char tmp=d[i]; d[i]=d[j]; d[j]=tmp; i++; j--;}    
}
bool find(char d[110],int h){
    for(int i=1;i<n;i++){
          if(strstr(c[i],d)==NULL){
               strrev(d,h);
               if(strstr(c[i],d)==NULL) return false;
          }
    }      
    return true;
}
void scpy(char d[110],int x,int h){
    for(int i=0;i<h;i++) d[i]=c[0][x+i]; d[h]='\0';   
}
void getv(){
     char d[110];
     for(int i=0;i<n;i++) scanf("%s",c[i]);
     int len=strlen(c[0]),h=len;
     while(h){
         for(int i=0;i+h<=len;i++){
             scpy(d,i,h);
             if(find(d,h)){ cout<<h<<endl; return; }
         }    
         h--;        
     }        
     cout<<h<<endl;     
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        getv();
    }
    system("pause");
    return 0;
}
