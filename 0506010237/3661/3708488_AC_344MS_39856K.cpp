#include<iostream>
using namespace std;
int n,m;
int f[10010][505][2];
int num[10010];
int maxs(int a,int b){ return a>=b?a:b; }
int mins(int a,int b){ return a<=b?a:b; }
int main()
{
     memset(f,0,sizeof(f));
     scanf("%d %d",&n,&m);
     for(int k=1;k<=n;k++) scanf("%d",&num[k]);
     for(int k=1;k<=n;k++){
         f[k][1][0]=f[k-1][0][1]+num[k];
         int a=mins(k,m);
         for(int h=2;h<=a;h++) f[k][h][0]=f[k-1][h-1][0]+num[k];
         f[k][0][1]=maxs(f[k-1][1][0],f[k-1][1][1]);
         f[k][0][1]=maxs(f[k][0][1],f[k-1][0][1]);
         for(int h=a;h>0;h--) f[k][h][1]=maxs(f[k-1][h+1][0],f[k-1][h+1][1]);      
     }
     printf("%d\n",f[n][0][1]);
     system("pause");
     return 0;
}
