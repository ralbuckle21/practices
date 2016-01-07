#include<iostream>
#include<string>
using namespace std;
int n,best=1000;
int bestx[101],mg[101];
char c[102];
void backtrace(int x,int y,int k)
{
    if(k>=best)
       return;
    if(x>=y)
    {
        if(x==y)
        {
          mg[k]=x;
          k++;
        }
        if(k<best) 
        {   
            for(int i=0;i<k;i++)
                bestx[i]=mg[i];
            best=k;
        }                  
    }             
    else
    {
       if(c[x]==']' && c[x]==')')
       {
            mg[k]=x;
            backtrace(x+1,y,k+1);
       }
       else if(c[y]=='[' && c[y]=='(')
       {
            mg[k]=y;
            backtrace(x,y-1,k+1);     
       }
       else if((c[x]=='[' && c[y]==']') || (c[x]=='(' && c[y]==')'))        
           backtrace(x+1,y-1,k);
        else
        {
           mg[k]=x;
           backtrace(x+1,y,k+1);
           mg[k]=y;
           backtrace(x,y-1,k+1);
        }    
    }
}
int cmp(const void *a, const void *b)
{
       return(*(int *)a-*(int *)b);
}
int main()
{
    scanf("%s",c);
    n=strlen(c);
    backtrace(0,n-1,0);
    qsort(bestx,best,sizeof(bestx[0]),cmp);
    int k=0;
    for(int i=0;i<n;i++)
    {
           if(i==bestx[k])
            {
                if(c[i]=='[' || c[i]==']')
                   printf("[]");
                else
                   printf("()");
                k++;              
            }
            else  
                printf("%c",c[i]);    
    }
    printf("\n");
    system("pause");
    return 0;
}

