#include<iostream>
using namespace std;
int main()
{
    float money=0.00;
    float m;
    for(int i=0;i<=11;i++)
     {
         cin>>m;
         money=money+m;
     }   
     money=money/12;
     cout<<"$"<<money<<endl;
    return 0;
}