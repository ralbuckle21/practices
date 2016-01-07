#include<iostream>
using namespace std;
int n,k,result;
int main()
{
     while(scanf("%d %d",&n,&k)!=EOF)
     {
         result=n;
         while(n>=k)
         {
             result+=n/k;
             n=n/k+n%k;       
         }
         printf("%d\n",result);
     }
     system("pause");
     return 0;
}
