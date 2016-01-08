#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
char a[10],b[3],c[101];
int len;
int main()
{
     while(1)
     {
         gets(a);
         if(a[0]=='E'&&a[3]=='O')
         break;
         if(a[0]=='S')
         {
 
             gets(c);
             len=strlen(c);
             for(int i=0;i<len;i++)
             {
                 if(c[i]>'E'&&c[i]<='Z')
                 c[i]-=5;
                 else if(c[i]>='A'&&c[i]<='E')
                 c[i]+=21;
             }
             gets(b);
             if(b[0]=='E')
             {
                 for(int i=0;i<len;i++)
                 cout<<c[i];
             }
             cout<<endl;
         }
     }
     return 0;
}