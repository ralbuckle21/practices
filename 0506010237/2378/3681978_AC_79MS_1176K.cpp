#include<iostream>
#include<math.h>
using namespace std;
bool visit[20000];
typedef struct enode{
   int adj;
   bool vs;
   int v;
   struct enode *next;        
}enode;
typedef struct vnode{
    enode *find;
    int ssv;
}vnode;
typedef vnode List[20000];
typedef struct graphic{
    List list;
    int n,e;       
}graphic;
void create(graphic *g){
    scanf("%d",&g->n);
    g->e=g->n-1;   
    for(int i=0;i<g->n;i++){  
        g->list[i].find=NULL;
        g->list[i].ssv=0;
    }     
    for(int i=0;i<g->e;i++){
        int k,m;   
        scanf("%d %d",&k,&m);
        k--;m--;
        enode *p=(enode *)malloc(sizeof(enode));
        p->adj=m; p->vs=false; p->v=0;
        p->next=g->list[k].find; g->list[k].find=p;
        p=(enode *)malloc(sizeof(enode));
        p->adj=k; p->v=0; p->vs=false;
        p->next=g->list[m].find; g->list[m].find=p;      
    }
}
int dfs(graphic *g,int k){
     int xy=0;
     visit[k]=true;
     enode *p=g->list[k].find;
     while(p){
          if(!visit[p->adj]){
               if(!p->vs){
                   p->v=dfs(g,p->adj);
                   p->vs=true;
               }
               xy += p->v; 
          } 
          p=p->next;        
     } 
     return xy+1;
}
void dbfst(graphic *g){
     for(int i=0;i<g->n;i++){
          memset(visit,0,sizeof(visit));
          dfs(g,i);
     }
     for(int i=0;i<g->n;i++){
        int xy=0;
        enode *p=g->list[i].find;
        while(p){
              if(p->v>xy) xy=p->v;
              p=p->next;                
        }
        g->list[i].ssv=xy;
     }
     int u=g->n/2;
     for(int i=0;i<g->n;i++)
        if(g->list[i].ssv<=u) 
           printf("%d\n",i+1);
}
int main()
{
    graphic *g=(graphic *)malloc(sizeof(graphic));
    create(g);
   dbfst(g);
   system("pause");
   return 0;
}

