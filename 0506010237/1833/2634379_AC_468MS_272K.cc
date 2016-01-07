#include<iostream>
using namespace std;
int num[1024];
void next(int k,int n)
{
    for(int i=1;i<=k;i++)
    {
        int j=n-1;
        while(num[j]>num[j+1] && j>=0)
          j=j-1;
        if(j>=0)
        {
           int k=n;
           while(num[j]>num[k])
             k--;
           swap(num[j],num[k]);
        }
        int r=n;
        int s=j+1;
        while(r>s)
        {
          swap(num[r],num[s]);
          r--;
          s++;
        }      
    } 
    for(int i=0;i<=n;i++) 
     printf("%d ",num[i]);
     printf("\n");  
}
int main()
{
    int t,n,k;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
       scanf("%d %d",&n,&k);
       for(int j=0;j<n;j++)
        scanf("%d",&num[j]);
       next(k,n-1);        
    }
    system("pause");
    return 0;
}
