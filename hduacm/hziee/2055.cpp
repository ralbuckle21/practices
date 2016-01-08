#include<stdio.h>
int main()
{
	int n=0,x2=0,x3=0,i;
	char x1;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("\n%c %d",&x1,&x2);
		x3=( int )x1;
		x3=x3<97 ? x3-64: -(x3-96);
		printf("%d\n",x3+x2);
	}
	return 0;
}

