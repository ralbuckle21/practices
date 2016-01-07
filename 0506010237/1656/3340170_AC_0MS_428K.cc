#include<iostream>
using namespace std;
int grid[101][101]={0};
int t,x,y,h;
char mg[10];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
         scanf("%s %d %d %d",mg,&x,&y,&h);
         int x1=x+h,y1=y+h;
         if(strcmp(mg,"WHITE")==0)
         {
              for(int i=x;i<x1;i++)
                 for(int j=y;j<y1;j++)
                   grid[i][j]=1;                      
         }          
         else if(strcmp(mg,"BLACK")==0)
         {
               for(int i=x;i<x1;i++)
                 for(int j=y;j<y1;j++)
                   grid[i][j]=2;    
         }
         else
         {
               int c=0;
               for(int i=x;i<x1;i++)
                 for(int j=y;j<y1;j++)
                   if(grid[i][j]==2) c++;
               printf("%d\n",c);   
         }     
    }
    system("pause");
    return 0;
}
