#include<iostream>
using namespace std;
int cmp(const void *a,const void *b)
{
     return *(int *)a -*(int *)b;
}
int main()
{
    int n;
    long long int sum=0,cost=0;
    scanf("%d",&n);
    int num[n];
    for(int i=0;i<n;i++)
    {
       scanf("%d",&num[i]);
       cost=num[i]+cost;
    }
    qsort(num,n,sizeof(num[0]),cmp);
    for(int i=n-1;i>=1;i--)
    {
         sum=sum+cost;
         cost=cost-num[i];       
    }
    if(n==1)
      cout<<0<<endl;
    else
      cout<<sum<<endl;
    system("pause");
    return 0;
}
