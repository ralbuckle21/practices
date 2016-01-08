#include<stdio.h>
int main()
{
	int year,day,month,i;
	int arr[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	while(scanf("%d/%d/%d",&year,&month,&day)!=EOF)
	{
		for(i=0;i<month-1;i++)
			day+=arr[i];
		if(month>2&&!(year%4)&&(year%100 ||!(year%400)))
			day++;
		printf("%d\n",day);
	}
	return 0;
}


	    
		