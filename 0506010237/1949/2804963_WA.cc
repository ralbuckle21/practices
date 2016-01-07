#include<iostream>
using namespace std;
int num[10000];
int main()
{
    int n,v,k,maxs,f;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
       scanf("%d %d",&v,&k);
       maxs=0;   
       for(int j=0;j<k;j++)
       {
           scanf("%d",&f);
           if(num[f-1]>maxs)
             maxs=num[f-1];        
       }  
       num[i]=v+maxs;
    }
    printf("%d\n",num[n-1]);
    system("pause");
    return 0;
}
