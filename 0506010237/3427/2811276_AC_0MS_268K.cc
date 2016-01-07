#include<iostream>
using namespace std;
int main()
{
    int n,l,t,sum=0;
    while(scanf("%d %d",&n,&l)!=EOF)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d",&t);
            t=t%l;
            if(t!=0 && sum<l-t)
              sum=l-t;
        }        
        printf("%d\n",sum);         
    }
    system("pause");
    return 0;
}
