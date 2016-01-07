#include<iostream>
using namespace std;
int n,m;
int num[101];
char mg[100];
int main()
{
    scanf("%d ",&n);
    for(int i=0;i<n;i++) gets(mg);
    scanf("%d",&m);
    while(m--)
    {
         memset(num,0,101);
         int d,x,ci=0;
         for(int i=0;i<n;i++)
         {
             scanf("%d ",&x); 
             num[x]++;
             gets(mg); 
             if(strcmp(mg,"Li Ming")==0) d=x;
         }
         for(int j=100;j>d;j--) ci+=num[j];
         printf("%d\n",ci+1);         
    }
    system("pause");
    return 0;
}
