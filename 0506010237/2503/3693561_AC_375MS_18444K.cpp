#include<iostream>
using namespace std;
struct node{
      node *child[26];
      char key[20];
      bool d;  
}*root;
char s1[20],s2[20],s3[20];
void trie(){
    root=new node;
    for(int i=0;i<26;i++) root->child[i]=NULL;
    root->d=false;    
}
void insert(){
    node *r=root,*p;
    int len=strlen(s3);
    for(int i=0;i<len;i++){
         if(r->child[s3[i]-'a']==NULL){
               p=new node; p->d=false;
               for(int j=0;j<26;j++) p->child[j]=NULL;
               r->child[s3[i]-'a']=p;                       
         }  
         r=r->child[s3[i]-'a'];      
         if(i==len-1){
              r->d=true;
              strcpy(r->key,s2); 
         }            
    } 
}
bool search(){
    node *r=root;
    int len=strlen(s1);
    for(int i=0;i<len;i++){
        r=r->child[s1[i]-'a'];        
        if(r==NULL) return false;
        if(i==len-1 && r->d){
            strcpy(s2,r->key);
            return true;     
        }     
    }     
    return false;
}
int main()
{
     int i,j,k,len;
     trie();
     while(true){
         gets(s1); if(strcmp(s1,"")==0) break;
         for(i=0;s1[i]!=' ';i++) s2[i]=s1[i];
         for(i=i+1, j=0, len=strlen(s1);i<len;i++,j++) s3[j]=s1[i];
         insert();            
     }
     while(scanf("%s",s1)!=EOF){
         if(search()) printf("%s\n",s2);
         else printf("eh\n");
                                    
     }
     system("pause");
     return 0;
}
