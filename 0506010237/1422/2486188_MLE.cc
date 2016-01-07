#include<iostream>
#include<malloc.h> 
using namespace std;
bool visit[120];
int counts,fenzhi;
typedef struct enode
{
   int adj;
   struct enode *next;        
}enode;
typedef struct vnode
{
    int indegree;
    enode *find;
}vnode;
typedef vnode List[120];
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
        g->list[i].indegree=0;      
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
void dfs1(graphic *g,int i)
{
     if(fenzhi==1)
     {
        enode *p;
        visit[i]=true;
        p=g->list[i].find;
        while(p)
        {
          g->list[p->adj].indegree++;
          if(!visit[p->adj])
              dfs1(g,p->adj);
              p=p->next; 
        }               
     }
     else
     {
         enode *p,*q;
         visit[i]=true;
         p=g->list[i].find;
         q=p;
         while(q)
         {
            g->list[q->adj].indegree--; 
            q=q->next;          
          }
         while(p)
         {
            if(!visit[p->adj])
             { 
               dfs1(g,p->adj);
               return; 
             }
             p=p->next;
         }
     }      
}
void dbfst1(graphic *g)
{
       for(int i=1;i<=g->n;i++)
         visit[i]=false;
       for(int i=1;i<=g->n;i++)
         if(!visit[i])
         {
             dfs1(g,i);
         }
       fenzhi=2;
    for(int i=1;i<=g->n;i++)
         visit[i]=false;
     for(int j=1;j<=g->n;j++)
     {
       for(int i=1;i<=g->n;i++)
        if(!visit[i] && g->list[i].indegree==0)
        {
             dfs1(g,i);
             counts++;
        }
     }
}
int main()
{
    int n;
    cin>>n;
    for(int m=1;m<=n;m++)
    {
       counts=0;
       fenzhi=1;
       graphic *g;
       g=(graphic *)malloc(sizeof(graphic));
       create(g);
       dbfst1(g);
       cout<<counts<<endl;
    }
   system("pause");
   return 0;
}
