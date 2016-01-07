#include<iostream>
using namespace std;
typedef struct
{
    int value;
    int maxvalue;
    bool sign;
}node;
node mg[200000];
int cmp(const void *a,const void *b)
{
     return (*(node *)a).value-(*(node *)b).value;   
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
        {
           scanf("%d",&mg[i].value);
           mg[i].sign=0;
        }
        qsort(mg,n,sizeof(mg[0]),cmp);
        x=0;
        node tmp;
        for(i=n;i<m;i++)
        {
           tmp.value=mg[x].value+mg[x+1].value;
           tmp.maxvalue=tmp.value;
           tmp.sign=1;
           if(mg[x].sign) tmp.maxvalue+=mg[x].maxvalue;
           if(mg[x+1].sign) tmp.maxvalue+=mg[x+1].maxvalue;
           int h=++x;
           h++;
           while(h<n && mg[h].value<tmp.value)
           {
                 mg[h-1]=mg[h];
                 h++;                            
           } 
           h--;
           mg[h]=tmp;
        }
        printf("%d\n",tmp.maxvalue);
     }
     system("pause");
     return 0;
}


