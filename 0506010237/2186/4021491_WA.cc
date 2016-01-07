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
    scanf("%d%d",&g->n,&g->e);  
    for(int i=0;i<g->n;i++){ 
        g->list[i].find=NULL;
        g->list[i].ssv=0;
    }     
    for(int i=0;i<g->e;i++){
        int k,m;   
        scanf("%d %d",&k,&m);
        k--;m--;
        enode *p=(enode *)malloc(sizeof(enode));
        p->adj=k; p->vs=false; p->v=0;
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
              xy+=p->v;
              p=p->next;                
        }
        g->list[i].ssv=xy;
     }
     int sum=0;
     for(int i=0;i<g->n;i++)
        if(g->list[i].ssv==g->n-1) sum++;
     printf("%d\n",sum);
}
int main(){
    graphic *g=(graphic *)malloc(sizeof(graphic));
    create(g);
    dbfst(g);
    system("pause");
    return 0;
}


