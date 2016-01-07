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
          scanf("%d",&num[i]);
    if(n==1 || n==0)
      cout<<"0"<<endl;
    else
    {
       qsort(num,n,sizeof(num[0]),cmp);
       int i=1;
       while(i<n)
       {
         num[i]=num[i-1]+num[i];
         sum=sum+num[i]; 
         int k=i;
         while(num[k]>num[k+1] && k<n-1)
         {
             int temp=num[k];
             num[k]=num[k+1];
             num[k+1]=temp;
             k++;                      
         }  
         i++;   
       }
       cout<<sum<<endl;
    }
    system("pause");
    return 0;
}
