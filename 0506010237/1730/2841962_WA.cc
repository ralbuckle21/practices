#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    long long int h;
    while(true)
    {
       cin>>h;
       if(h==0)
         break;
       int max=0,sign=0;
       if(h<0)
       {
           sign=1;
           h=-h;      
       }  
       for(int i=1;i<=32;i++)
       {
          double m=pow(h,1.0/i);
          int n=int(m);
          if(m-n<1e-12||n+1-m<1e-12)
          {
             if(sign && i%2==0)
              continue;
              max=i<max?max:i;
          }
       }
        printf("%d\n",max);
    }
    system("pause");
    return 0;
}
