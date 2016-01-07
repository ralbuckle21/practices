#include<iostream>
using namespace std;
int sum;
void tback(int n,int k)
{
     if(n==k || k==0)
     {
       printf("1\n");
       return;
     }
     int x1=0,x2=0;
     for(int i=1;i<=k;i++)
     {
           int h=i;
           while(h%2==0)
           {
                x2++;
                h=h/2;      
           }        
     }        
     for(int i=n-k+1;i<=n;i++)
     {
          int h=i;
           while(h%2==0)
           {
                x1++;
                if(x1>=x2)
                {
                     printf("0\n");      
                     return;    
                }
                h=h/2;      
           }    
     }
     printf("1\n");
}
int main()
{
    int n,k;
    while(scanf("%d %d",&n,&k)!=EOF)      
    { 
         if(k>n/2)          
             k=n-k;           
         tback(n,k);
    }        
    system("pause");
    return 0;
}
