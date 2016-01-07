#include<iostream>
using namespace std;
typedef struct
{
      int m;
      int count;  
}node;
node mg[26];
void init()
{
     int i;
     for(i=0;i<26;i++)
     {
       mg[i].m=i;
       mg[i].count=0;
     }    
}
int cmp(const void *a,const void *b)
{
    node *c=(node *)a;
    node *d=(node *)b;
    if(c->count!=d->count)
      return d->count-c->count;
    else
       return c->m-d->m;   
}
int main()
{
    char c;
    int i,j,x=0;
    init();
    while(true)
    {
        c=getchar();
        if(c=='!')
          break;
        if(c<='Z' && c>='A')
           mg[int(c-'A')].count++;          
    }
    qsort(mg,26,sizeof(mg[0]),cmp);
    while(true)
    {
         if(mg[0].count==0)
           break;
         while(x<26 && mg[0].count==mg[x].count)
           x++;
         int t=0;
         for(j=0;j<x;j++)
         {
              for(i=t;i<mg[j].m;i++)
                printf("  ");
              printf("* ");
              mg[j].count--;
              t=mg[j].m+1;   
         }
         printf("\n");
         qsort(mg,26,sizeof(mg[0]),cmp);   
         x=0;        
    }
    for(i=0;i<26;i++)
      printf("%c ",char('A'+i));
    printf("\n");
    system("pause");
    return 0;
}
