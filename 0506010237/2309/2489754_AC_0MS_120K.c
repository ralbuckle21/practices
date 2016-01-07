#include<stdio.h>
int main()
{
	int N, a, b;
	scanf("%d", &N);
	while(N--)
	{
		scanf("%d", &a);
		b=1;
		while(!(a&b)) b<<=1;
		b--;
		printf("%d %d\n", a-b, a+b);
	}
}
