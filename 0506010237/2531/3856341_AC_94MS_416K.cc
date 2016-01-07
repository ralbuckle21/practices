#include<iostream>
using namespace std;
int c[22][22];
int n,result=0;
bool sign[22];
int v[22];
void find(int k,int a,int r){
     int temp=0;
     if(a+r<=result) return;
     if(k==n+1){
          if(a>result) result=a;
          return;         
     }      
     sign[k]=false;
     for(int i=1;i<k;i++) if(sign[i]) temp+=c[k][i]; find(k+1,a+temp,r-v[k]);
     sign[k]=true; temp=0;
     for(int i=1;i<k;i++) if(!sign[i]) temp+=c[i][k]; find(k+1,a+temp,r-v[k]);
}
int main()
{
     int sum=0;
     scanf("%d",&n);
     for(int i=1;i<=n;i++){
         for(int j=1;j<=n;j++){
              scanf("%d",&c[i][j]);
              v[i]+=c[i][j];
         }
         sum+=v[i];
     }
     find(1,0,sum);
     printf("%d\n",result);
     system("pause");
     return 0;
}
