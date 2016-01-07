#include<iostream>
#include<math.h>
using namespace std;
long long int f(int n,int m)
{
    if(n<=0 || m<=0)
      return 0;
    if(m==1 || n==1)
      return 1;
    if(m>n)
      return f(n,n);
    if(n==m)
    {
        int k=m;
        while(k%2==0)
          k=k/2;
        if(k==1)
           return 1+f(n,n/2);
        else
           return f(n,n-1);    
    }   
    if(n>m)
    {
        int k=m;
        while(k%2==0)
          k=k/2;
        if(k==1)
           return f(n,m/2)+f(n-m,m);
        else
          return f(n,m-1);
    }
}
int main()
{
    int n;
    while(true)
    {
       scanf("%d",&n);
       cout<<f(n,n)<<endl;
    }
    system("pause");
    return 0;
}
