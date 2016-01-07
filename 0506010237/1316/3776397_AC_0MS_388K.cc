#include<iostream>
using namespace std;
bool num[11010]={0};
int getv(int v){
    int s=0;
    while(v){
       s+=v%10;
       v=v/10;         
    }   
    return s;
}
void init(){
     int v;
     for(int i=1;i<10000;i++){
       int v=i;
       while(v<10000){
            v=v+getv(v);
            if(num[v]) break;
            num[v]=true;               
       }
     }    
}
int main()
{
     init();
     for(int i=1;i<10000;i++) if(!num[i]) printf("%d\n",i);
     system("pause");
     return 0;
}
