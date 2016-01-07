#include<iostream>
using namespace std;
int a[3]={2,3,5};
int c[3]={1,1,1};
int f[1800];
int n;
void init(){
     f[1]=1;
     for(int i=2;i<=1500;i++){
         int v=INT_MAX,u;
         for(int j=0;j<3;j++)
             if(a[j]*f[c[j]]<v)
                   v=a[j]*f[c[j]];       
         f[i]=v;
         for(int j=0;j<3;j++)
             while(a[j]*f[c[j]]<=v) c[j]++;
     }    
}
int main()
{
     init();
     while(true){
         scanf("%d",&n);
         if(n==0) break;
         printf("%d\n",f[n]);            
     }
     system("pause");
     return 0;
}
