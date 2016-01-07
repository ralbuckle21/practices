#include<iostream>
using namespace std;
int main()
{
    int num[10002];
    int k=1,i=1,j;
    num[0]=0;  
    while(i<=10001)
    {
       j=1;
        while(j<=k && i<=10001)
        {
            num[i]=num[i-1]+k;
            i++;    
            j++;     
        }       
        k++;      
    }
    int n;
    while(true)
    {
        scanf("%d",&n);
        if(n==0)
          break;
        printf("%d %d\n",n,num[n]);
    }
    system("pause");
    return 0;
}
