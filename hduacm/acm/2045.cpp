#include<stdio.h>
int main()
{
	__int64 rpg[50];
	int i,n;
	rpg[1]=3;
	rpg[2]=6;
	rpg[3]=6;
	for(i=4;i<=50;i++)
		rpg[i]=rpg[i-1]+2*rpg[i-2];
	while(scanf("%d",&n)!=EOF)
		printf("%I64d\n",rpg[n]);
	return 0;
}