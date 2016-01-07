#include<iostream>
#include<string>
using namespace std;
const int maxs=1000000;
char c[16000005];
char key[16000005];
long long n,m,sum=0;
struct node{
    char key[32];
    struct node *next;      
}*s[maxs];
int insert(char *key1)
{
    int dir,len=n;
    if(len==1) dir=key1[0]-'A';
    else dir=key1[0]-'A'+(key1[1]-'A')*41+(key1[len-1]-'A')*16810+(key1[len-2]-'A')*168100;
    dir=dir%maxs;
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
