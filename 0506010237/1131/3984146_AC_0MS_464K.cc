#include<iostream>
using namespace std;
char c[1000],len;
int a[1000],n;
void convert(){
     int r=0,v,i;
     for(i=0;i<n;i++){
          v=r*10+a[i];
          a[i]=v/8;
          r=v%8;        
     }     
     while(r){
          v=r*10;
          a[n++]= v/8;
          r=v%8;         
     }
}
int main(){
    while(scanf("%s",c)!=EOF){
          if(c[0]=='1'){ cout<<"1 [8] = 1 [10]"<<endl; continue; }
          memset(a,0,sizeof(a));
          len=strlen(c); n=1;
          for(int i=len-1;i>=2;i--){ 
                  a[0]=c[i]-'0';
                  convert();
          }   
          cout<<c<<" [8] = 0.";
          for(int i=1;i<n;i++) cout<<a[i]; cout<<" [10]"<<endl;           
    }
    system("pause");
    return 0;
}
