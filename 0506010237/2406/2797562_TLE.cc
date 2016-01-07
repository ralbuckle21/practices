#include<iostream>
using namespace std;
void nexts(char p[100],int n)
{
     int next[100];
     next[0]=-1;
     int k=-1;
     for(int i=1;i<n;i++)
     {
         while(k>=0 && p[k+1]!=p[i])
            k=next[k];
         if(p[k+1]==p[i])
          k=k+1;
         next[i]=k;       
     }
     if(n%(n-1-next[n-1])==0)
        printf("%d\n",n/(n-1-next[n-1]));
     else
        printf("1\n");
}
int main()
{
     char p[1000001];
     while(true)
     {
         scanf("%s",p);
         if(p[0]=='.')
           break;
         int n=strlen(p);
         nexts(p,n);           
     } 
    system("pause");
    return 0;
}
