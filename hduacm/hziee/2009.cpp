#include<stdio.h>
#include<math.h>
int main()
{
    int i,m,n;
    float    a[1000],t;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        t=n;
        for(a[0]=n,i=1;i<m;i++)
        {
            a[i]=sqrt(a[i-1]);
            t+=a[i];
        }
        printf("%.2f\n",t);
    }
    return 0;
}

