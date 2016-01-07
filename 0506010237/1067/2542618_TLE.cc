#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int a,b;
    while(cin>>a && cin>>b)
    {
         if(a>b)
         {
            int t=a;
            a=b;
            b=t;       
         }
         int k=0,n=0,m=0;
         while(m<a)
         {
            k++;
            m=int(k*(1+sqrt(5))/2);
            n=k+m;          
         }   
         if(m==a && n==b)
          cout<<"0"<<endl;
         else
           cout<<"1"<<endl;        
    }
    system("pause");
    return 0;
}
