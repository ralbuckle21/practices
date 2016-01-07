#include<iostream>
using namespace std;
int main()
{
    int n,k=1;
    while(true)
    {
       scanf("%d",&n);
       if(n==0) 
         break;
       int num[n],sum=0,count=0;
       for(int i=0;i<n;i++)
       {
           scanf("%d",&num[i]);
           sum=sum+num[i];        
       }        
       sum=sum/n;
       for(int i=0;i<n;i++)
          if(num[i]>sum)
            count=count+num[i]-sum;
       cout<<"Set #"<<k<<endl;
       cout<<"The minimum number of moves is "<<count<<"."<<endl;
       k++;
       cout<<endl;
    }
    system("pause");
    return 0;
}
