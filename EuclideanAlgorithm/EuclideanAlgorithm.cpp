#include<iostream>
#include<cmath>
using namespace std;
 void swap(int & a, int & b)
 {
 int c = a;
 a = b;
 b = c;
 }
//计算a,b的最大公约数的函数gcd(int a,int b)

 int gcd(int a,int b)
 {
 if(0 == a )
 {
  return b;
 }
 if( 0 == b)
 {
  return a;
 }
 if(a > b)
 {
  swap(a,b);
 }
 int c;
 for(c = a % b ; c > 0 ; c = a % b)
 {
  a = b;
  b = c;
 }
 return b;
 }
int main()
{
int a, b;
cin >> a >> b;
cout << gcd(a,b);
system("PAUSE");
return 0;
}

