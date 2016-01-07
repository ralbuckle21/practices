#include<iostream>
using namespace std;
int f(int m,int n)
{
   if(m<0)
	   return 0;
   else if(m==1 || n==1)
	   return 1;
   else
	   return f(m,n-1)+f(m-n,n);
}
int main()
{
   int i,j,c,m,n;
   scanf("%d",&c);
   for(i=1;i<=c;i++)
   {
        scanf("%d %d",&m,&n);
       cout<<f(m,n)<<endl;
   }
   system("pause");
   return 0;
}