#include<iostream>
#include<cmath>
using namespace std;
 void swap(int & a, int & b)
 {
 int c = a;
 a = b;
 b = c;
 }
//����a,b�����Լ���ĺ���gcd(int a,int b)

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

