#include<iostream>
using namespace std;
typedef struct node{
    char name[32];
    int v;
    struct node *next;      
}students;
students *student[12011];
int n,m,maxs=12011;
char mg[100];
void insert(char key[35])
{
    int dir=0,len=strlen(key);
    if(len==1) dir=key[0]-'A';
    else dir=key[0]-'A'+(key[1]-'A')*41+(key[len-1]-'A')*1681+(key[len-2]-'A')*1681*41;
    dir=dir%maxs;
    if(!student[dir])
    {
        student[dir]=new students;
        strcpy(student[dir]->name,key);
        student[dir]->v=0;
        student[dir]->next=NULL;
        return;
    }
    students *temp=student[dir]->next;
    while(temp)temp=temp->next;
    temp=new students;
    strcpy(temp->name,key);
    temp->v=0;
    temp->next=student[dir];
    student[dir]=temp;
}
void change(char key[35],int value)
{
    int i,dir=0,len=strlen(key);
    if(len==1) dir=key[0]-'A';
    else dir=key[0]-'A'+(key[1]-'A')*41+(key[len-1]-'A')*1681+(key[len-2]-'A')*1681*41;
    dir=dir%maxs;
    students *temp=student[dir];
    while(strcmp(temp->name,key)!=0)temp=temp->next;  
    temp->v+=value;
}
int gett(char key[35])
{
    int i,dir=0,len=strlen(key);
    if(len==1) dir=key[0]-'A';
    else dir=key[0]-'A'+(key[1]-'A')*41+(key[len-1]-'A')*1681+(key[len-2]-'A')*1681*41;
    dir=dir%maxs;
    students *temp=student[dir];
    while(strcmp(temp->name,key)!=0)temp=temp->next;     
    return temp->v;
}
int main()
{
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
            students *t=student[i];
            while(t)
            {
                if(t->v>d)
                    ci++;
                t=t->next;
            }
         }
         printf("%d\n",ci+1);         
    }
    system("pause");
    return 0;
}

