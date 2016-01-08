#include<stdio.h>
int main()
{
	int m,n,i,j,a[25][25],p,q,s,t;
	while( scanf("%d %d",&m,&n)!=EOF)
	{
		s=0;t=0;q=0;
		for(i=0;i<m;i++)
			for(j=0;j<n;j++)
			{
				scanf("%d",&a[i][j]);
				p=a[i][j]<0 ? -a[i][j] : a[i][j];
				if(p>q)
				{
					q=p;
					s=i;
					t=j;
				}
			}
		printf("%d %d %d\n",s+1,t+1,a[s][t]);
	}
}



				

				
		


