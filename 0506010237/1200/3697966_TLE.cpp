#include<iostream>
#include<string>
using namespace std;
const int maxs=1000000;
char c[16000005];
char key[16000005];
int n,m;
long long sum=0;
struct node{
    char key[32];
    struct node *next;      
}*s[maxs];
int hash(char *keys){
     long long h=0;
     for(int i=0;i<n;i++) h=h*26+keys[i]-97;
     int hh=h%maxs;
     return hh;
}
int insert(char *key1)
{
    int dir=hash(key1),len=n;
    if(!s[dir]){ //这个关键码还是为空 
        s[dir]=new node;
        strcpy(s[dir]->key,key1);
        s[dir]->next=NULL;
        return 1;
    }
    node *p=s[dir];
    while(p && strcmp(p->key,key1)!=0) p=p->next;
    if(p) return 0; // 已存在 
    p=new node; strcpy(p->key,key1);
    p->next=s[dir]; s[dir]=p;
    return 1; 
}
int main()
{
     cin>>n>>m;
     scanf("%s",c);
     int len=strlen(c)-n;
     strncpy(key,c,n);
     sum += insert(key);
     for(int i=1;i<=len;i++){
         key[n+i-1]=c[n+i-1]; 
         sum += insert(key+i);                   
     }
     cout<<sum<<endl;
     system("pause");
     return 0;
}
