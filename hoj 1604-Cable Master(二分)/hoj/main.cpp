#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;
int main()
{
      cout<<setiosflags(ios::fixed)<<setprecision(2);
      long long  n,k;
      long long  l=0,r=100000000000,mid;
      while (cin>>n>>k && n!=0 && k!=0) //n是库存的电缆数，k是需要的电缆段数
      {
          double *s=new double[n];
		  long long *si=new long long [n];
		  long long *sf=new long long [n];
		  long long *ss=new long long [n];
          for(int i=0;i<n;i++)
		  {
              cin>>s[i];
		      si[i]=(long long)s[i];
			  sf[i]=long long ((s[i]-(double)si[i])*100+0.1);
			  ss[i]=100*si[i]+sf[i];
		  }
          while (l!=r)
          {
             mid=(l+r+1)/2;
             long long sum=0;
             for(long long i=0;i<n;i++)
                 sum+=long long(ss[i]/mid);
             if(sum<k)
                 r=mid-1;
             else
                 l=mid;
          }
           cout<<double(l/100.00)<<endl;
		   l=0,r=1000000000000;
       }
      return 0;
}
