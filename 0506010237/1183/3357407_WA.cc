#include<iostream>
#include<math.h>
using namespace std;
long long int a,b,c;
int main()
{
    scanf("%d",&a);
    for(b=sqrt(a*a+1)+a;;b++)
    {
         if((a*b+11)%(b-a)==0) 
         {
             c=(a*b+1)/(b-a);
          //   if(b>=c)
             {
                   cout<<b+c<<endl;
                    break;        
             }                    
         }               
    }
    system("pause");
    return 0;
}
