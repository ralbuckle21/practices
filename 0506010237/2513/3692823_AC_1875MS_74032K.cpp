#include<iostream>
using namespace std;
const int maxs=500010;
int degree[maxs];
int f[maxs];
int cnt=1;
char s1[20],s2[20];
struct node{
     node *child[26];//指向其孩子 
     int id;  //关键码 
     bool d;  // 是否已结束即存在此单词 
}*root;
void trie(){ //trie树初始化 
    root=new node; root->id = 0; root->d = 0;
    for(int i=0;i<26;i++) root->child[i]=NULL;    
}
int getv(char *s){ //找到字符串所对应的关键码 
    int len=strlen(s);
    node *r = root, *temp;
    for(int i=0;i<len;i++){
        if(r->child[s[i]-'a']==NULL){//没有就就建立新的路径，有就依路径往下 
             temp=new node; temp->id=0; temp->d=0;
             for(int j=0;j<26;j++) temp->child[j]=NULL;
             r->child[s[i]-'a']=temp;                        
        }
        r=r->child[s[i]-'a'];     
    }
    if(!r->d){//以前没有此字符串 
        r->id=cnt++;
        r->d=true;          
    }
    return r->id;
}
int Find(int a){ //找其根 
     while(a!=f[a]) a=f[a];
     return a;    
}
void unions(int a,int b){ //合并 
     f[Find(a)]=f[Find(b)];    
}
void init(){
     for(int i=0;i<maxs;i++){
        f[i]=i;
        degree[i]=0;
     }
     trie();    
}
int main()
{
     int a,b;
     init();
     while(scanf("%s %s",s1,s2)!=EOF){
           a=getv(s1); b=getv(s2);
           degree[a]++; degree[b]++;
           unions(a,b);               
     }
     int sign=0,c=Find(1);
     for(int i=1;i<cnt;i++){
           if(degree[i]%2) sign++;
           if(Find(i)!=c){ //判断是否连通 
                 sign=-1;
                 break;               
           }        
     }
     if(sign==0 || sign==2) printf("Possible\n");
     else printf("Impossible\n");
     system("pause");
     return 0;
}
