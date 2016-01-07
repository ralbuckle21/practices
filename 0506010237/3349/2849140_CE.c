#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
typedef struct
{
    int mg[6];
    int sum;       
}node;
node list[100001];
int cmp( const void *a ,const void *b)
{
     return (*(node *)a).sum - (*(node *)b).sum;
}
void com(int n)
{
    int k,x=0,i=1;
    while(i<n)
    {
        if(list[x].sum!=list[i].sum)
        {
             x=i;
             i++;                            
        }        
        else
        {
             for(int j=x;j<i;j++)
             {
                  for(k=0;k<6;k++)
                  {
                         if(list[i].mg[k]==list[j].mg[0])
                         if(list[i].mg[(k+1)%6]==list[j].mg[1])
                         if(list[i].mg[(k+2)%6]==list[j].mg[2])
                         if(list[i].mg[(k+3)%6]==list[j].mg[3]) 
                         if(list[i].mg[(k+4)%6]==list[j].mg[4])
                         {
                                printf("%s\n","Twin snowflakes found.");
                                return;            
                         }  
                         //逆向  
                         if(list[i].mg[k]==list[j].mg[0])
                         if(list[i].mg[(k+5)%6]==list[j].mg[1])
                         if(list[i].mg[(k+4)%6]==list[j].mg[2])
                         if(list[i].mg[(k+3)%6]==list[j].mg[3])
                         if(list[i].mg[(k+2)%6]==list[j].mg[4])
                         {
                                 printf("%s\n","Twin snowflakes found.");
                                 return;     
                         } 
                  }            
             }
             i++;
        }         
    } 
    printf("%s\n","No two snowflakes are alike.");  
}
int main()
{
    int n,i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
         scanf("%d %d %d %d %d %d",&list[i].mg[0],&list[i].mg[1],&list[i].mg[2],&list[i].mg[3],&list[i].mg[4],&list[i].mg[5]);
         list[i].sum=0;
         for(j=0;j<6;j++)
            list[i].sum=list[i].sum+list[i].mg[j];             
    }
    qsort(list,n,sizeof(list[0]),cmp);
    com(n);
    system("pause");
    return 0;
}

