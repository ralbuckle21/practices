#include<iostream>
using namespace std;
int num[20];
int maxs=10000000;
void next(int a[20],int m)
{
     int r=m-1;
     if(a[r]-a[0]==r)
     {
         a[r]++;
         for(int i=0;i<r;i++)
           a[i]=num[i];                    
     }    
     else
     {
          int i=0;
          while(a[i]+1==a[i+1] && i<r)
             i++;
          if(i<r)
            a[i]++;
          for(int k=0;k<i;k++)
             a[k]=num[k];    
     }
}
void next1(int a[20],int m)
{
     int r=m-1;
     if(a[r]-a[0]==r)
         a[0]--;   
     else
     {
          int i=0;
          while(a[i]+1==a[i+1] && i<r)
             i++;
          a[i+1]--;
          for(int k=i;k>=0;k--)
             a[k]=a[k+1]-1;    
     }
}
int getsum(int a[20],int b[20],int m)
{
    int sum=0;
    for(int i=0;i<m;i++)
     sum=sum+a[i]*a[i]*b[i];
    return sum;
}
void getresult(int a[20],int b[20],int m,int n)
{
    while(true)
    {
        while(getsum(a,b,m)<n) 
          next(b,m); 
        if(getsum(a,b,m)==n)
        {
            int sum=a[m-1]*a[m-1];
            for(int i=0;i<m;i++)
             sum=sum+2*a[i]*b[i]; 
            if(sum<maxs)
              maxs=sum;               
        } 
        next(a,m);
        while(getsum(a,b,m)>n && (b[m-1]!=num[m-1]))
             next1(b,m);               
        if(getsum(a,b,m)>n)
          break;           
    }  
    if(maxs==10000000)
       cout<<0<<endl;
    else
     cout<<maxs<<endl;   
}
int main()
{
    int n,m,i;
    for(i=1;i<=20;i++)
       num[i-1]=i;
    scanf("%d",&n);
    scanf("%d",&m);
    int a[m],b[m];
    for(i=0;i<m;i++)
      a[i]=b[i]=num[i];
    getresult(a,b,m,n);
    system("pause");
    return 0;
}
