#include<iostream>
#include<math.h>
using namespace std;
bool visit[10010];
typedef struct enode{
   int adj; 
   struct enode *next;        
}enode;
typedef struct vnode{
    enode *find;
}vnode;
typedef vnode List[10010];
typedef struct graphic{
    List list;
    int n,e;       
}graphic;
typedef struct Edge{
    int s, e;
} Edge;
Edge E[500000];
int order[10010],id[10010],in[10010];
int cnt;
void create(graphic *g,graphic *g1){
    scanf("%d",&g->e);
    g1->n=g->n; g1->e=g->e;   
    for(int i=0;i<g->n;i++){
        g->list[i].find=NULL;
        g1->list[i].find=NULL;
    }   
    for(int i=0;i<g->e;i++){
        enode *p=(enode *)malloc(sizeof(enode));
        int k,m;   
        scanf("%d%d",&k,&m);
        k--; m--;
        E[i].s=k; E[i].e=m;
        p->adj=m; p->next=g->list[k].find;
        g->list[k].find=p;
        p=(enode *)malloc(sizeof(enode));
        p->adj=k;  p->next=g1->list[m].find;
        g1->list[m].find=p;    
    }
}
void dfs1(graphic *g,int i){
       enode *p=g->list[i].find;;
       visit[i]=true;
       while(p) {
           if(!visit[p->adj]) dfs1(g,p->adj);
           p=p->next;        
       }  
       order[cnt++]=i;
}
void dfs(graphic *g,int i){
       enode *p=g->list[i].find;;
       visit[i]=true;
       id[i]=cnt;
       while(p) {
           if(!visit[p->adj])dfs(g,p->adj);
           p=p->next;        
       }  
}
bool solve(){
   int pos;
   graphic *g=(graphic *)malloc(sizeof(graphic));
   scanf("%d",&g->n); if(g->n==0) return false;
   graphic *g1=(graphic *)malloc(sizeof(graphic));
   create(g,g1);
   memset(visit,0,sizeof(visit)); cnt=0;
   for(int i=0;i<g->n;i++) if(!visit[i]) dfs1(g1,i);
   memset(visit,0,sizeof(visit)); cnt=0;
   for(int i=g->n-1;i>=0;i--){
       if(!visit[order[i]]){ 
            dfs(g,order[i]);
            cnt++;        
       }
   }
   int s,e;
   for (int i = 0; i < g->e; i++){ //一个部落能通往其他部落则为1 
        s = id[E[i].s];
        e = id[E[i].e];
        if (s != e)  in[s]++;
    }
    memset(visit,0,sizeof(visit));
    for(int j=0;j<g->n;j++)
       if(in[id[j]]==0) visit[j]=true;
    for (int i = 0; i < g->n; i++)
         if (visit[i]) printf("%d ",i+1);
    printf("\n");  
    free(g); free(g1);
    return true;
}
int main(){
   while(solve());
   system("pause");
   return 0;
}

