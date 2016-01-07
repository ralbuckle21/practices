#include<iostream>
using namespace std;
int main()
{
   int n,m;
   cin>>n;
   cin>>m;
   int c=0;
   for(int i=2;i<m;i++)  
   {
       if(m%i==0)
         c++;        
   } 
   c++;
   int total=1;
   int totalc=1;
   for(int i=1;i<=n;i++)
    {
             total=m*total;
             totalc=c*totalc;
    }
   cout<<total-totalc<<endl;
   return 0;
}