#include<iostream>
using namespace std;
int cmp(const void *a,const void *b)
{
     return *(int *)a -*(int *)b;
}
int main()
{
    long long int n;
    long long int sum=0,cost=0;
    cin>>n;
    long long int num[n];
       for(int i=0;i<n;i++)
       {
          cin>>num[i];
          cost=num[i]+cost;
       }
    if(n==1 || n==0)
      cout<<"0"<<endl;
    else
    {
       qsort(num,n,sizeof(num[0]),cmp);
       for(int i=n-1;i>=1;i--)
       {
         sum=sum+cost;
         cost=cost-num[i];       
       }
       cout<<sum<<endl;
    }
    system("pause");
    return 0;
}
