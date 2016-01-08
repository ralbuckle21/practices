#include<iostream>
int gcd(int x,int y)
{
   int t;
   while(y) t=x,x=y,y=t%y;
   return x;
}
int main()
{
	int step,mod;
	while(scanf("%d %d",&step,&mod)!=EOF)
	{
		if(gcd(step,mod)==1) printf("%10d%10d    Good Choice\n\n",step,mod);
		else printf("%10d%10d    Bad Choice\n\n",step,mod);
	}
}