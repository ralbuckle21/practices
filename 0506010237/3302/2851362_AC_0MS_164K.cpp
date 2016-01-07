#include<iostream>
using namespace std;
bool kmp(char p[102],char t[102],int n,int m)
{
    int i=0,j=0;
    while(i<m && j<n)
    {
         if(t[i]==p[j])
             j++;                 
         if(j==n)
            return true;
         i++;   
    }    
    return false;
}
int main()
{
    int f,i;
    scanf("%d",&f);
    while(f--)
    {
       char p[102],t[102],t1[102];
       scanf("%s",t);
       scanf("%s",p);
       int n=strlen(p);
       int m=strlen(t);
       for(i=0;i<m;i++)
         t1[i]=t[m-1-i];
       if(kmp(p,t,n,m) || kmp(p,t1,n,m))
           printf("YES\n"); 
       else
          printf("NO\n");
    }  
    system("pause");
    return 0;
}

