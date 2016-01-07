#include<iostream>
#include<string>
using namespace std;
char c[9][12];
int n,cs=1,num[9];
bool getresult()
{
     for(int i=0;i<=n;i++)
        num[i]=strlen(c[i]);
     for(int i=0;i<n;i++)
     {
       for(int j=i+1;j<=n;j++)
       {
            if(num[i]>num[j]) 
               continue;
            int x;
            for(x=0;x<num[i];x++)
            {
                 if(c[i][x]!=c[j][x])
                     break;      
            }       
            if(x==num[i])
              return true; 
        }
     }
     return false;
}
int main()
{
    while(scanf("%s",c[0])!=EOF)
    {
        int i=0;
        while(true)
        {
            scanf("%s",c[++i]);
            if(c[i][0]=='9')
               break;           
        }           
        n=i-1; 
        if(!getresult())
           printf("Set %d is immediately decodable\n",cs++);
        else
           printf("Set %d is not immediately decodable\n",cs++);             
    }
    system("pause");
    return 0;
}
