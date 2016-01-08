#include<stdio.h>
__int64 count( int n) 
{
	__int64 sum=0;
	if(n==1)return 2;
	if(n==2)return 4;
	sum=count(n-1)+2*count(n-2)+6;
	return sum;
}
 int main()
 {
	 int n,m,i;
	 __int64 sum;
	 scanf("%d",&m);
	 for(i=0;i<m;i++)
	  {
		   scanf("%d",&n);
		   sum=count(n);
		   printf("%d\n",sum);
	   }
	 return 0;
 }

		 
