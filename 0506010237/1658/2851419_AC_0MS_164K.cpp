#include<iostream>
using namespace std;
int main()
{
    int t,num[5],i;
    scanf("%d",&t);
    while(t--)
    {
         for(i=0;i<4;i++)
           scanf("%d",&num[i]);
         if(2*num[2]==num[3]+num[1] && 2*num[1]==num[0]+num[2])
               num[4]=2*num[3]-num[2];
         else
            num[4]=num[3]*num[3]/num[2];
         for(i=0;i<5;i++)
           printf("%d ",num[i]);
           printf("\n");     
    }
    system("pause");
    return 0;
}
