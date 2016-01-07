#include<iostream>
using namespace std;
long long int a,b,c;
int main()
{
    scanf("%d",&a);
    for(b=a+1;;b++)
    {
         if((a+b)%(a*b-1)==0) 
         {
             c=(a+b)/(a*b-1);
             if(b>=c)
             {
                   cout<<b+c<<endl;
                    break;        
             }                    
         }               
    }
    system("pause");
    return 0;
}
