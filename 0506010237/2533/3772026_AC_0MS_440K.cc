#include<iostream>
using namespace std;
int n;
int num[1000];
int list(){
     int b[1003];
     int len=1,p,r,m;
     b[0]=-10;
     b[1]=num[0];
     for(int i=1;i<n;i++){
         p=0;
         r=len;
         while(p<=r){
             int m=(p+r)/2;
             if(b[m]<num[i])  p=m+1;
             else  r=m-1;         
         }        
         b[p]=num[i];
         if(p>len)  len=len+1;
     }
     return len;
}
int main()
{
     scanf("%d",&n);
     for(int i=0;i<n;i++) scanf("%d",&num[i]);
     cout<<list()<<endl;
     system("pause");
     return 0;
}
