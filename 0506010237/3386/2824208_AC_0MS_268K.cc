#include<iostream>
using namespace std;
int outr1,inr1,outr2,inr2,r;
void getresult()
{
     if(outr1>r || outr2>r)
     {
          printf("No\n");
          return;              
     }
     if(outr1+outr2<=r)
     {
          printf("Yes\n");
          return;                              
     }
     if(outr1<=inr2)
     {
          printf("Yes\n");
          return;                      
     }
     if(outr2<=inr1)
     {
          printf("Yes\n");
          return;                      
     }
     printf("No\n");
}
int main()
{
    scanf("%d %d %d %d %d",&outr1,&inr1,&outr2,&inr2,&r);
    getresult();
    system("pause");
    return 0;
}
