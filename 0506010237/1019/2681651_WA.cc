#include<iostream>
using namespace std;
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
       scanf("%d",&n);
       for(int i=1;;i++)
       {
               if(n>i)
                 n=n-i;
               else
               {
                   int c=0;
                   while(n>=0)
                   {
                       if(c<10)
                         n--;
                       else if(c<100)
                          n=n-2;
                       else if(c<1000)
                         n=n-3;
                       else if(c<10000)
                         n=n-4;
                       else if(c<100000)
                         n=n-5;  
                       else if(c<1000000)
                         n=n-6; 
                       else if(c<10000000)
                         n=n-7;                   
                       else if(c<100000000)
                         n=n-8;
                       else if(c<1000000000)
                         n=n-9;  
                      else 
                         n=n-10; 
                         c++;            
                   } 
                   c--;
                   if(c<10)
                         n++;
                   else if(c<100)
                         n=n+2;
                   else if(c<1000)
                         n=n+3;
                   else if(c<10000)
                         n=n+4;
                   else if(c<100000)
                         n=n+5;  
                   else if(c<1000000)
                         n=n+6; 
                   else if(c<10000000)
                         n=n+7;                   
                   else if(c<100000000)
                         n=n+8;
                   else if(c<1000000000)
                         n=n+9;  
                   else 
                         n=n+10;  
                   int num[12],k=0; 
                   while(c>0)
                   {
                       num[k++]=c%10;
                       c=c/10;          
                   }
                   printf("%d\n",num[k-n-1]);
                   break;
               }
        }          
    }
    system("pause");
    return 0;
}
