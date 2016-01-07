#include<iostream>
using namespace std;
int main()
{
    int n,h,maxs=0;
    while(true)
    {
        scanf("%d",&n);
        if(n==0)
          break;
        scanf("%d",&h);
        h=h*12;
        int numf[n],numd[n],time[n],counts[n];
        time[0]=0;
        counts[0]=0;
        maxs=0;
        for(int i=0;i<n;i++)
          scanf("%d",&numf[i]);
        for(int i=0;i<n;i++)
           scanf("%d",&numd[i]);
        for(int i=1;i<n;i++)
        {
           scanf("%d",&time[i]);
           time[i]=time[i-1]+time[i];
           counts[i]=0;
        }
        for(int i=0;i<n;i++)
        {
              int max=0,c=h-time[i],f[n],count[n];
              for(int j=0;j<=i;j++)
              {
                  f[j]=numf[j];
                  count[j]=0;
              }
              while(c>0)
              {
                  int m=0,s=0;
                  for(int k=0;k<=i;k++)
                       if(f[k]>m)
                       {
                           m=f[k];
                           s=k;          
                       }  
                  max=max+m;
                  f[s]=f[s]-numd[s];
                  c--; 
                  count[s]++;             
              }       
              if(max>maxs)
              {
                for(int j=0;j<=i;j++)
                  counts[j]=count[j];
                  maxs=max;
              }            
        }
        if(maxs==0)
           counts[0]=h;
        for(int j=0;j<n-1;j++) 
           printf("%d%c ",counts[j]*5,',');
        printf("%d\n",counts[n-1]*5);
        printf("%s%d\n\n","Number of fish expected: ",maxs);     
    }
    system("pause");
    return 0;
}
