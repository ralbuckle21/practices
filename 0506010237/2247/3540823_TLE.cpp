#include<iostream>
using namespace std;
bool a[1000000001]={false};
int sign[55843];
int len=3;
int n;
bool isprim1(int k){
     if(k%2==0 && a[k/2]){
          a[k]=true;
          return true;
     }    
     if(k%3==0 && a[k/3]){
          a[k]=true;
          return true;   
     }       
     if(k%5==0 && a[k/5]){
          a[k]=true;
          return true;
     }    
     if(k%7==0 && a[k/7]){
          a[k]=true;
          return true;   
     } 
     return false; 
}
bool isprim(int k){
     if(k%2==0 && a[k/2])  return true;   
     if(k%3==0 && a[k/3])  return true;         
     if(k%5==0 && a[k/5])  return true;  
     if(k%7==0 && a[k/7])  return true;   
     return false; 
}
void init(){
    a[1]=true; a[2]=true; a[3]=true;   
    sign[1]=1; sign[2]=2; sign[3]=3;
    for(int i=4;i<=1000000000;i++)
        if(isprim1(i)) sign[++len]=i;
    for(int i=1000000001;i<=2000000000;i++)  
       if(isprim(i)) sign[++len]=i;            
}
int main()
{
    init();
    while(true){
        scanf("%d",&n); 
        if(n==0) break;
        printf("The %dst humble number is %d.\n",n,sign[n]);           
    }
    system("pause");
    return 0;
}
