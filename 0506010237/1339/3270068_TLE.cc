#include<iostream>
using namespace std;
int mg[100000];
int cmp(const void *a,const void *b)
{
     return (*(int *)a)-(*(int *)b);   
}
int main()
{
     int i,j,t,n,m,x;
     scanf("%d",&t);
     while(t--)
     {
        scanf("%d",&n);
        m=2*n-1;
        for(i=0;i<n;i++)
           scanf("%d",&mg[i]);
        qsort(mg,n,sizeof(mg[0]),cmp);
        x=0;
        int tmp,ss=0;
        if(n==1) ss=mg[0];
        else if(n>1)
        for(i=n;i<m;i++)
        {
           tmp=mg[x]+mg[x+1];
           ss+=tmp;
           int h=++x;
           h++;
           while(h<n && mg[h]<tmp)
           {
                 mg[h-1]=mg[h];
                 h++;                            
           } 
           h--;
           mg[h]=tmp;
        }
        printf("%d\n",ss);
     }
     system("pause");
     return 0;
}


