#include<stdio.h>
int main()
{
	int n,i,j,k,max;
	double u[20][20],temp1,temp2,rult;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				scanf("%lf",&u[i][j]);
		// 矩阵变换上三角
		for(i=0;i<n-1;i++)
		{
			max=i;
			for(j=i+1;j<n;j++)
			{
                temp1=u[i][i]<0 ? -u[i][i] : u[i][i];
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
			    temp1=u[j][i]/u[i][i];
				for(k=i;k<=n;k++)
					u[j][k]=u[j][k]-u[i][k]*temp1;
			}
		}
		//依次求解
		for(rult=1,i=0;i<n;i++)
		   rult*=u[i][i];
		printf("%.4lf",rult);
	}
	return 0;
}