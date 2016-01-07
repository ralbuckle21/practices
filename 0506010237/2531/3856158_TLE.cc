#include<iostream>
using namespace std;
int c[22][22];
int n,result=0;
int sign[22];
void find(int k){
     if(k==n+1){
          int v=0;
          for(int i=1;i<=n;i++)
              for(int j=i+1;j<=n;j++)
                    if(sign[i]!=sign[j]) v+=c[i][j];        
          if(v>result) result=v;
          return;         
     }      
     sign[k]=1; find(k+1);
     sign[k]=2; find(k+1);
}
int main()
{
     scanf("%d",&n);
     for(int i=1;i<=n;i++)
         for(int j=1;j<=n;j++)
              scanf("%d",&c[i][j]);
     find(1);
     printf("%d\n",result);
     system("pause");
     return 0;
}
