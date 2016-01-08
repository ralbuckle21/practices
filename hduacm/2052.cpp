#include<stdio.h>
int main()
{
	int m,n,i,j;
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		for(i=0;i<m+2;i++)
		{
			if(i==0||i==m+1)printf("+");
			else printf("|");
			for(j=1;j<=n;j++)
				if(i==0||i==m+1)printf("-");
				else printf(" ");
			if(i==0||i==m+1)printf("+\n");
			else printf("|\n");
		}
		printf("\n");
	}
	return 0;
}
			
			