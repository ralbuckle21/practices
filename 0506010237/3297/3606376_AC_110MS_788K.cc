#include<iostream>
#include<string>
using namespace std;
typedef struct{
     char sname[100];
     int sign;   
     bool visit;   
}student;
student stu[10000];
typedef struct{
     char pname[100];
     int num;    
}project;
project pr[100];
int slen,plen;
int cmp(const void *a,const void *b){
    project *c = (project *)a;
    project *d = (project *)b;
    if(c->num != d->num) return d->num - c->num;
    else return strcmp(c->pname,d->pname);   
}
int main()
{
    char s[100];
    int i;
    while(true){
         gets(s);
         if(s[0]=='0') break;
         slen=0,plen=0;
         while(s[0]!='1'){
             if(s[0]>='A' && s[0]<='Z'){
                  strcpy(pr[plen].pname,s);
                  pr[plen].num=0;
                  plen++;
             }            
             else{
                 for(i=0;i<slen;i++) 
                     if(strcmp(stu[i].sname,s)==0) break;
                if(i<slen){
                     if(!stu[i].visit){
                          if(stu[i].sign!=plen-1){
                              pr[stu[i].sign].num--;
                              stu[i].visit=true;
                          }
                     }
                }
                else{
                     strcpy(stu[slen].sname,s);
                     stu[slen].sign=plen-1;
                     stu[slen].visit=false;
                     slen++;
                     pr[plen-1].num++;     
                }           
             }           
             gets(s);  
         }
         qsort(pr,plen,sizeof(pr[0]),cmp);
         for(i=0;i<plen;i++) printf("%s %d\n",pr[i].pname,pr[i].num);          
    }
    system("pause");
    return 0;
}
