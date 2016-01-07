#include<iostream>
using namespace std;
typedef struct
{
    int h;
    int c;
    int a;       
}build;
int mg[401][11];
int cmp(const void *c,const void *d)
{
    return (*(build *)c).a-(*(build *)d).a;    
}
void f(int k,build bd[401])
{
    int j,i,x=bd[k].c,y=bd[k-1].c;
    for(i=0;i<=x;i++)
    {
        int max=0,t=bd[k].h*i;
        for(j=0;j<=y;j++)
        {
            if(t+mg[k-1][j]<=bd[k].a && t+mg[k-1][j]>max)
               max=t+mg[k-1][j];                 
        }                 
        mg[k][i]=max;
    }    
}
int main()
{
     int i,n;
     build bd[401];
     scanf("%d",&n);    
     for(i=0;i<n;i++)
     {
         scanf("%d %d %d",&bd[i].h,&bd[i].a,&bd[i].c);                
     }
     qsort(bd,n,sizeof(bd[0]),cmp);
     for(i=0;i<=bd[0].c;i++)
     {
        if(bd[0].h*i<=bd[0].a)
          mg[0][i]=bd[0].h*i;
        else
        {
           bd[0].c=i-1;
           break;
        }
     }
     for(i=1;i<n;i++)
         f(i,bd);
     int max=0;
    for(i=0;i<=bd[n-1].c;i++)
        if(mg[n-1][i]>max)
          max=mg[n-1][i];
     printf("%d\n",max);
     system("pause");
     return 0;   
}
