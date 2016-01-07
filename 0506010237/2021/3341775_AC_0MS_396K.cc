#include<iostream>
using namespace std;
typedef struct
{
    char name[20];
    int pre;
    int v;
    bool flag;
    bool flagx;   
    int vs;    
}hashtable;
typedef struct
{
    char prename[20];
    char name[20];
    int vs;       
}node;
int t,n,cs=1,len,p;
char mg[100];
int search(hashtable ha[100],char k[100])
{
    int i,key=0,len=strlen(k);
    for(i=0;i<len;i++) key=key+int(k[i]-'0');
    key=key%p;
    while(strcmp(ha[key].name,k)!=0)
             key=(key+1)%p;    
    return key;
}
void insert(hashtable ha[100],char pk[100],char k[100],int vs)
{
    int i,key=0,len=strlen(pk);
    for(i=0;i<len;i++) key=key+int(pk[i]-'0');
    key=key%p;
    while(ha[key].flagx && strcmp(ha[key].name,pk)!=0)key=(key+1)%p;
	if(!ha[key].flagx)
	{
         ha[key].flagx=1;
         strcpy(ha[key].name,pk);   
         if(strcmp(pk,"Ted")==0)
         {
            ha[key].flag=1;
            ha[key].v=100;                      
         }
	}
    int pr=key;
    key=0,len=strlen(k);
    for(i=0;i<len;i++) key=key+int(k[i]-'0');
    key=key%p;
	while(ha[key].flagx && strcmp(ha[key].name,k)!=0) key=(key+1)%p; 
	if(!ha[key].flagx)
	{
        ha[key].flagx=1;
        strcpy(ha[key].name,k);
	}
	ha[key].pre=pr;    
    ha[key].vs=vs;
}
int find(hashtable ha[100],int key)
{
        if(!ha[key].flag)
        {
            ha[key].v=find(ha,ha[key].pre)-ha[key].vs;
            ha[key].flag=true;
        }
        return ha[key].v;                     
}
int cmp(const void *a,const void *b)
{
    hashtable *c = (hashtable *)a;
    hashtable *d = (hashtable *)b;
    if(c->v != d->v) return d->v - c->v;
    return strcmp((*(hashtable *)a).name,(*(hashtable *)b).name);
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
         scanf("%d",&n);
         p=n+1;
         hashtable ha[100];
         node sign[100];
         for(int i=0;i<p;i++){ ha[i].flag=ha[i].flagx=0;}          
         for(int i=0;i<n;i++)
         {
             scanf("%s %s %d",sign[i].prename,sign[i].name,&sign[i].vs);
			 insert(ha,sign[i].prename,sign[i].name,sign[i].vs);      
         }   
         for(int i=0;i<n;i++)
         {
              int key=search(ha,sign[i].name);
              if(!ha[key].flag)
              {
                   ha[key].v=find(ha,ha[key].pre)-sign[i].vs;
                   ha[key].flag=true;                 
              }
         }  
         qsort(ha,p,sizeof(ha[0]),cmp);
         printf("DATASET %d\n",cs++);
         for(int i=1;i<p;i++)
            printf("%s %d\n",ha[i].name,ha[i].v);
    }
    system("pause");
    return 0;
}
