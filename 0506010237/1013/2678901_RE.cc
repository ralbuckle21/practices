#include<iostream>
using namespace std;
void chuli(char mg[3][20])
{
     int num[12],num1[12],feifa[3],fa[3][13];
     for(int j=0;j<12;j++)
     {
        num[j]=0;
        num1[j]=2;
     }
     for(int j=0;j<3;j++)
       feifa[j]=0;
     int k[3];
     for(int f=0;f<3;f++)
      for(int i=0;i<7;i++)
       if(mg[0][i]==' ')
         k[f]=i;
     for(int i=0;i<3;i++)
     {
           char c=mg[i][2*k[i]+2];
           if(c=='e')
           {
                for(int j=0;j<k[i];j++)
                  num[int(mg[i][j]-'A')]=2;
                for(int j=k[i]+1;j<=k[i]+4;j++)
                  num[int(mg[i][j]-'A')]=2;         
           }                   
           else if(c=='u')
           {
                for(int j=0;j<k[i];j++)
                  fa[i][j]=int(mg[i][j]-'A');
                for(int j=k[i]+1;j<=k[i]+4;j++)
                  fa[i][j-1]=int(mg[i][j]-'A');
               feifa[i]=2;  
           }
           else
           {
               for(int j=0;j<k[i];j++)
                  fa[i][j]=int(mg[i][j]-'A');
                for(int j=k[i]+1;j<=k[i]+4;j++)
                  fa[i][j-1]=int(mg[i][j]-'A');
               feifa[i]=1; 
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
                   if(feifa[j]==2)
                   {
                        int x=0,y=0;
                        for(int h=0;h<k[j];h++)
                             x=x+num1[fa[j][h]];
                        for(int h=k[j];h<2*k[j];h++)   
                             y=y+num1[fa[j][h]];
                        if(x<=y)
                          break;  
                   }    
                   else if(feifa[j]==1)
                   {
                        int x=0,y=0;
                        for(int h=0;h<k[j];h++)
                             x=x+num1[fa[j][h]];
                        for(int h=k[j];h<2*k[j];h++)   
                             y=y+num1[fa[j][h]];
                        if(x>=y)
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
                   if(feifa[j]==2)
                   {
                        int x=0,y=0;
                        for(int h=0;h<k[j];h++)
                             x=x+num1[fa[j][h]];
                        for(int h=k[j];h<2*k[j];h++)   
                             y=y+num1[fa[j][h]];
                        if(x<=y)
                          break;  
                   }    
                   else if(feifa[j]==1)
                   {
                        int x=0,y=0;
                        for(int h=0;h<k[j];h++)
                             x=x+num1[fa[j][h]];
                        for(int h=k[j];h<2*k[j];h++)   
                             y=y+num1[fa[j][h]];
                        if(x>=y)
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
