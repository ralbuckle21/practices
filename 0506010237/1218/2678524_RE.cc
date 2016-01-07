#include<iostream>
using namespace std;
int main()
{
    char mg[41];
    bool visit[41];
    int t,n,i,j,k,m,h,num[40];
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
         h=0;
         scanf("%d",&n);
         for(j=0;j<n;j++)
         {
             scanf("%d",&k);
             k=k+j;
             num[j]=k;
             for(;h<k;h++)
               mg[h]='(';
             mg[h]=')';
             h++;           
         }  
         for(j=0;j<h;j++)
            visit[j]=0;
         for(j=0;j<n;j++)
         {
              h=num[j]-1;
              int c=0;
              while(h>=0)
              {
                 if(mg[h]=='(')
                  c++;
                  if(mg[h]=='(' && visit[h]==0)
                  {
                      if(j!=n-1)
                      printf("%d ",c);
                      else
                        printf("%d\n",c);
                      visit[h]=1;
                      break;              
                  }
                  h--;           
              }               
         }         
    }
    system("pause");
    return 0;
}