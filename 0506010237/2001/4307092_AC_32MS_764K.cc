#include<iostream>
using namespace std;
struct node{
    node *child[26];
    int count;   
}*root;
char c[1010][22];
int len[1010];
char temp[22];
int n=0;
void trie(){
    root=new node();
    for(int i=0;i<26;i++) root->child[i]=NULL;     
}
void insert(int k){
    node *r=root,*p;
    for(int i=0;i<len[k];i++){
         if(r->child[c[k][i]-'a']==NULL){
              p=new node; p->count=0;
              for(int j=0;j<26;j++) p->child[j]=NULL;
              r->child[c[k][i]-'a']=p;                                
         }        
         r=r->child[c[k][i]-'a'];
         r->count++;
    }
}
void search(int k){
    node *r=root;
    for(int i=0;i<len[k];i++){
        r=r->child[c[k][i]-'a'];
        temp[i]=c[k][i];
        if(r->count==1){
              temp[i+1]='\0';
              return;                
        }       
    }   
    temp[len[k]]='\0';  
}
int main(){
    trie();
    while(scanf("%s",c[n])!=EOF && c[n][0]!='.'){
          len[n]=strlen(c[n]);
          insert(n);    
          n++;
    }
    for(int i=0;i<n;i++){
          search(i);
          printf("%s %s\n",c[i],temp);        
    }
    system("pause");
    return 0;
}
