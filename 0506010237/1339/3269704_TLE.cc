#include<iostream>
using namespace std;
typedef struct
{
    int value;
    int maxvalue;
    int sign;
}node;
node mg[200000];
int main()
{
     int i,j,t,n,m;
     scanf("%d",&t);
     while(t--)
     {
        scanf("%d",&n);
        m=2*n-1;
        for(i=0;i<n;i++)
        {
            scanf("%d",&mg[i].value);
            mg[i].sign=0;
        }
        int mn1,mn2,v1,v2;
        for(i=n;i<m;i++)
        {
           mn1=10000000;
           mn2=10000000;
           v1=v2=-1;
           for(j=0;j<i;j++)
           {
                 if(!mg[j].sign)
                 {
                      if(mg[j].value<mn1)
                      {
                         v2=v1;
                         mn2=mn1;
                         v1=j;
                         mn1=mg[j].value;
                       }
                       else if(mg[j].value<mn2)
                       {
                         v2=j;
                         mn2=mg[j].value;
                       }
                 }
           }
           mg[i].value=mg[v1].value+mg[v2].value;
           mg[i].maxvalue=mg[i].value;
           mg[v1].sign=mg[v2].sign=true;
           mg[i].sign=0;
           if(v1>=n) mg[i].maxvalue+=mg[v1].maxvalue;
           if(v2>=n) mg[i].maxvalue+=mg[v2].maxvalue;
        }
        printf("%d\n",mg[m-1].maxvalue);
     }
     system("pause");
     return 0;
}

