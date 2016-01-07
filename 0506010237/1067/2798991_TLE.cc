#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int a,b;
    while(scanf("%d %d",&a,&b)!=EOF)
    {
       if(a<b)
       {
         int c=a;
         a=b;
         b=c;       
       }  
       int k=1;
       while(b>(int)((1+sqrt(5))*k/2))
          k++;
         if(b==(int)((1+sqrt(5))*k/2) && a==b+k)
           printf("0\n");
         else
           printf("1\n");            
    }
    system("pause");
    return 0;
}
