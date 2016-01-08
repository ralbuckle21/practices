#include<stdio.h>
int main()
{
	int n,i,j,k,max;
	//int b[20];
	double u[20][20],l[20][20],temp1,temp2;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
			{
				scanf("%f",&u[i][j]);
				l[i][j]=0;
			}
	//	for(i=0;i<n;i++)
			//scanf("%d",b[i]);
		for(i=0;i<n-1;i++)
		{
			l[i][i]=1;
			max=i;
			temp1=u[i][i]<0 ? -u[i][i] : u[i][i];
			for(j=i+1;j<n;j++)
			{
				temp2=(u[j][i]<0 ?-u[j][i]:u[j][i]);
				if(temp2>temp1)max=j;
			}
			if(max!=i)
				for(j=i;j<n;j++)
				{
				   temp1=u[max][j];
				   u[max][j]=u[i][j];
				   u[i][j]=temp1;
				}
			for(j=i+1;j<n;j++)
			{
			    l[j][i]=u[j][i]/u[i][i];
				for(k=i;k<n;k++)
					u[j][k]=u[j][k]-u[i][k]*l[j][i];
			}
		}
		l[n-1][n-1]=1;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n-1;j++)
				printf("%.2f ",u[i][j]);
			printf("%.2f\n",u[i][j]);
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<n-1;j++)
			printf("%.2f ",l[i][j]);
			printf("%.2f\n",l[i][j]);
		}
	}
	return 0;
}









