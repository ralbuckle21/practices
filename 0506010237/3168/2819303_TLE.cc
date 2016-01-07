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
Line line[25001];
int sum=0;
int n,k=0;
int cmp1( const void *a ,const void *b)
{
     return (*(Line *)a).sx - (*(Line *)b).sx ;
}
int cmp2( const void *a ,const void *b)
{
     return (*(Line *)a).sy -(*(Line *)b).sy;
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
    for(int i=1;i<n;i++)
    {
         k=i-1;
         while(line[i].sx>=line[k].tx && k>=0)
         {
             if(line[i].sx==line[k].tx && line[i].sy<=line[k].ty && line[i].ty>=line[i].sy)
             {
               line[i].visit=true;
               line[k].visit=true; 
               break;
             } 
             k--;        
         }           
    }
    qsort(line,n,sizeof(line[0]),cmp2);
    for(int i=1;i<n;i++)
    {
         k=i-1;
         while(line[i].sy>=line[k].ty && k>=0)
         {
             if(line[i].sy==line[k].ty && line[i].sx<=line[k].tx && line[i].tx>=line[i].sx)
             {
               line[i].visit=true;
               line[k].visit=true; 
               break;
             } 
             k--;        
         }           
    }
    for(int i=0;i<n;i++)
      if(line[i].visit==false)
         sum++;
    printf("%d\n",sum);
    system("pause");
    return 0;
}

