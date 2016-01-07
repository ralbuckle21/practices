#include<iostream>
#include<math.h>
#define pi 3.1415926
using namespace std;
int c=1;
int main()
{
    int t;
    float R,r,n;
    scanf("%d",&t);
    while(t--)
    {
         scanf("%f %f",&R,&n);
         printf("Scenario #%d:\n",c++);
         r=R*sin(pi/n)/(1+sin(pi/n));
         printf("%.3f\n\n",r);        
    }
    system("pause");
    return 0;
}
