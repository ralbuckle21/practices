#include<iostream>
#include<string>
using namespace std;
int main()
{
     int n,count=1,len,j=0;
     char mg[1001];
     scanf("%d",&n);
     while(n--)
     {
          scanf("%s",mg);
          len=strlen(mg);
          for(int i=1;i<len;i++)
          {
                if(mg[j]==mg[i])
                {
                    j++;
                    count++;                
                }       
                else
                {
                     printf("%d%c",count,mg[j]);
                     count=1;  
                     j=i;
                }
          }       
          printf("%d%c\n",count,mg[j]);   
          j=0;
          count=1;
     }
     system("pause");
     return 0;
}
