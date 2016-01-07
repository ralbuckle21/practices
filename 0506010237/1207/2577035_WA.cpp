#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int a,b;
    while(cin>>a>>b)
    {
        if(a>b)
        {
            int temp=a;
            a=b;
            b=temp;       
        }
        int max=0;
      for(int i=a;i<=b;i++)
      {
         int x=1,j=i;
         while(j!=1)
         {    
              if(j%2==0)
              {
                  j=j/2;
                  x++;
              }           
              else
              {
                 j=3*j+1;
                 x++;
              }
         }  
         if(x>max)
             max=x;
       }
       cout<<a<<" "<<b<<" "<<max<<endl;
    }
    system("pause");
    return 0;
}
              
