#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
int mg[100000][7],num[100000][6];
int cmp ( const void *a , const void *b )
{
     return *(int *)a - *(int *)b;
}
void com(int n)
{
     int i,j,k;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(mg[j][6]==mg[i][6])
            {
               if(num[j][0]==num[i][0] && num[j][1]==num[i][1] && num[j][2]==num[i][2] && num[j][3]==num[i][3] && num[j][4]==num[i][4] && num[j][5]==num[i][5])
               {
                  for(k=0;k<6;k++)
                  {
                      int kw=0,w=0;
                      while(w<6)
                      {
                         while(mg[i][k]!=mg[j][w] && w<6)
                             w++;
                         if(w==6)
                           break;
                         if(mg[i][k]==mg[j][w])
                         if(mg[i][(k+1)%6]==mg[j][(w+1)%6])
                         if(mg[i][(k+2)%6]==mg[j][(w+2)%6])
                         if(mg[i][(k+3)%6]==mg[j][(w+3)%6]) 
                         if(mg[i][(k+4)%6]==mg[j][(w+4)%6])
                         if(mg[i][(k+5)%6]==mg[j][(w+5)%6])
                         {
                                printf("%s\n","Twin snowflakes found.");
                                return;            
                         }    
                         if(mg[i][k]==mg[j][w])
                         if(mg[i][(k-1)%6]==mg[j][(w+1)%6])
                         if(mg[i][(k-2)%6]==mg[j][(w+2)%6])
                         if(mg[i][(k-3)%6]==mg[j][(w+3)%6])
                         if(mg[i][(k-4)%6]==mg[j][(w+4)%6])
                         if(mg[i][(k-5)%6]==mg[j][(w+5)%6])
                         {
                                 printf("%s\n","Twin snowflakes found.");
                                 return;     
                         } 
                         w++;         
                      }
                  }                         
               }
            }  
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
         scanf("%d %d %d %d %d %d",&mg[i][0],&mg[i][1],&mg[i][2],&mg[i][3],&mg[i][4],&mg[i][5]);
         mg[i][6]=0;
         for(j=0;j<6;j++)
         {
            mg[i][6]=mg[i][6]+mg[i][j];             
            num[i][j]=mg[i][j];
         }
         qsort(num,6,sizeof(num[0]),cmp);
    }
    com(n);
    system("pause");
    return 0;
}
