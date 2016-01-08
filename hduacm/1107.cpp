#include<stdio.h>
float a[500000];
typedef struct rult
{
     int  min;
	 int max;
}RULT;

RULT search(RULT rult);
int main()
{
	int n,i;
	RULT rult;
	while(scanf("%d",&n),n>0)
	{
		rult.min=0;
		rult.max=n-1;
		for(i=0;i<n;i++)
			scanf("%f",&a[i]);
		rult=search(rult);
        printf("%.0f\n",a[rult.min]);
		
	}
	return 0;
}

RULT search(RULT rult)
{
   int mid;
   RULT rult1,rult2;
   if(rult.max-rult.min==1)
	   if(a[rult.max]>a[rult.min])return rult;
	   else
	   {
		   mid=rult.max;
		   rult.max=rult.min;
		   rult.min=mid;
		   return rult;
	   }
   else
   {
	   mid=(rult.max+rult.min)/2;
	   rult1.max=mid;
	   rult1.min=rult.min;
	   rult2.min=mid+1;
	   rult2.max=rult.max;
	   rult1=search(rult1);
	   rult2=search(rult2);
	   if(a[rult1.max]<a[rult2.max])
	   {
	   
		   if(a[rult2.min]>a[rult1.max])
			   a[rult1.min]=a[rult2.min];
		   else a[rult1.min]=a[rult1.max];
		   a[rult1.max]=a[rult2.max];
	   }
	   else
		   if(a[rult2.max]>a[rult1.min])
			   a[rult1.min]=a[rult2.max];
		   return rult1;
   }
}