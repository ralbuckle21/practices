#include<iostream>
using namespace std;
int fen(int n)
{
    int i,p=0;
    for(i=2;i<=n/2;i++)
      if(n%i==0)
        p++;
    p++;
    return p;
}
int main()
{
    int n,m,k,i;
    long long int sum1=1,sum2=1;
    scanf("%d %d",&n,&m);
    if(m==1)
      k=0;
    else
     k=fen(m);
    for(i=1;i<=n;i++)
    {
        sum1=sum1*m;
        sum2=sum2*k;                 
    }
    cout<<sum1-sum2<<endl;
    system("pause");
    return 0;
}
