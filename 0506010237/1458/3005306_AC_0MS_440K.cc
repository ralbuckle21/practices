#include<iostream>
#include<string>
using namespace std;
void lcs(char x[1000],char y[1000])
{
    int m=strlen(x)-1;
    int n=strlen(y)-1;
    int c[m+1][n+1];
    for(int i=0;i<=m;i++)
       c[i][0]=0;
    for(int j=0;j<=n;j++)
       c[0][j]=0;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
           if(x[i]==y[j])
                c[i][j]=c[i-1][j-1]+1;       
            else if(c[i-1][j]>=c[i][j-1])
                c[i][j]=c[i-1][j]; 
            else
                c[i][j]=c[i][j-1];    
        }        
    }
    printf("%d\n",c[m][n]);
}
int main()
{
    while(true)
    {
       char x[1000],y[1000];
       if(!(cin>>x+1>>y+1))
            break;
       x[0]='0';
       y[0]='0';
       lcs(x,y);
    }          
   system("pause");
   return 0;
}
