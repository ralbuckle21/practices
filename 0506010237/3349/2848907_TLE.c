#include <stdio.h>
#include <stdlib.h>
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
                         if(mg[i][k]==mg[j][0])
                         if(mg[i][(k+1)%6]==mg[j][1])
                         if(mg[i][(k+2)%6]==mg[j][2])
                         if(mg[i][(k+3)%6]==mg[j][3]) 
                         if(mg[i][(k+4)%6]==mg[j][4])
                         if(mg[i][(k+5)%6]==mg[j][5])
                         {
                                printf("%s\n","Twin snowflakes found.");
                                return;            
                         }  
                         //逆向  
                         if(mg[i][k]==mg[j][0])
                         if(mg[i][(k+5)%6]==mg[j][1])
                         if(mg[i][(k+4)%6]==mg[j][2])
                         if(mg[i][(k+3)%6]==mg[j][3])
                         if(mg[i][(k+2)%6]==mg[j][4])
                         if(mg[i][(k+1)%6]==mg[j][5])
                         {
                                 printf("%s\n","Twin snowflakes found.");
                                 return;     
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
         qsort(num[i],6,sizeof(num[0][0]),cmp);
    }
    com(n);
    system("pause");
    return 0;
}
