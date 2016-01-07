#include<iostream>
using namespace std;
int num[64];
bool mg[64];
int n;
bool find(int m,int k,int len)
{
     if(m==0 && k==0)
         return true;
     if(m==0)
        m=len;
     for(int i=0;i<n;i++)    
     {
          if(!mg[i] && num[i]<=m)
          {
              mg[i]=true;
              if(find(m-num[i],k-1,len))
                 return true;
              mg[i]=false;            
          }        
     }
     return false;
}
int main()
{
    int i,max,sum;
    while(true)
    {
       scanf("%d",&n);
       if(n==0)
         break;
       max=0;
       sum=0;
       for(i=0;i<n;i++)
       {
            scanf("%d",&num[i]);
            sum=sum+num[i];  
            if(max<num[i])
              max=num[i]; 
            mg[i]=false;            
       }
       for(int j=max;j<=sum;j++)
          if((sum%j==0) && find(j,n,j))
           {
             cout<<j<<endl;
             break;
           }
    }
    system("pause");
    return 0;
}
