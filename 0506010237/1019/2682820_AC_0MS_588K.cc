#include<iostream>
using namespace std;
long long key[35000]={0};
int getDigit(int n)
{
      int digit=1;
      while(n/10)
      {
          n=n/10;
          digit++;
      } 
      return digit;
}      
void init()
{
      key[0]=0;
      for(int i=1; i<35000; i++)
        key[i]=key[i-1]+getDigit(i);
} 
void getresult(int c,int n)
{
       int num[12],k=0;
       while(c>0)
       {
          num[k++]=c%10;
          c=c/10;          
       }
       printf("%d\n",num[k-n]);
}
int main()
{
    int t;
    long long sum,n,i;
    init();
    scanf("%d",&t);
    while(t--)
    {
       cin>>n;
       i=1,sum=0;
       while(n>=sum+key[i])
       {
         sum=sum+key[i];
         i++;
       }        
       if(n==sum)
          printf("%d\n",(i-1)%10);
       else
       {
            n=n-sum;
            for(i=1; key[i]<=n; i++);
               n=n-key[i-1];
            if(n!=0) 
            {
               int num=i;
               n=getDigit(num)-n;
               for(i=1; i<=n; i++)
                 num=num/10;
               printf("%d\n",num%10);
            }
            else 
               printf("%d\n",(i-1)%10); 
       } 
    }
    system("pause");
    return 0;
}