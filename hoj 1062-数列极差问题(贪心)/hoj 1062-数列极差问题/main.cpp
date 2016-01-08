#include<iostream>
#include <algorithm>
using namespace std;
long long find_max(long long *num,int n)
{
	if(n==1) return num[0];
	sort(num,num+n);
	reverse(num,num+n);
	num[n-2]=num[n-1]*num[n-2]+1;
	return find_max(num,n-1);
}
long long find_min(long long *num,int n)
{
	if(n==1) return num[0];
	sort(num,num+n);
	num[n-2]=num[n-1]*num[n-2]+1;
	return find_min(num,n-1);
}
int main()
{
	int n;
	long long max,min;
	while(cin>>n)
	{
		if(n==0) break;
		long long *num=new long long[n];
	    long long *numcpy=new long long[n];
		for(int i=0;i<n;i++)
		{
			cin>>num[i];
			numcpy[i]=num[i];
		}
		sort(num,num+n);
		sort(numcpy,numcpy+n);
		reverse(numcpy,numcpy+n);
		cout<<(find_max(numcpy,n)-find_min(num,n))<<endl;
	}
}