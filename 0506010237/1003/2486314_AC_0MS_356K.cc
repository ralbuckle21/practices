#include<iostream>
using namespace std;
int card(float x)
{
    int i=0;
    float m=0.00;
    while(m<x)
    {
       i++;
       m=m+(1.00)/(i+1);    
    }  
    return i;     
}
int main()
{
    float n;
    while(true)
    {
        cin>>n;
        if(n<=0.00 && n>=0.00)
           break;
        else
        {
            cout<<card(n)<<" card(s)"<<endl;   
         }    
    }    
    return 0;
}


