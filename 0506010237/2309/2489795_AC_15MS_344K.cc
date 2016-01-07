#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
       int h;
       cin>>h;
       int k=1;
       while(!(k&h))
           k=k*2;
           k--;
       cout<<h-k<<" "<<h+k<<endl;
    }   
    system("pause");
    return 0;
}