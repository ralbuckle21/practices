#include<iostream>
using namespace std;
char c[1000];
int n,ok=0;
bool f(int x,int y)
{
    if(x>y)
      return false;
    if(x!=y && c[x]<='z' && c[x]>='p')
         return false;
    if(x==y)
    {
       if(c[x]<='z' && c[x]>='p')
       {
          return true;
       }
       else
          return false;        
    }
    else if(c[x]=='N')
    {
         if(f(x+1,y))
         {
             return true;            
         }     
    }
    else if(c[x]=='C' || c[x]=='D' || c[x]=='E' || c[x]=='I')
    {
          for(int i=x+1;i<y;i++)
          {
               if(f(x+1,i) && f(i+1,y))
               {
                  return true;
               }        
          }      
    }  
    return false;  
}
int main()
{
    while(scanf("%s",c)!=EOF)
    {
      n=strlen(c);
      if(f(0,n-1))
        printf("YES\n");
      else
        printf("NO\n");
    }
    system("pause");
    return 0;
}
