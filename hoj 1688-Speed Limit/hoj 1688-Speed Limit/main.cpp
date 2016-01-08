#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    int n,a,b,ans,pre;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==-1) break;
        ans=0;
        pre=0;
        for(int i=0;i<n;i++)
        {    
            scanf("%d%d",&a,&b);
            ans+=a*(b-pre);
            pre=b;
        }
        printf("%d miles\n",ans);    
    }
}