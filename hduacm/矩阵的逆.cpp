#include<stdio.h>
int main()
{
	int n,i,j,k,max,label;
	double u[20][20],temp1,temp2,e[20][20];
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				scanf("%lf",&u[i][j]);
	    for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				if(i!=j)
					e[i][j]=0;
				else 
					e[i][j]=1;
		// 矩阵变换求逆
		label=1;
		for(i=0 ;label && i<n-1;i++)
		{
			max=i;
			for(j=i+1;j<n;j++)
			{
				temp1=u[max][max]<0 ? -u[max][max] : u[max][max];
				temp2=(u[j][i]<0 ?-u[j][i]:u[j][i]);
				if(temp2>temp1)max=j;
			}
			if(max!=i)
				for(j=0;j<n;j++)
				{
				   temp1=u[max][j];
				   u[max][j]=u[i][j];
				   u[i][j]=temp1;
				   temp1=e[max][j];
				   e[max][j]=e[i][j];
				   e[i][j]=temp1;
				}
			for(j=i+1;j<n;j++)
			{
				if(u[i][i]==0)
				{
			      printf("no answer\n");
		          break;
				  label=0;
				}
				temp1=u[j][i]/u[i][i];
				for(k=0;k<n;k++)
				{
					if(k>=i)u[j][k]-=u[i][k]*temp1;
					e[j][k]-=e[i][k]*temp1;
				}
			}
		}
	//继续变换
	   for(i=0;i<n;i++)
		   e[n-1][i]/=u[n-1][n-1];
	   u[n-1][n-1]=1;
	   for(i=n-2;i>=0;i--)
		{
	      for(j=n-1;j>i;j--)
		    for(k=0;k<n;k++)
			{
				if(k>=j)
					u[i][k]-=u[j][k]*u[i][j];
				e[i][k]-=e[j][k]*u[i][j];
			}
          for(j=0;j<n;j++)
			   e[i][j]/=u[i][i];
		   u[i][i]=1;
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<n-1;j++)
				printf("%.2lf ",e[i][j]);
			printf("%.2lf\n",e[i][j]);
		}



		//依次求解
	/*	rult[n-1]=u[n-1][n]/u[n-1][n-1];
    	for(i=n-2;i>=0;i--)
		{ 
            rult[i]=u[i][n];
			for(j=i+1;j<n;j++)
				rult[i]-=u[i][j]*rult[j];
			rult[i]/=u[i][i];
		}
		for(i=0;i<n;i++)
		   printf("%.2lf\n",rult[i]);*/
	}
	return 0;
}