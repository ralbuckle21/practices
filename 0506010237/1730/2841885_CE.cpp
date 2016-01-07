#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    long long int n;
    while(true)
    {
       cin>>n;
       if(n==0)
         break;
       int max=0;
       for(int i=1;i<=32;i++)
       {
          double m=pow(n,1.0/i);
          int n=int(m);
          if(m-n<1e-12||n+1-m<1e-12) max=i<max?max:i;
       }
        printf("%d\n",max);
    }
    system("pause");
    return 0;
}
