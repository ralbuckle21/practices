#include<stdio.h>
int main()
{
	int i;
	char a[3],t;

    while(gets(a)!=NULL)//用scanf也可以的。
	{
		for(i=0;i<2;i++)
			if(a[i]>a[i+1])
			{
				t=a[i];
				a[i]=a[i+1];
				a[i+1]=t;
			}
		if(a[0]>a[1])
		{
			t=a[0];
			a[0]=a[1];
			a[1]=t;
		}
	printf("%c %c %c\n",a[0],a[1],a[2]);
		}
	return 0;
}





		
