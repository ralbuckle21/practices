#include<iostream>
using namespace std;
int num[32];
int main()
{
    int k=2;
    for(int i=0;i<=31;i++)
    {
         num[i]=k-1;
         k=2*k;
    }
    int n;
    char mg[32];
    while(true)
    {
        scanf("%s",mg);
        if(mg[0]=='0')
           break;
        n=strlen(mg);
        int sum=0,i=0;
        while(i<n)
        {
            sum=sum+(mg[i]-'0')*num[n-i-1];
            i++;            
        }       
        printf("%d\n",sum);
    }
    system("pause");
    return 0;
}
