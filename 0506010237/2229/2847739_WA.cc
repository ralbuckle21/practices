#include <stdio.h>
#include<iostream>
#include<math.h>
using namespace std;
long long  int n,num[1000001],t[10];
int  main()
{
     int i;
     while (scanf ("%I64d",&n)!=EOF)
     {
           num[1]=1;
           num[2]=2;
           for (i=3;i<=n;i++)
           {
               if (i%2==1)
                  num[i]=num[i-1];
               if (i%2==0)
               {
                   num[i]=num[i-2]+num[i/2];
                   int k=num[i]%100000;
                   num[i]=((num[i]/100000)%100000)*100000+k;
               }  
           }
           cout<<num[n]<<endl;
     }
     return 0;
}

