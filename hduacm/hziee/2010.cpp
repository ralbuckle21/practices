#include<stdio.h>
int main()
{
    int j,i,m,n,sum,a,b[10],t;
    while(scanf("%d %d",&m,&n)!=EOF&&m>=100&&n<=999)
    {
        for(j=0,i=m;i<=n;i++)
        {
            sum=0;
            a=i/100;
           t=a*a;
           sum+=t*a;
            a=i%100;
            a=a/10;
            t=a*a;
            sum+=a*t;
            a=i%10; 
            t=a*a;
            sum+=a*t;
            if(sum==i)b[j++]=i;
        }
      if(j==0)printf("no");
	  else
		  for(i=0;i<j;i++)
		  {
			  printf("%d",b[i]);
			  if(i!=j-1)printf(" ");
		  }
      printf("\n");
    }
    return 0;
}
