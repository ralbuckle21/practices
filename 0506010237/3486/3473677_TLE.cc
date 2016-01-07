#include<iostream>
using namespace std;
int n,c;
int m[1003][1003];
int main()
{
    while(scanf("%d",&c) != EOF){
          scanf("%d",&n);
          memset(m,0,sizeof(m));
          for(int i=1;i<=n;i++){
               for(int j=i;j<=n;j++){ 
                   scanf("%d",&m[i][j]);
                   m[i][j]+=c;
               }               
          }
          for(int i=1;i<n;i++){
               for(int j=1;j<=n-i;j++){
                    int t=i+j;
                    for(int k=j;k<t;k++){
                         if(m[j][t]>m[j][k]+m[k+1][t])
                              m[j][t]=m[j][k]+m[k+1][t];        
                    }        
               }        
          }  
          printf("%d\n",m[1][n]);                  
    }
    system("pause");
    return 0;
}
