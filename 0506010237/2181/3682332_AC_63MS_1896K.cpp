#include<iostream>
using namespace std;
int n;
int v[150000];
int f[150000][2];
int main()
{
     scanf("%d",&n);
     for(int i=0;i<n;i++) scanf("%d",&v[i]);
     f[0][0]=v[0]; f[0][1]=0;
     for(int i=1;i<n;i++){
         int j=f[i-1][1],mins=INT_MAX;
         for(;j<i;j++) if(v[j]<mins) mins=v[j];
         if(mins<v[i]){
             f[i][0]= f[i-1][0]+v[i]-mins;
             f[i][1]=i;
         }
         else{
             f[i][0]=f[i-1][0];
             f[i][1]=f[i-1][1];     
         }        
     }
     printf("%d\n",f[n-1][0]);
     system("pause");
     return 0;
}
