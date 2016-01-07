#include<iostream>
using namespace std;
int main()
{
    int mg[102];
    int t,n,i,j;
    scanf("%d",&t);
    while(t--)
    {
         scanf("%d",&n);
         for(i=1;i<=n;i++)
              mg[i]=1;
         for(i=2;i<=n;i++)
             for(j=i;j<=n;j=j+i)
                 if(j%i==0)
                 {
                    if(mg[j]==1)
                       mg[j]=0;
                    else if(mg[j]==0)
                       mg[j]=1;         
                 }  
         int c=0;
         for(i=1;i<=n;i++)
           if(mg[i]==1)
             c++;
         printf("%d\n",c);                                  
    }
    system("pause");
    return 0;
}
