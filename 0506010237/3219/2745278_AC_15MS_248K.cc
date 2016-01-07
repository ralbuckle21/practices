#include<iostream>
using namespace std;
int cc(int n)
{ 
    int sum=0;
    while(n>=2)
    {
        sum=sum+n/2; 
        n=n/2;
    }
    return sum;
}
int main()
{
  int n, k;
  while(scanf("%d%d", &n, &k)!=EOF)
  {  
    if(cc(n)>cc(n-k)+cc(k))
      printf("0\n");
     else
        printf("1\n");
  }
 return 0;
}