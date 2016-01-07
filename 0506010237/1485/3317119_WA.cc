#include<iostream>
using namespace std;
int cs=1;
int n,k;
int num[201];
int s[201][201];
int f[201][30];
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
     while(true){
        scanf("%d %d",&n,&m);
        if(n==0 && m==0) break;
        for(i=1;i<=n;i++) scanf("%d",&num[i]);
        memset(s,0,sizeof(s));
        memset(f,1000000,sizeof(f));
        cost(n);
        for(i=1;i<=n;i++) f[i][1]=s[1][i];
        for(k=2;k<=m;k++){
             for(i=1;i<=n;i++){
                 for(j=1;j<i;j++)
                     if(f[j][k-1]+s[j+1][i]<f[i][k]) f[i][k]=f[j][k-1]+s[j+1][i];        
             }                  
        }
        printf("Chain %d\nTotal distance sum = %d\n\n",cs++,f[n][m]);
     }
     system("pause");
     return 0;
}
