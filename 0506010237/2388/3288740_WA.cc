#include<iostream>
using namespace std;
int main()
{
     int n,num[10000];
     scanf("%d",&n);
     for(int i=0;i<n;i++)scanf("%d",&num[i]);
     for(int i=1;i<n;i++)
        for(int j=i;j<n;j++)
        {
            if(num[i-1]>num[i])
            {
                   int tmp=num[i];
                   num[i]=num[i-1];
                   num[i-1]=tmp;               
            }        
        }
     cout<<num[n/2]<<endl;
     system("pause");
     return 0;
}
