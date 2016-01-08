#include<stdio.h>
int  main()
{
	int a,b,c,i,n,m,p;
    scanf("%d",&n);
	while(n--)
	{
		scanf("%d %d %d",&a,&b,&c);
		p=0;
		for(i=1000;i<=9999;i++)
		{
			m=0;
			if(!(i%a))m++;
			if(!((i+1)%b))m++;
			if(!((i+2)%c))m++;
			if(m==3)
			{
				printf("%d",i);
				p=1;
				break;
			}
		}
		if(p==0)printf("Impossible");
		printf("\n");
	}
return 0;
}


