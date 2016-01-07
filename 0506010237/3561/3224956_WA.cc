#include<iostream>
using namespace std;
char c[12][12];
int t,n,m;
int x,y,sign=0;
bool k=false;
bool getresult()
{
    int i,j;
    for(i=0;i<n;i++)
      for(j=0;j<m;j++)
      {
           if(c[i][j]=='-')
           {
               if(!k)
               {
                    sign=1;
                    x=i;
                    y=j+1;
                    k=true;     
               }       
               else if(sign!=1 || x!=i || y!=j) return false;
               else{x=i;y=j+1;}
           }
           else if(c[i][j]=='|')
           {
               if(!k)
               {
                    sign=2;
                    x=i+1;
                    y=j;
                    k=true;      
               }     
               else if(sign!=2 || x!=i || y!=j) return false;
               else{x=i+1;y=j;}
           }
           else if(c[i][j]=='\\')
           {
               if(!k)
               {
                    sign=3;
                    x=i+1;
                    y=j+1;
                    k=true;     
               }     
               else if(sign!=3 || x!=i || y!=j)return false;
               else{x=i+1;y=j+1;}
           }
           else if(c[i][j]=='/')
           {
               if(!k)
               {
                    sign=4;
                    x=i;
                    y=j-1;
                    k=true;      
               }     
               else if(sign!=4 || x!=i || y!=j) return false;
               else{x=i;y=j-1;}
           }
      }
      if(sign==0) return false;
      return true;
}
int main()
{
     scanf("%d",&t);
     while(t--)
     {
          scanf("%d %d",&n,&m);
          for(int i=0;i<n;i++)
             scanf("%s",&c[i]);
          if(getresult()) printf("CORRECT\n");
          else printf("INCORRECT\n");   
          k=false; 
          sign=0;      
     }
     system("pause");
     return 0;
}
