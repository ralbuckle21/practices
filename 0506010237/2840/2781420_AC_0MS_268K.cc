#include<iostream>
using namespace std;
int main()
{
    int t,h,m,k;
    char c[8];
    scanf("%d",&t);
    while(t--)
    {
         scanf("%s",c);
         h=3;
         m=c[0]-'0';
         if(c[1]==':')
           h=2;
         else
           m=m*10+c[1]-'0'; 
         if(c[h]!='0' || c[h+1]!='0')
         {
             printf("0\n");
             continue;             
         }     
         k=(m+12)%24;
         if(k==0)
           k=24;
         printf("%d\n",k);  
    }
    system("pause");
    return 0;
}
