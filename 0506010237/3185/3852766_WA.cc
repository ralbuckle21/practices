#include<iostream>
using namespace std;
int result=5000;
int v[21];
int c[21];
void getv1(){
     int s=0;
     for(int i=0;i<19;i++){
          if(c[i]){
               s++;
               if(i+1<20) c[i+1]=1-c[i+1];
               if(i+2<20) c[i+2]=1-c[i+2];    
          }        
     }
     if(result>s) result=s;     
}
void getv2(){
     int s=0;
     if(c[0]==1){ c[1]=1-c[1];s++;}
     for(int i=1;i<19;i++){
          if(c[i]){
               s++;
               if(i+1<20) c[i+1]=1-c[i+1];
               if(i+2<20) c[i+2]=1-c[i+2];    
          }        
     }
     if(result>s) result=s;      
}
int main()
{
     for(int i=0;i<20;i++) scanf("%d",&v[i]);
     for(int i=0;i<20;i++) c[i]=v[i];  getv1();
     for(int i=0;i<20;i++) c[i]=v[i];  getv2();
     for(int i=19;i>=0;i--) c[i]=v[i]; getv1();
     for(int i=19;i>=0;i--) c[i]=v[i]; getv2();
     printf("%d\n",result);
     system("pause");
     return 0;
}

