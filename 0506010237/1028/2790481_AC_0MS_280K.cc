#include<iostream>
#include<string>
using namespace std;
int f=0;
int b=0;
char mg[100][100];
char g[100]="http://www.acm.org/";
int main()
{
    strcpy(mg[0],g);
    char mgs[10],str[100];
    while(true)
    {
        scanf("%s",mgs);
        if(strcmp(mgs,"QUIT")==0)  
           break;
        if(strcmp(mgs,"VISIT")==0) 
        {
           scanf("%s",str);
           b++;
           strcpy(mg[b],str);
           f=b;
           printf("%s\n",mg[b]);
        }
        else if(strcmp(mgs,"BACK")==0) 
        {
             if(b==0)
               printf("%s\n","Ignored");
             else
             {
               printf("%s\n",mg[--b]);
             }
        }
        else if(strcmp(mgs,"FORWARD")==0)
        {
             if(b==f)
               printf("%s\n","Ignored");
             else
             {
               printf("%s\n",mg[++b]);
             }  
        }       
    }
    system("pause");
    return 0;
}
