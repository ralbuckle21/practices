#include<iostream>
using namespace std;
int f(int n)
{
    return n*(n-1)/2;   
}
int main()
{
     int t,n;
     scanf("%d",&t);
     while(t--)
     {
          scanf("%d",&n);
          if(n==1) cout<<0<<endl;
          else if(n==2 || n==3) cout<<1<<endl;
          else {
          if(n%2==0) cout<<2*f(n/2)<<endl;
          else cout<<f(n/2)+f(n/2+1)<<endl;
          }
     }
     system("pause");
     return 0;
}
