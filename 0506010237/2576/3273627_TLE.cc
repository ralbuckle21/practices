#include<iostream>
using namespace std;
int n,value[101],maxl=0,maxr=10000000,m=0,vc=100000000,sum=0;
void find(int k,int left,int right,int vleft,int vright,int r)
{
     if(left>m || right>m)  return; 
     if(vleft-vright-r>=vc || vright-vleft-r>=vc) return;
     if(k==n+1)
     {
         if(abs(vleft-vright)<vc)
         {
              vc=abs(vleft-vright);
              maxr=vright;
              maxl=vleft;                                   
         }        
     }
     find(k+1,left,right+1,vleft,vright+value[k],r-value[k]);
     find(k+1,left+1,right,vleft+value[k],vright,r-value[k]);
}
int main()
{
     scanf("%d",&n);
     m=(n+1)/2;
     for(int i=1;i<=n;i++)
     {
              scanf("%d",&value[i]);
              sum+=value[i];
     }
     find(1,0,0,0,0,sum);
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