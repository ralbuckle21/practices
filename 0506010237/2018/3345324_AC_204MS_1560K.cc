#include<iostream>
using namespace std;
int main()
{
    int n,f,i,good=0;
    scanf("%d %d",&n,&f);
    int num[n];
    float b[n],sum[n],best;
    sum[0]=0;
    for(i=1;i<=f;i++)
    {
         scanf("%d",&num[i]);
         sum[i]=num[i]+sum[i-1];                
    }
    b[f]=sum[f]; 
    best=b[f]*1000/f; 
    good=f;
    for(i=f+1;i<=n;i++) 
    { 
         scanf("%d",&num[i]);
         sum[i]=num[i]+sum[i-1];  
         b[i]=b[i-1]+num[i]; 
         good++;
         if((b[i]*1000/good)<((sum[i]-sum[i-f])*1000/f))//动规如果总和均值不如F项均值则剪 
         {
                b[i]=sum[i]-sum[i-f];
                good=f;
         } 
         if((b[i]*1000/good)>best) best = b[i]*1000/good; 
    } 
    printf("%d\n",int(best));
    system("pause");
    return 0;
}
