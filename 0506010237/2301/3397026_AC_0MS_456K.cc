#include<iostream>
using namespace std;
int t;
long long int a,b;
int main()
{
    cin>>t;
    while(t--){
       cin>>a>>b;
       if(a>=b && (a+b)%2==0) cout<<(a+b)/2<<" "<<(a-b)/2<<endl;
       else cout<<"impossible"<<endl;           
    }
    system("pause");
    return 0;
}
