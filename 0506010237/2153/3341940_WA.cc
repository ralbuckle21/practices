#include<iostream>
using namespace std;
int n,m;
int num[101];
char mg[300];
char c;
int main()
{
    scanf("%d",&n);
    c=getchar();while(c==' ' || c=='\n') c=getchar();
    mg[0]=c;
    for(int i=0;i<n;i++) cin.getline(mg+1,50,'\n');
    scanf("%d",&m);
    while(m--)
    {
         memset(num,0,101);
         int d,x,ci=0;
         for(int i=0;i<n;i++)
         {
             strcpy(mg,"");
             scanf("%d",&x);
             c=getchar();while(c==' ' || c=='\n') c=getchar();
             mg[0]=c; 
             num[x]++;
             cin.getline(mg+1,50,'\n'); 
             if(strcmp(mg,"Li Ming")==0) d=x;
         }
         for(int j=100;j>d;j--) ci+=num[j];
         printf("%d\n",ci+1);         
    }
    system("pause");
    return 0;
}
