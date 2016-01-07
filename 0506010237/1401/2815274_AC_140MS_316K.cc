#include<iostream>
using namespace std;
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int s=0;
        while(n>=5)
        {
             s=s+n/5;
             n=n/5;           
        }  
        printf("%d\n",s);         
    }
    system("pause");
    return 0;
}
