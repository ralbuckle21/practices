#include<iostream>
using namespace std;
int num[100];
int k=0,sum=0;
void fenjie(int n)
{
    int i=2,sign=0; 
    while(i<=n)
    {
         while(n%i==0 && i<=n)
         {
              n=n/i;
              num[k]++;
              sum++;
              sign=1;           
         } 
         if(sign==1)
         {
             k++;
             sign=0;           
         }
         i++;        
    }  
    if(n==1)
      k++;
}
int qiuc(int n)
{
    int x=1;
    for(int i=2;i<=n;i++)
          x=x*i;
    return x;
}
int main()
{
    int n;
    for(int i=0;i<=50;i++)
         num[i]=0;
    while(scanf("%d",&n)!=EOF)
    {
       fenjie(n);
       int h=sum;
       sum=qiuc(sum);
       for(int i=0;i<k;i++)
       {
          sum=sum/qiuc(num[i]);
          num[i]=0;
       }
       printf("%d %d\n",h,sum);
       sum=0;
       k=0;
    }  
    system("pause");
    return 0;
}
