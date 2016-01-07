#include<iostream>
using namespace std;
struct{
    char name[32];
    int v;
    bool flag;      
}student[500000];
int n,m,maxs=500000;
int num[11000];
int len=0;
char mg[100];
void insert(char key[35])
{
    int dir=0,len=strlen(key);
    for(int i=0;i<len;i++) dir=dir+int(key[i]-'0');
    dir=dir%maxs;
    while(student[dir].flag) dir=(dir+1)%maxs;
	if(!student[dir].flag)
	{
         student[dir].flag=1;
         strcpy(student[dir].name,key);   
	}
}
void change(char key[35],int value)
{
    int i,dir=0,len=strlen(key);
    for(i=0;i<len;i++) dir=dir+int(key[i]-'0');
    dir=dir%maxs;
    while(strcmp(student[dir].name,key)!=0)
             dir=(dir+1)%maxs;    
    student[dir].v+=value;
    num[len++]=student[dir].v;
}
int gett(char key[35])
{
    int i,dir=0,len=strlen(key);
    for(i=0;i<len;i++) dir=dir+int(key[i]-'0');
    dir=dir%maxs;
    while(strcmp(student[dir].name,key)!=0)
             dir=(dir+1)%maxs;    
    return student[dir].v;
}
int main()
{
    for(int i=0;i<=maxs;i++)
    {
          student[i].flag=false;
          student[i].v=0;
    }
    scanf("%d ",&n);
    for(int i=0;i<n;i++)
    { 
          gets(mg);
          insert(mg);
    }
    scanf("%d",&m);
    while(m--)
    {
         int x,ci=0,d;
         len=0;
         for(int i=0;i<n;i++)
         {
             scanf("%d ",&x); 
             gets(mg); 
             change(mg,x);
         }
         d=gett("Li Ming");
         for(int i=0;i<n;i++) 
         {
             if(num[i]>d)
                ci++;        
         }
         printf("%d\n",ci+1);         
    }
    system("pause");
    return 0;
}

