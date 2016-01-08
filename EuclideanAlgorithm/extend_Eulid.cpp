#include <iostream>
using namespace std;
int x,y,q;
int extend_Eulid(int a,int b,int &x,int &y)
{
             int ans,t;
             if (b==0) { x=1; y=0; cout<<x<<" "<<y<<endl; return a; }
             else { ans=extend_Eulid(b,a%b,x,y); t=x; x=y; y=t-(a/b)*y;}
             return ans;
}
int main()
{
int a,b;
cin>>a>>b;
if(a < b)
swap(a,b);
int c = extend_Eulid(a,b,x,y);
cout<<c;
system("PAUSE");
return 0;
}
