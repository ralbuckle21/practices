#include<stdio.h>
#include<math.h>
int main()
{
	int x,y,i,t,j,m;
	while(scanf("%d %d",&x,&y)!=0&&x<y)
	{
		for(m=0,i=x;i<=y;i++)
		{
			t=i*(i+1)+41;   
			for(j=2;j<=sqrt(t);j++)
				if(t%j==0)m=1;
		}
		if(m==0)printf("OK\n");
		else
			printf("Sorry\n");
	}
 return 0;
}


