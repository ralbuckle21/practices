#include<stdio.h>
int main()
{
	int n,i,j,k,max;
	double u[20][21],temp1,temp2,rult[20];
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				scanf("%lf",&u[i][j]);
		for(i=0;i<n;i++)
			scanf("%lf",&u[i][n]);
		// 矩阵变换上三角
		for(i=0;i<n-1;i++)
		{
			max=i;
			temp1=u[i][i]<0 ? -u[i][i] : u[i][i];
			for(j=i+1;j<n;j++)
			{
				temp2=(u[j][i]<0 ?-u[j][i]:u[j][i]);
				if(temp2>temp1)max=j;
			}
			if(max!=i)
				for(j=i;j<=n;j++)
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
		rult[n-1]=u[n-1][n]/u[n-1][n-1];
    	for(i=n-2;i>=0;i--)
		{ 
            rult[i]=u[i][n];
			for(j=i+1;j<n;j++)
				rult[i]-=u[i][j]*rult[j];
			rult[i]/=u[i][i];
		}
		for(i=0;i<n;i++)
		   printf("%.2lf\n",rult[i]);
	}
	return 0;
}