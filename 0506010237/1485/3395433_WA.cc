#include<iostream>
#define maxs INT_MAX
#include<string.h>
using namespace std;
int n,m;
int num[302];
int s[302][302][2];
int f[302][32][2];
int cs=1,h=1;
void cost(int n){
     int i,j,k;
     for(i=1;i<=n;i++){
         for(k=i;k <= n;k ++){
            s[i][k][0]=0;
            int mid=(i+k)/2;
            for(j=i;j<mid;j++) s[i][k][0]+=num[mid]-num[j];
            for(j=mid+1;j<=k;j++) s[i][k][0]+=num[j]-num[mid];
            s[i][k][1]=mid;
         }
      }
}
void output(int x,int y){
     if(y==0) return;
     output(f[x][y][1],y-1);
     if(f[x][y][1]+1==x) printf("Depot %d at restaurant %d serves restaurant %d\n",h++,s[f[x][y][1]+1][x][1],y);
     else printf("Depot %d at restaurant %d serves restaurants %d to %d\n",h++,s[f[x][y][1]+1][x][1],f[x][y][1]+1,x);       
}
int main()
{
     int i,j,k;
     while(true){
         scanf("%d %d",&n,&m);
         if(n==0 && m==0) break;
         for(i=1;i<=n;i++) scanf("%d",&num[i]);
         cost(n);
         for(i=1;i<=n;i++){ 
             f[i][1][0]=s[1][i][0];
             f[i][1][1]=0;   
         }
        for(k=2;k<=m;k++){ 
             for(i=1;i<=n;i++){
                 f[i][k][0]=f[1][k-1][0]+s[2][i][0];
                 for(j=2;j<i;j++)
                    if(f[j][k-1][0]+s[j+1][i][0]<f[i][k][0]){
                         f[i][k][0]=f[j][k-1][0]+s[j+1][i][0];
                         f[i][k][1]=j; 
                    }       
             }                  
         }
         printf("Chain %d\n",cs++);
         output(f[n][m][1],m-1);
         if(f[n][m][1]+1==n) printf("Depot %d at restaurant %d serves restaurant %d\n",h++,s[f[n][m][1]+1][n][1],n);
         else printf("Depot %d at restaurant %d serves restaurants %d to %d\n",h++,s[f[n][m][1]+1][n][1],f[n][m][1]+1,n);
         printf("Total distance sum = %d\n\n",f[n][m][0]);
         h=1;
     }
     system("pause");
     return 0;
}


