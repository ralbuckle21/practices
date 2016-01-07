#include<iostream>
using namespace std;
long long int a,b,c;
int main()
{
    scanf("%d",&a);
    for(b=a+1;;b++)
    {
         if(a*a*(b*b+1)%(b-a)==0) 
         {
             cout<<a*a*(b*b+1)/(b-a)<<endl;
             break;                     
         }               
    }
    system("pause");
    return 0;
}
