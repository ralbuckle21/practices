#include <iostream>
using namespace std;
int main()
{
 int n,m,i;
 while(cin>>n>>m)
 {
  int count=1;
  int num=n;
  while(num%m!=0&&count<=m)
  {
   count++;
   num=10*(num%m)+n;
  }
  if(count==m+1)
   cout<<0<<endl;
  else
   cout<<count<<endl;
 }
 return 0;
}
