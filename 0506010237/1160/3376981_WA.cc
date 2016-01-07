#include<iostream>
using namespace std;
int n,k;
int num[301];
int s[301][301];
int f[301][30];
void cost(int n){
     int i,j,k;
     for(i=1;i<n;i++){
         for(k=i+1; k <= n; k ++){
            int mid=(i+k)/2;
            for(j=i;j<mid;j++) s[i][k]+=num[mid]-num[j];
            for(j=mid+1;j<=k;j++) s[i][k]+=num[j]-num[mid];
         }
      }
}
int main()
{
     int i,j,k,m;
     memset(s,0,sizeof(s));//s保存的是从i到j个放一个邮局的最少距离 
     memset(f,1000000,sizeof(f));
     scanf("%d %d",&n,&m);
     for(i=1;i<=n;i++) scanf("%d",&num[i]);
     cost(n);
     for(i=1;i<=n;i++) f[i][1]=s[1][i];
     for(k=2;k<=m;k++){//放K个 
         for(i=1;i<=n;i++){//保证i个村庄 
            for(j=1;j<i;j++)//f(i,k)=min(f(j,k-1)+s(j+1,i))
                 if(f[j][k-1]+s[j+1][i]<f[i][k]) f[i][k]=f[j][k-1]+s[j+1][i];        
         }                  
     }
     printf("%d\n",f[n][m]);
     system("pause");
     return 0;
}
