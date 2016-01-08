#include<stdio.h>
int main()
{
	int n,i,j,k,max,label[20];
	double u[20][20],l[20][20],temp1,temp2,b[20], x[20],y[20];
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
			{
				scanf("%lf",&u[i][j]);
				l[i][j]=0;
			}
		for(i=0;i<n;i++)
		{
		   scanf("%lf",&b[i]);
		   label[i]=i;
		}
		// LU分解
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
				   label[i]=max;
				   label[max]=i;
				}
			for(j=i+1;j<n;j++)
			{
			    l[j][i]=u[j][i]/u[i][i];
				for(k=i;k<n;k++)
					u[j][k]=u[j][k]-u[i][k]*l[j][i];
			}
		}
		// 求解
		l[n-1][n-1]=1;
		for(i=0;i<n;i++)
			for(y[i]=b[label[i]],j=0;j<i;j++)
				y[i]-=l[i][j]*y[j];

		x[n-1]=y[n-1]/u[n-1][n-1];
    	for(i=n-2;i>=0;i--)
		{ 
            for(x[i]=y[i],j=i+1;j<n;j++)
				x[i]-=u[i][j]*x[j];
			x[i]/=u[i][i];
		}
        for(i=0;i<n;i++)
		   printf("%.2lf\n",x[i]);
	}
	return 0;
}