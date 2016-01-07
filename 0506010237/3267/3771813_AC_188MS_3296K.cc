#include<iostream>
using namespace std;
const int maxs=INT_MAX;
char c[610][30];
int len[610];
int f[310];
int w[610][310][3]={0};
int k,n;
char mg[310];
void pipei(){
     for(int i=1;i<=n;i++){
         for(int j=0;j<k;j++){
              int a=i,b=0;
              while(b<len[j] && a<=n){
                    if(c[j][b]==mg[a]){ a++; b++; } 
                    else a++;              
              }        
              if(b==len[j]){
                   w[j][a-1][0]=i;
                   w[j][a-1][1]=a-i-b;
                   w[j][a-1][2]=true;
              }
         }        
     }     
}
int main()
{
     scanf("%d%d",&k,&n);
     scanf("%s",mg+1);
     for(int i=0;i<k;i++){
          scanf("%s",&c[i]);
          len[i]=strlen(c[i]);        
     }
     pipei();
     for(int i=1;i<=n;i++) f[i]=maxs; f[0]=0;
     for(int i=1;i<=n;i++){
         f[i]=f[i-1]+1;
         for(int j=0;j<k;j++){
             int d=w[j][i][0],v=w[j][i][1];bool s=w[j][i][2];
             if(s && f[i]>f[d-1]+v) f[i]=f[d-1]+v;
         }         
     }
     int sum=f[n];
     cout<<sum<<endl;      
     system("pause");
     return 0;
}
