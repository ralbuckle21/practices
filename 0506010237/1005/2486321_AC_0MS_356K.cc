#include<iostream>
using namespace std;
int main()
{
    int counts=1;   
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        float m=100.0;  
        float t=3.14;
        int year=1;
        float a,b,h;
        cin>>a;
        cin>>b;
        h=3.14*(a*a+b*b);
        while(h>m)
        {
           m=m+100.0;
           year++;    
        }    
        cout<<"Property "<<counts<<": This property will begin eroding in year "<<year<<"."<<endl;
        counts++;
    }    
    cout<<"END OF OUTPUT."<<endl;
    return 0;
}
