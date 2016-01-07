#include<iostream>
using namespace std;
int mg[10][7]= {{1,1,1,0,1,1,1},
                {0,0,1,0,0,1,0},
                {1,0,1,1,1,0,1},
                {1,0,1,1,0,1,1},
                {0,1,1,1,0,1,0},
                {1,1,0,1,0,1,1},
                {1,1,0,1,1,1,1},
                {1,0,1,0,0,1,0},
                {1,1,1,1,1,1,1},
                {1,1,1,1,0,1,1}};
int main()
{
    int s,n;
    char c[13];
    while(true)
    {
         scanf("%d %s",&s,c);
         if(s==0)
           break;
         n=strlen(c);
         for(int i=0;i<n;i++)
         {
             printf(" ");
             if(mg[int(c[i]-'0')][0]==1)
               for(int j=0;j<s;j++)
                    printf("-");        
             else
                for(int j=0;j<s;j++)
                    printf(" ");  
             printf("  ");
         }  
         printf("\n");  
         for(int k=1;k<=s;k++)
         {
            for(int i=0;i<n;i++)
            {
              if(mg[int(c[i]-'0')][1]==1) 
                   printf("|");
              else
                  printf(" ");
              for(int j=0;j<s;j++)
                  printf(" ");
              if(mg[int(c[i]-'0')][2]==1) 
                   printf("|");
              else
                  printf(" ");      
              printf(" "); 
            }
            printf("\n");
         }        
         for(int i=0;i<n;i++)
         {
             printf(" ");
             if(mg[int(c[i]-'0')][3]==1)
               for(int j=0;j<s;j++)
                    printf("-");        
             else
                for(int j=0;j<s;j++)
                    printf(" ");  
             printf("  ");
         }  
         printf("\n");  
         for(int k=1;k<=s;k++)
         {
           for(int i=0;i<n;i++)
           {
              if(mg[int(c[i]-'0')][4]==1) 
                   printf("|");
              else
                  printf(" ");
              for(int j=0;j<s;j++)
                  printf(" ");
              if(mg[int(c[i]-'0')][5]==1) 
                   printf("|");
              else
                  printf(" ");      
              printf(" "); 
           }
           printf("\n");
         }        
         for(int i=0;i<n;i++)
         {
             printf(" ");
             if(mg[int(c[i]-'0')][6]==1)
               for(int j=0;j<s;j++)
                    printf("-");        
             else
                for(int j=0;j<s;j++)
                    printf(" ");  
             printf("  ");
         }  
         printf("\n"); 
         printf("\n");
    }
    system("pause");
    return 0;
}
