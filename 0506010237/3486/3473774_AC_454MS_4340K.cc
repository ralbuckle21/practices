#include<iostream>
using namespace std;
int n,c;
int m[1003][1003];
int f[1003];
int main()
{
    while(scanf("%d",&c) != EOF){
          scanf("%d",&n);
          memset(m,0,sizeof(m));
          for(int i=1;i<=n;i++){
               for(int j=i;j<=n;j++)
                   scanf("%d",&m[i][j]); 
          }
          for(int i=1;i<=n;i++){
               f[i]=c+m[1][i];        
          }
          for(int i=2;i<=n;i++){
               for(int j=i;j<=n;j++){
                    if(f[j]>f[i-1]+c+m[i][j])
                         f[j]=f[i-1]+c+m[i][j];        
               }        
          }
          printf("%d\n",f[n]);                  
    }
    system("pause");
    return 0;
}
