#include<iostream>
using namespace std;
int main()
{
    int t,a,b;
    scanf("%d",&t);
    while(t--)
    {
       scanf("%d %d",&a,&b);
       if(a>=b)
         printf("MMM BRAINS\n");
       else
         printf("NO BRAINS\n");       
    }
    system("pause");
    return 0;
}
