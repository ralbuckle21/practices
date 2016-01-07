#include<iostream>
using namespace std;
double f[51][51];
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
     char c[100];
     init();
     while(true){
          scanf("%d%d ",&n,&m); 
          if(n==0 && m==0) break;   
          getchar();
          //for(int i=1;i<=n;i++) scanf("%d",&x);
          gets(c);
          printf("Case %ld:\n",cs++);
          for(int i=1;i<=m;i++){
               scanf("%d",&x); 
               printf("%0.0lf\n",f[n][x]);      
          }        
     }
     system("pause");
     return 0;
}
