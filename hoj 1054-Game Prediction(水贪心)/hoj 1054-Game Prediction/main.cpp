#include<iostream>
#include<algorithm>
using namespace std;
int n,m,c[51],cas=0;
int main()
{
	while(scanf("%d %d",&m,&n)&&m&&n)
	{
		 for(int i=0;i<n;i++)
			 scanf("%d",&c[i]);
		 sort(c,c+n);
		 int max=m*n,num=n-1,res=0;
		 while(n--)
		 {
			 if(max==c[num])
			 {
				 res++;
				 max--;
			 }
			 else max-=2;
			 num--;
		 }
		 cas++;
		 printf("Case %d: %d\n",cas,res);
	}
}