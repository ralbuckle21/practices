#include<iostream>
using namespace std;
int main()
{
     int n,count=0,num[1001],m,i=2,j;
     scanf("%d",&n);
     m=n;
     while(n>=i)
     {
         num[count++]=i;
         n=n-i;
         i++;           
     }
     num[count]=-1;
     for(j=0;j<count;j++)
         if(num[j]+n>num[count-1])
         {
             num[count]=num[j]+n;
             num[j]=-1;
             break;
         }
     for(j=0;j<=count;j++)
        if(num[j]!=-1)
         printf("%d ",num[j]);
     printf("\n");
     system("pause");
     return 0;
}
