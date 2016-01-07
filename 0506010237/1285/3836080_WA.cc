#include<iostream>
using namespace std;
long long unsigned int f[51][51];
int n,m;
int cs=1;
void init(){
    for(int i=0;i<=50;i++) f[i][0]=1;
    for(int i=1;i<=50;i++){
        f[i][i]=1;
        for(int j=1;j<i;j++)
           f[i][j]=f[i-1][j-1]+f[i-1][j];       
    }    
}
int main()
{
     int x;
     init();
     while(true){
          scanf("%d%d",&n,&m); 
          if(n==0 && m==0) break;   
          for(int i=1;i<=n;i++) scanf("%d",&x);
          printf("Case %d:\n",cs++);
          for(int i=1;i<=m;i++){
               scanf("%d",&x); 
               if(x>n) x=n;
               cout<<f[n][x]<<endl;      
          }        
     }
     system("pause");
     return 0;
}
