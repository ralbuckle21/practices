#include<iostream>
using namespace std;
int main()
{
   int n;
   cin>>n;
   int c[n][n];
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<=i;j++)
        cin>>c[i][j];    
   }   
   for(int i=1;i<n;i++)
   {
       c[i][0]=c[i-1][0]+c[i][0];
       c[i][i]=c[i-1][i-1]+c[i][i];    
      for(int j=1;j<i;j++)
      {
         if(c[i-1][j-1]>=c[i-1][j])
             c[i][j]=c[i-1][j-1]+c[i][j];
          else
             c[i][j]=c[i-1][j]+c[i][j];         
      }        
   }
   int max=c[n-1][0];
   for(int k=1;k<n;k++)
   {
       if(c[n-1][k]>max)
       max=c[n-1][k];       
    }
    cout<<max<<endl;
    return 0;
}
