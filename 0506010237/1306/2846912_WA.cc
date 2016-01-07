#include<iostream>
using namespace std;
int main()
{
	long long int sum;
	int i,n,k,h;
	while(true)
	{
        cin>>n>>k;
        if(n==0 && k==0)
           break;
		sum=1;
		if(k>n/2) 
          k=n-k;
		h=2;
		for(i=n;i>=n-k+1;i--)
		{
            sum=sum*i;
            while(sum%h==0 && h<=k)
            {
                     sum=sum/h;
                     h++;   
            }                     
        }
  	   cout<<n<<" things taken "<<k<<" at a time is "<<sum<<" exactly."<<endl;
	}
    system("pause");
    return 0;
}
