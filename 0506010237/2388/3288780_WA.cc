#include<iostream>
using namespace std;
int main()
{
     int n;
     long long int num[10000];
     scanf("%d",&n);
     for(int i=0;i<n;i++)cin>>num[i];
     for(int i=1;i<n;i++)
        for(int j=i;j<n;j++)
        {
            if(num[j-1]>num[j])
            {
                   int tmp=num[j];
                   num[j]=num[j-1];
                   num[j-1]=tmp;               
            }        
        }
     cout<<num[n/2]<<endl;
     system("pause");
     return 0;
}
