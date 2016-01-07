#include<iostream>
using namespace std;
int countnum(int n)
{
   if(n==2)
     return 1;
   else 
   {
      int m=0;
      int k=n-2;
      for(int i=4;i<=k;i+=2) 
         m=countnum(i-2)*countnum(n-i)+m;
            return 2*countnum(n-2)+m;            
   }      
}
int main()
{
    int n;
    while(true)
    {
           cin>>n;
           if(n==-1)
             break;
           cout<<countnum(2*n)<<endl;
    }
    return 0;
}