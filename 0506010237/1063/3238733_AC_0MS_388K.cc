#include<iostream>
using namespace std;
int main()
{
     int num=0,n,t,c;
     scanf("%d",&t);
     while(t--)
     {
         scanf("%d",&n);
         if(n%2)
         {
                 for(int i=1;i<=n;i++) scanf("%d",&c);
                 printf("YES\n");
         }
         else
         {
                for(int i=1;i<=n;i++)
                {
                      scanf("%d",&c);
                      if(c==0)
                      {
                            if(i%2) num++;
                            else num--;          
                      }        
                }
                if(abs(num)<2) printf("YES\n");
                else printf("NO\n");     
         }          
         num=0;
     }
     system("pause");
     return 0;
}
