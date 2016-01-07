#include<iostream>
using namespace std;
void chuli(char mg[3][20])
{
     int num[12],num1[12],feifa[3],fa[3][9];
     for(int j=0;j<12;j++)
     {
        num[j]=0;
        num1[j]=2;
     }
     for(int j=0;j<3;j++)
       feifa[j]=0;
     for(int i=0;i<3;i++)
     {
           char c=mg[i][10];
           if(c=='e')
           {
                for(int j=0;j<4;j++)
                  num[int(mg[i][j]-'A')]=2;
                for(int j=5;j<9;j++)
                  num[int(mg[i][j]-'A')]=2;         
           }                   
           else if(c=='u')
           {
                for(int j=0;j<4;j++)
                  fa[i][j]=int(mg[i][j]-'A');
                for(int j=5;j<=8;j++)
                  fa[i][j-1]=int(mg[i][j]-'A');
               fa[i][8]=2;  
           }
           else
           {
               for(int j=0;j<4;j++)
                  fa[i][j]=int(mg[i][j]-'A');
                for(int j=5;j<=8;j++)
                  fa[i][j-1]=int(mg[i][j]-'A');
               fa[i][8]=1; 
           }        
     }
     for(int i=0;i<12;i++)
     {
          int j;
          if(num[i]!=2)
          {
               num1[i]=1;  
               for(j=0;j<3;j++)
               {
                   if(feifa[j]!=0)
                   {
                        if(!((fa[j][8]=2 && num1[fa[j][0]]+num1[fa[j][1]]+num1[fa[j][2]]+num1[fa[j][3]]>
                        num1[fa[j][4]]+num1[fa[j][5]]+num1[fa[j][6]]+num1[fa[j][7]]) || 
                        (fa[j][8]=1 && num1[fa[j][0]]+num1[fa[j][1]]+num1[fa[j][2]]+num1[fa[j][3]]<
                        num1[fa[j][4]]+num1[fa[j][5]]+num1[fa[j][6]]+num1[fa[j][7]])))  
                           break;          
                   }    
               }
               if(j==3)
               {
                  printf("%c %s\n",char('A'+i),"is the counterfeit coin and it is light.");
                  break;
               }  
               num1[i]=3;  
               for(j=0;j<3;j++)
               {
                   if(feifa[j]!=0)
                   {
                        if(!((fa[j][8]=2 && num1[fa[j][0]]+num1[fa[j][1]]+num1[fa[j][2]]+num1[fa[j][3]]>
                        num1[fa[j][4]]+num1[fa[j][5]]+num1[fa[j][6]]+num1[fa[j][7]]) || 
                        (fa[j][8]=1 && num1[fa[j][0]]+num1[fa[j][1]]+num1[fa[j][2]]+num1[fa[j][3]]<
                        num1[fa[j][4]]+num1[fa[j][5]]+num1[fa[j][6]]+num1[fa[j][7]])))  
                           break;          
                   }    
               }
              num1[i]=2;
              if(j==3)
              {
                printf("%c %s\n",char('A'+i),"is the counterfeit coin and it is heavy."); 
                break;
              }       
          }        
     }
}
int main()
{
    int t;
    scanf("%d",&t);
    char mg[3][20];
    gets(mg[0]);
    while(t--)
    { 
         gets(mg[0]);
         gets(mg[1]);
         gets(mg[2]); 
         chuli(mg);      
    }
    system("pause");
    return 0;
}
