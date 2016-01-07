#include<iostream>
using namespace std;
long long int fs[202][202];
void init(){
   for(int i=1;i<=200;i++){
         fs[i][1]=fs[1][i]=1;
         fs[i][0]=fs[0][i]=1;      
   }
   for(int i=2;i<=200;i++)
       for(int j=2;j<=i;j++)
          if(i<j) fs[i][j]=1;
          else fs[i][j]=fs[i][j-1]+fs[i-j][j];  
}
int main()
{
   int m,n;
   init();
   while(true){
        scanf("%d %d",&m,&n);
        if(n==0 && m==0) break;
        cout<<fs[m-n][n]<<endl;
   }
   system("pause");
   return 0;
}
