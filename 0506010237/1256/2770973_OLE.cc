#include<iostream>
#include<string>
using namespace std;
char c[14];
void swaps(int x,int y)
{
    char temp=c[x];
    c[x]=c[y];
    c[y]=temp;    
}
void swapup(int x,int y)
{
     char temp=c[x];
     for(int i=x+1;i<=y;i++)
       c[i-1]=c[i];
     c[y]=temp;      
}
void swapdown(int x,int y)
{
     char temp=c[y];
     for(int i=y-1;i>=x;i--)
      c[i+1]=c[i];
     c[x]=temp;
}
void perm(int k,int m)
{
   if(k==m)
    {
        for(int i=0;i<=m;i++)
          printf("%c",c[i]);
        printf("\n");
    }
   else
   {
      for(int i=k;i<=m;i++)
      {
         if(k==i)
         {
           swaps(k,i);
           perm(k+1,m);
           swaps(k,i);
         }
         if(c[k]!=c[i])
         {
           swapdown(k,i);
           perm(k+1,m);
           swapup(k,i);
         }
      }
   }
}
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s",c);
        int len=strlen(c);
        for(int i=0;i<len-1;i++)
          for(int j=i+1;j<len;j++)
          {
               if(c[i]>='a' && c[j]>='a')
               {
                   if(c[i]>c[j])
                     swaps(i,j);             
               }
               else if(c[i]<'a' && c[j]<'a')
               {
                   if(c[i]>c[j])
                     swaps(i,j);     
               }
               else if(c[i]>='a' && c[j]<'a')
               {
                   if(c[i]-32>=c[j])
                      swaps(i,j);  
               }
               else
               {
                   if(c[i]>c[j]-32)
                     swaps(i,j);                        
               }
          }    
          perm(0,len-1);
    }
    system("pause");
    return 0;
}
