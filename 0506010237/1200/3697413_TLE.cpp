#include<iostream>
#include<string>
using namespace std;
const int maxs=100000;
char c[16000005];
char key[16000005];
long long n,m,sum=0;
struct node{
    char key[32];
    struct node *next;      
}*s[maxs];
int insert()
{
    int dir,len=n;
    if(len==1) dir=key[0]-'A';
    else dir=key[0]-'A'+(key[1]-'A')*41+(key[len-1]-'A')*1681+(key[len-2]-'A')*1681*41;
    dir=dir%maxs;
    if(!s[dir]){ //这个关键码还是为空 
        s[dir]=new node;
        strcpy(s[dir]->key,key);
        s[dir]->next=NULL;
        return 1;
    }
    node *p=s[dir];
    while(p && strcmp(p->key,key)!=0) p=p->next;
    if(p) return 0; // 已存在 
    p=new node; strcpy(p->key,key);
    p->next=s[dir]; s[dir]=p;
    return 1; 
}
int main()
{
     cin>>n>>m;
     scanf("%s",c);
     int len=strlen(c)-n;
     for(int i=0;i<=len;i++){
         strncpy(key,c+i,n);
         sum += insert();                   
     }
     cout<<sum<<endl;
     system("pause");
     return 0;
}
