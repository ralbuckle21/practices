#include<iostream>
using namespace std;
int n,value[101],maxl=0,maxr=10000000,m;
void find(int k,int left,int right,int vleft,int vright)
{
     if(left>m || right>m)
         return; 
     if(abs(vleft-vright)>=abs(maxr-maxl))
        return;
     if(k==n+1)
     {
         if(abs(vleft-vright)<abs(maxr-maxl))
         {
              maxr=vright;
              maxl=vleft;                                   
         }        
     }
     find(k+1,left,right+1,vleft,vright+value[k]);
     find(k+1,left+1,right,vleft+value[k],vright);
}
int main()
{
     scanf("%d",&n);
     m=(n+1)/2;
     for(int i=1;i<=n;i++) scanf("%d",&value[i]);
     find(1,0,0,0,0);
     if(maxl>maxr)
     {
          int tmp=maxl;
          maxl=maxr;
          maxr=tmp;             
     }
     printf("%d %d\n",maxl,maxr);
     system("pause");
     return 0;
}

