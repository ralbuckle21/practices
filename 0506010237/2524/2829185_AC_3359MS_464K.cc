#include<iostream>
using namespace std;
int father[50002];
int n,m,a,b,c=1;
int findroot(int p)
{
     while(father[p]!=p)
        p=father[p];
     return p;   
}
int main()
{
    while(true)
    {
         scanf("%d %d",&n,&m);
         if(n==0 && m==0)
           break;
         for(int i=1;i<=n;i++)
             father[i]=i;     
         for(int i=1;i<=m;i++)
         {
             scanf("%d %d",&a,&b); 
             int k1=findroot(a);    
             int k=findroot(b);
             if(k1!=k)
              father[k]=a;
         } 
         int sum=0;   
         for(int i=1;i<=n;i++)
         {
              if(father[i]==i)
                 sum++;   
         }
         printf("Case %d: %d\n",c++,sum);
    }
    system("pause");
    return 0;
}
