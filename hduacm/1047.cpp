#include<stdio.h>
int main()
{
    __int64 a[41];
    int n,i;
    a[1]=3;
	a[2]=8;
    for(i=3;i<41;i++)
        a[i]=2*(a[i-1]+a[i-2]);
    while(scanf("%d",&n)!=EOF)
        printf("%I64d\n",a[n]);
    return 0;
} 