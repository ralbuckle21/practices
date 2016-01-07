#include<iostream>
using namespace std;
int main()
{
	double sum;
	int i,n,k;
	while(true)
	{
        cin>>n>>k;
        if(n==0 && k==0)
           break;
		sum=1;
		if(k>n/2) 
          k=n-k;
		for(i=1;i<=k;i++)
        {
		    sum=sum*(n-i+1);
			sum=sum/i;
		}
		cout<<n<<" things taken "<<k<<" at a time is ";
        printf("%.0lf",sum);
        cout<<" exactly."<<endl;
	}
    system("pause");
    return 0;
}
