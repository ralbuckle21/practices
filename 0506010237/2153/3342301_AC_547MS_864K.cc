#include<iostream>
using namespace std;
struct{
    char name[32];
    int v;
    bool flag;      
}student[12011];
int n,m,maxs=12011;
char mg[100];
void insert(char key[35])
{
    int dir=0,len=strlen(key);
    if(len==1) dir=key[0]-'A';
    else dir=key[0]-'A'+(key[1]-'A')*41+(key[len-1]-'A')*1681+(key[len-2]-'A')*1681*41;
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
    if(len==1) dir=key[0]-'A';
    else dir=key[0]-'A'+(key[1]-'A')*41+(key[len-1]-'A')*1681+(key[len-2]-'A')*1681*41;
    dir=dir%maxs;
    while(strcmp(student[dir].name,key)!=0)
             dir=(dir+1)%maxs;    
    student[dir].v+=value;
}
int gett(char key[35])
{
    int i,dir=0,len=strlen(key);
    if(len==1) dir=key[0]-'A';
    else dir=key[0]-'A'+(key[1]-'A')*41+(key[len-1]-'A')*1681+(key[len-2]-'A')*1681*41;
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
         for(int i=0;i<n;i++)
         {
             scanf("%d ",&x); 
             gets(mg); 
             change(mg,x);
         }
         d=gett("Li Ming");
         for(int i=0;i<maxs;i++) 
         {
             if(student[i].v>d)
                ci++;        
         }
         printf("%d\n",ci+1);         
    }
    system("pause");
    return 0;
}

