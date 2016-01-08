#include<iostream>
using namespace std;
int main()
{
    int n,i,j,k;
    while(cin>>n)
    {
        if(n==0) break;
        k=0;
        for(i=1;i*i<=n;i++)
            k++;
        cout<<k<<endl;
    }
    return 0;
}