#include<iostream>
using namespace std;
int num[6],ok=0,sum=0,c=1;
void getresult(int t,int x)
{
     if(ok==1)
       return;
     if(x==sum)
     {
        ok=1;
         return;         
     }
     if(t<=0)
       return;
     for(int i=num[t-1];i>=0;i--)
     {
         if(i*t+x<=sum)
           getresult(t-1,i*t+x);        
     }
}
int main()
{
    while(true)
    {
        sum=0;
        for(int i=0;i<6;i++)
        {
           scanf("%d",&num[i]);
           num[i]=num[i]%30;
           sum=num[i]*(i+1)+sum;
        }
        if(sum==0)
          break;
        printf("Collection #%d:\n",c++);
        if(sum%2)
        {
          printf("Can't be divided.\n");
          continue;
        }
        sum=sum/2;
        for(int i=num[5];i>=0;i--)
        {
                if(6*i<=sum)
                {
                    getresult(5,6*i);            
                }       
        }     
        if(ok==1)
            printf("Can be divided.\n");
        else
           printf("Can't be divided.\n");
        ok=0;         
    }
    system("pause");
    return 0;
}
