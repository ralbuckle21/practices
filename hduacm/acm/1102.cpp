#include<stdio.h>
int main()
{
	int n,i,j,k,max;
	double u[20][20],temp1,temp2,e[20][20],rult;
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
		for(i=0 ;i<n-1;i++)
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
		          goto end;
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
		  {
		    for(k=0;k<n;k++)
				e[i][k]-=e[j][k]*u[i][j];
			u[i][j]=0;
		  }
          for(j=0;j<n;j++)
			   e[i][j]/=u[i][i];
		   u[i][i]=1;
	   }
		for(i=0; i<n-1;i++)
		{
			max=i;
			for(j=i+1;j<n;j++)
			{
				temp1=e[max][max]<0 ? -e[max][max] : e[max][max];
				temp2=(e[j][i]<0 ?-e[j][i]:e[j][i]);
				if(temp2>temp1)max=j;
			}
			if(max!=i)
				for(j=0;j<n;j++)
				{
				   temp1=e[max][j];
				   e[max][j]=e[i][j];
				   e[i][j]=temp1;
				}
			for(j=i+1;j<n;j++)
			{
			    temp1=e[j][i]/e[i][i];
				for(k=i;k<n;k++)
					e[j][k]-=e[i][k]*temp1;
			}
		   for(rult=1,i=0;i<n;i++)
		   rult*=e[i][i];
		   printf("%.4lf\n",rult);	
		}
    end: ;
	}
	return 0;
}