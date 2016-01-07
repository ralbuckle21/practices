#include<iostream>
using namespace std;
int main()
{
    int n,i,max,sum,x;
    while(true)
    {
       scanf("%d",&n);
       if(n==0)
         break;
       max=0;
       sum=0;
       for(i=0;i<n;i++)
       {
            scanf("%d",&x);
            if(x>max)
             max=x;
            sum=sum+x;               
       }
       for(int j=max+1;j<=sum;j++)
         if(sum%j==0)
         {
            cout<<j<<endl;
            break;
         }
    }
    system("pause");
    return 0;
}
