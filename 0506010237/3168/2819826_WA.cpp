# include <stdio.h>
# include <stdlib.h>
typedef struct
{
    int sx;
    int sy;
    int tx;
    int ty;     
}Line;
bool visit[25000];
Line line1[25000],line2[25000];
int sum=0;
int n,k=0,i;
int cmp1( const void *a ,const void *b)
{
     return (*(Line *)a).sx - (*(Line *)b).sx ;
}
int cmp2( const void *c ,const void *d)
{
     return (*(Line *)c).sy -(*(Line *)d).sy;
}
int main()
{
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d %d %d %d",&line1[i].sx,&line1[i].sy,&line1[i].tx,&line1[i].ty); 
        line2[i].sx=line1[i].sx;
        line2[i].sy=line1[i].sy;
        line2[i].tx=line1[i].tx;
        line2[i].ty=line1[i].ty;
        visit[i]=false;       
    }
    qsort(line1,n,sizeof(line1[0]),cmp1);
    for(i=1;i<n;i++)
    {
         k=i-1;
         while(line1[i].sx>=line1[k].tx && k>=0)
         {
             if(line1[i].sx==line1[k].tx && line1[i].sy<=line1[k].ty && line1[i].ty>=line1[i].sy)
             {
               visit[i]=true;
               visit[k]=true; 
               break;
             } 
             k--;        
         }           
    }
    qsort(line2,n,sizeof(line2[0]),cmp2);
    for(i=1;i<n;i++)
    {
         k=i-1;
         while(line2[i].sy>=line2[k].ty && k>=0)
         {
             if(line2[i].sy==line2[k].ty && line2[i].sx<=line2[k].tx && line2[i].tx>=line2[i].sx)
             {
               visit[i]=true;
               visit[k]=true; 
               break;
             } 
             k--;        
         }           
    }
    for(i=0;i<n;i++)
      if(visit[i]==false)
         sum++;
    printf("%d\n",sum);
    system("pause");
    return 0;
}

