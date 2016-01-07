#include<iostream>
#include<malloc.h> 
using namespace std;
bool visit[100];
int counts;
typedef struct enode
{
   int adj;
   struct enode *next;        
}enode;
typedef struct vnode
{
    enode *find;
}vnode;
typedef vnode List[100];
typedef struct graphic
{
    List list;
    int n,e;       
}graphic;
void create(graphic *g)
{
    cin>>g->n;
    cin>>g->e;    
    for(int i=1;i<=g->n;i++)
    {
        g->list[i].find=NULL;       
    }
    for(int i=1;i<=g->e;i++)
    {
        enode *p;
        p=(enode *)malloc(sizeof(enode));
        int k,m;
        cin>>k;
        cin>>m;
        p->adj=m;
        p->next=g->list[k].find;
        g->list[k].find=p;        
    }
}
void dfs(graphic *g,int i)
{
       enode *p;
        visit[i]=true;
       p=g->list[i].find;
       while(p)
       {
           if(!visit[p->adj])
              dfs(g,p->adj);
           else
              p=p->next;        
       }  
}
void dbfst(graphic *g)
{
     for(int i=1;i<=g->n;i++)
        visit[i]=false;
     for(int i=1;i<=g->n;i++)
        if(!visit[i])
        {
             dfs(g,i);
             counts++;
        }
}
int main()
{
    int n;
    cin>>n;
    for(int m=1;m<=n;m++)
    {
       counts=0;
       graphic *g;
       g=(graphic *)malloc(sizeof(graphic));
       create(g);
       dbfst(g);
       cout<<counts<<endl;
    }
   return 0;
}