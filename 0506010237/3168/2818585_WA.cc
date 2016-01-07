#include<iostream>
#include<math.h>
using namespace std;
typedef struct
{
    int sx;
    int sy;
    int tx;
    int ty; 
    bool visit;     
}Line;
Line line[25000];
int sum=0;
int n,k=0;
int cmp1( const void *a ,const void *b)
{
     return (*(Line *)a).sx > (*(Line *)b).sx ? 1 : -1;
}
int cmp2( const void *a ,const void *b)
{
     return (*(Line *)a).sy > (*(Line *)b).sy ? 1 : -1;
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d %d %d %d",&line[i].sx,&line[i].sy,&line[i].tx,&line[i].ty); 
        line[i].visit=false;       
    }
    qsort(line,n,sizeof(line[0]),cmp1);
    int i=1;
    while(i<n)
    {
         if(line[i].sx==line[k].tx)
         {
             if(line[i].sy<=line[k].ty && line[i].ty>=line[i].sy)
             {
               line[i].visit=true;
               line[k].visit=true; 
             } 
             i++;            
         }
         else
           k++;
         if(k==i)
            i++;            
    }
    qsort(line,n,sizeof(line[0]),cmp2);
    i=1;
    k=0;
    while(i<n)
    {
         if(line[i].sy==line[k].ty)
         {
            if(line[i].sx<=line[k].tx && line[i].tx>=line[i].sx)
            {
             line[i].visit=true;
             line[k].visit=true;
            }                           
             i++;
         }
         else
           k++;
         if(k==i)
            i++;             
    }
    for(i=0;i<n;i++)
      if(line[i].visit==false)
         sum++;
    printf("%d\n",sum);
    system("pause");
    return 0;
}