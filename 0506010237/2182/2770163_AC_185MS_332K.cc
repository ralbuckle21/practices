#include<iostream>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    int rank[n],num[n];
    rank[0]=0;
    num[0]=1;
    for(int i=1;i<n;i++)
    {
       scanf("%d",&rank[i]);
       num[i]=i+1;        
    }
    for(int i=n-1;i>=0;i--)
    {
         int j=0,k=0;
         while(num[j]==10000)
           j++;
         while(k<rank[i])
         {
              j++; 
             if(num[j]!=10000)
               k++;               
         }       
         rank[i]=num[j];
         num[j]=10000;
    }
    for(int i=0;i<n;i++)
       printf("%d\n",rank[i]);
    system("pause");
    return 0;
}
