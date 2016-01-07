#include<iostream>
using namespace std;
struct node
{
     int c;
     int h;
     int a; 
}block[402];
int f[402][40002]={0};
int n,maxs=0;
int cmp(void const *a,void const *b)
{
     return (*(node *)a).a-(*(node *)b).a;   
}
int main()
{
    scanf("%d",&n);
    block[0].a=block[0].c=block[0].h=0;
    for(int i=1;i<=n;i++)
    {
         scanf("%d %d %d",&block[i].h,&block[i].a,&block[i].c);
         if(block[i].a>maxs) maxs=block[i].a;        
    }
    qsort(block,n+1,sizeof(block[0]),cmp);
    for(int i=1;i<=n;i++)
       for(int j=1;j<=block[i].c;j++)
       {
           int x=j*block[i].h;
           for(int h=1;h<=maxs;h++)
           {
                if(h>=x && h>=f[i-1][h-x]+x && f[i-1][h-x]+x<=block[i].a && f[i-1][h-x]+x>f[i-1][h])  
                    f[i][h]=f[i-1][h-x]+x;
                else
                {
                     f[i][h]=f[i-1][h];
                     if(f[i][h]<f[i][h-1]) f[i][h]=f[i][h-1];
                }   
           }        
       }
    printf("%d\n",f[n][maxs]);
    system("pause");
    return 0;
}
