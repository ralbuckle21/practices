#include<iostream>
using namespace std;
int main()
{
	double sum,s;
	int i,n,k,h;
	while(true)
	{
        cin>>n>>k;
        if(n==0 && k==0)
           break;
		sum=1;
		s=1;
		if(k>n/2) 
          k=n-k;
		h=2;
		int j=1;
		for(i=n;i>=n-k+1;i--)
		{
            sum=sum*i;
            s=s*j;
            j++;                   
        }
        sum=sum/s;
  	   cout<<n<<" things taken "<<k<<" at a time is ";
       printf("%.0lf",sum);  
       cout<<" exactly."<<endl;
	}
    system("pause");
    return 0;
}
