#include<iostream>
using namespace std;
int f(int n)
{
    if(n==2) return 1;
    else if(n==3) return 3;
    else
    {
         if(n%2==0) return 2*f(n/2);
         else return f(n/2)+f(n/2+1);     
    }   
}
int main()
{
     int t,n;
     scanf("%d",&t);
     while(t--)
     {
          scanf("%d",&n);
          if(n==1) cout<<0<<endl;
          else if(n==3) cout<<2<<endl;
          else   cout<<f(n)<<endl;          
     }
     system("pause");
     return 0;
}
