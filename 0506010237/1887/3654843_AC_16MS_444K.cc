#include<iostream>
using namespace std;
int cs=1,n;
int heigh[10000];
int list(){
     int h[10000];
     int len=1,p,r,m;
     h[0]=INT_MAX;
     h[1]=heigh[0];
     for(int i=1;i<n;i++){
         p=0;
         r=len;
         while(p<=r){
             int m=(p+r)/2;
             if(h[m]>heigh[i])  p=m+1;
             else  r=m-1;         
         }        
         h[p]=heigh[i];
         if(p>len)  len=len+1;
     }
     return len;
}
int main()
{
    int b;
     while(true){
         n=0;    
         scanf("%d",&b);
         if(b==-1) break;
         while(true){
             heigh[n++]=b;
             scanf("%d",&b);
             if(b==-1) break;             
         }        
         printf("Test #%d:\n  maximum possible interceptions: %d\n\n",cs++,list());
     }
     system("pause");
     return 0;
}
