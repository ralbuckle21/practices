#include<stdio.h>
int main()
{
	int m;
	while(scanf("%d",&m)!=EOF)
	   if(m>100||m<0)printf("Score is error!\n");
		else
			switch(m/10)
		{
			case 10:
		    case 9:printf("A\n");break;
		    case 8:printf("B\n");break;
		    case 7:printf("C\n");break;
		    case 6:printf("D\n");break;
		   default:printf("E\n");break;
	}
	return 0;
}



