#include<iostream>
#include<string>
using namespace std;
typedef struct
{
    int x;
    int y;
    int w;
    int c;       
}node;
int n;
char mg[102];
int cmp(const void *a, const void *b)
{
       return(*(int *)a-*(int *)b);
}
int main()
{
    scanf("%s",mg);
    n=strlen(mg);
    node num[n][n];
    for(int i=0;i<n;i++)
    {
         num[i][i].x=num[i][i].y=-1;
         num[i][i].c=i;   
         num[i][i].w=1;    
    }
    for(int i=1;i<n;i++)
    {
        int k=0;
        for(int j=i;j<n;j++)
        {
            if(num[k+1][j].w<=num[k][j-1].w)
            {
                 num[k][j].x=k+1;
                 num[k][j].y=j;
                 num[k][j].w=num[k+1][j].w+1;                              
                 num[k][j].c=k; 
            }
            else
            {
                 num[k][j].x=k;
                 num[k][j].y=j-1;
                 num[k][j].w=num[k][j-1].w+1;
                 num[k][j].c=j;                        
            }
            if((mg[k]=='[' && mg[j]==']') || (mg[k]=='(' && mg[j]==')') && num[k+1][j-1].w<num[k][j].w)
            {
                 num[k][j].x=k+1;
                 num[k][j].y=j-1;
                 num[k][j].w=num[k+1][j-1].w;
                 num[k][j].c=1000;        
            }
            k++;        
        }  
    }
    int best[102],h=1,a,b;
    best[0]=num[0][n-1].c;
    a=num[0][n-1].x;
    b=num[0][n-1].y;
    while(a!=-1)
    {
        best[h++]=num[a][b].c; 
        a=num[a][b].x;
        b=num[a][b].y;           
    } 
    qsort(best,h,sizeof(best[0]),cmp);
    int f=0;
    for(int i=0;i<n;i++)
    {
           if(i==best[f])
            {
                if(mg[i]=='[' || mg[i]==']')
                   printf("[]");
                else
                   printf("()");
                f++;              
            }
            else  
                printf("%c",mg[i]);    
    }
    printf("\n");
    system("pause");
    return 0;
}
