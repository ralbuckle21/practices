#include<iostream>
using namespace std;
int gcd(int a,int b)
{
    while(b!=0)
    {
        int r=a%b;
        a=b;
        b=r;           
    }    
    return a;
}
int main()
{
    int n,count;
    while(scanf("%d",&n)!=EOF)
    {
        count=0;
        int mg[n+1];
        for(int i=1;i<=n;i++)
           mg[i]=0;
        for(int a=1;a<=n-2;a++)
         for(int b=a+1;b<=n-1;b++)
            for(int c=b+1;c<=n;c++)
              if(c*c==a*a+b*b)
              {
                   if(gcd(a,b)==1 || gcd(a,c)==1 || gcd(b,c)==1)
                       count++;
                    mg[a]=mg[b]=mg[c]=1;                  
              }
        int c=0;
        for(int i=1;i<=n;i++)
             if(mg[i]==0)
               c++;
        printf("%d %d\n",count,c);                   
    }
    system("pause");
    return 0;
}
