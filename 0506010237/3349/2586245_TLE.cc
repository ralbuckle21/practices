#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
int mg[100000][9];
void com(int n)
{
     int i,j,k;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(mg[j][6]==mg[i][6] && mg[j][7]==mg[i][7] && mg[j][8]==mg[i][8])
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
     printf("%s\n","No two snowflakes are alike.");  
}
int main()
{
    int n,i,j,h=0,min=99999999;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
         scanf("%d %d %d %d %d %d",&mg[i][0],&mg[i][1],&mg[i][2],&mg[i][3],&mg[i][4],&mg[i][5]);
         mg[i][6]=0;
         for(j=0;j<6;j++)
         {
            mg[i][6]=mg[i][6]+mg[i][j];
             if(mg[i][j]<min)
              min=mg[i][j];
             if(mg[i][j]==min)
               h++;                 
         }
         mg[i][7]=min;
         mg[i][8]=h;
         h=0;
    }
    com(n);
    system("pause");
    return 0;
}
