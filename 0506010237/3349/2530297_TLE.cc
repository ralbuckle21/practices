#include <stdio.h>
#include <stdlib.h>
int mg[100000][7];
void com(int n)
{
     int i,j,k;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(mg[j][6]==mg[i][6])
            {
                  for(k=0;k<6;k++)
                  {
                      int kw=0,w=0;
                      while(mg[i][k]!=mg[j][w] && w<6)
                           w++;
                      if(w==6)
                        continue;
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
                  }        
            }  
        }       
    } 
     printf("%s\n","No two snowflakes are alike.");  
}
int main()
{
    int n,i,h;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
         mg[i][6]=0;
         for(h=0;h<6;h++)
         {  
               char c;
               mg[i][h]=0;
               c=getchar();
               while(c>'9' || c<'0')
                 c=getchar();
               while(c<='9' && c>='0')
               {
                   mg[i][h]=(c-'0')+mg[i][h]*10;
                   c=getchar();
               }
             //  scanf("%d",&mg[i][h]);
               mg[i][6]=mg[i][6]+mg[i][h];
         } 
    }
    com(n);
    return 0;
}