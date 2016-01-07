#include<iostream>
using namespace std;
int main()
{
	double sum;
	int n,k;
	while(true)
	{
        cin>>n>>k;
        if(n==0 && k==0)
           break;
		sum=1;
		if(k>n/2) 
          k=n-k;
		for(int i=n;i>=n-k+1;i--)
		{
            sum=sum*i/(k+i-n);
        }
  	    printf("%d things taken %d at a time is %.0lf exactly.\n",n,k,sum);
	}
    system("pause");
    return 0;
}
