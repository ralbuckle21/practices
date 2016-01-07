#include<iostream>
using namespace std;
int main()
{
     int t,n;
     scanf("%d",&t);
     while(t--)
     {
          scanf("%d",&n);
          if(n==1) cout<<0<<endl;
          else if(n==2) cout<<1<<endl;
          else   cout<<int(n/2)*int((n-1)/2)<<endl;          
     }
     system("pause");
     return 0;
}
