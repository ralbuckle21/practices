/* 采用枚举+dp+trie  ：枚举单词的所有改变，dp记载最大的长度,trie用来查询单词 */ 
#include<iostream>
using namespace std;
char c[25000][20];
char temp[20];
char d[3]={'z','z','a'};
int len[25000];
int f[25000];
int n=0;
struct node{
    node *child[26];
    int sign;
    bool end;      
}*root;
void trie(){
    root=new node;
    for(int i=0;i<26;i++) root->child[i]=NULL;
    root->end=false;      
}
void insert(int k){
    node *r=root,*p;
    for(int i=0;i<len[k];i++){
         if(r->child[c[k][i]-'a']==NULL){
              p=new node; p->end=false;
              for(int j=0;j<26;j++) p->child[j]=NULL;
              r->child[c[k][i]-'a']=p;                                
         }        
         r=r->child[c[k][i]-'a'];
         if(i==len[k]-1){
              r->end=true;
              r->sign=k;               
         }
    }     
}
int search(){
    node *r=root;
    int lens=strlen(temp);
    for(int i=0;i<lens;i++){
         r=r->child[temp[i]-'a'];
         if(r==NULL) return -1;
         if(i==lens-1 && r->end) return r->sign;        
    }   
    return -1;
}
void add(int k,int x,int y){
    for(int i=0;i<x;i++) temp[i]=c[k][i];
    temp[x]=y;
    for(int i=x;i<len[k];i++) temp[i+1]=c[k][i];
    temp[len[k]+1]='\0';     
}
void change(int k,int x,int y){
    strcpy(temp,c[k]);
    temp[x]=y;     
}
void delect(int k,int x){
     for(int i=0;i<x;i++) temp[i]=c[k][i];
     for(int i=x+1;i<len[k];i++) temp[i-1]=c[k][i];
     temp[len[k]-1]='\0';    
}
void edit(int k,int type,int x,int y){
    if(type==0) add(k,x,y);
    else if(type==1) change(k,x,y);
    else delect(k,x);     
}
int main(){
    trie();
    while(scanf("%s",c[n])!=EOF && c[n][0]!='.'){
        len[n]=strlen(c[n]);
        insert(n);
        n++;
    }
    for(int k=0;k<n;k++){
        f[k]=1;
        for(int type=0;type<3;type++){
            for(int x=0;x<len[k];x++){
                for(int y='a';y<=d[type];y++){
                      edit(k,type,x,y);
                      if(strcmp(temp,c[k])>=0) break;
                      int v=search();
                      if(v>=0 && f[v]+1>f[k]) f[k]=f[v]+1;    
                }        
            }        
        }        
    }
    int result=0;
    for(int k=0;k<n;k++) if(f[k]>result) result=f[k];
    printf("%d\n",result); 
    system("pause");
    return 0;
}
