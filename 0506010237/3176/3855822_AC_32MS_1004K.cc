#include<iostream>
using namespace std;
int num[400][400];
int n;
int maxs(int a,int b){ return a>b?a:b; }
int main()
{
     scanf("%d",&n);
     for(int i=0;i<n;i++)
         for(int j=0;j<=i;j++)     
             scanf("%d",&num[i][j]);   
     for(int i=1;i<n;i++){
         num[i][0]+=num[i-1][0];
         num[i][i]+=num[i-1][i-1];
         for(int j=1;j<i;j++)
              num[i][j]+=maxs(num[i-1][j-1],num[i-1][j]);           
     }
     int sum=0;
     for(int i=0;i<n;i++)
        if(num[n-1][i]>sum) sum=num[n-1][i];
     cout<<sum<<endl;
     system("pause");
     return 0;
}
