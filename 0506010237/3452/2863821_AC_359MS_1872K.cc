#include<iostream>
using namespace std;
typedef struct
{
      int sign;  //记录车号
      int s;   //记录所去铁道  
}node;
node mg[200000];
int num[200003];
int x=1,n,m,ok=1;
int cmp(const void *a,const void *b)
{
    return (*(node *)a).sign-(*(node *)b).sign;
}
int main()
{
    int i,k;
    while(true)
    {
       scanf("%d %d",&n,&m);
       if(n==0 && m==0)
          break;
       scanf("%d",&mg[0].sign);
       num[x++]=mg[0].sign;
       mg[0].s=1;
       for(i=1;i<n;i++)
       {
            k=1;
            scanf("%d",&mg[i].sign);
            if(ok==0)
               continue;
            while(k<x && mg[i].sign<num[k])
                k++;                
            if(k==x)
            {
                 x++;
                 if(k>m) 
                   ok=0;       
            }
            num[k]=mg[i].sign;
            mg[i].s=k;
       }
       if(ok==0)
          printf("Transportation failed\n");
       else
       {
           for(i=0;i<n;i++)
              printf("%d ",mg[i].s);
              printf("\n"); 
           qsort(mg,n,sizeof(mg[0]),cmp);  
           for(i=0;i<n;i++)
              printf("%d ",mg[i].s);
              printf("\n");  
       }
       ok=1;
    }
    system("pause");
    return 0;
}
