#include<iostream>
#include<math.h>
using namespace std;
bool visit[10000];
typedef struct enode{
   int adj; 
   struct enode *next;        
}enode;
typedef struct vnode{
    enode *find;
}vnode;
typedef vnode List[10000];
typedef struct graphic{
    List list;
    int n,e;       
}graphic;
typedef struct Edge{
    int s, e;
} Edge;
Edge E[100000];
int order[10000],id[10000],in[10000];
int cnt;
void create(graphic *g,graphic *g1){
    scanf("%d %d",&g->n,&g->e);
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
void dfs2(graphic *g,int i){
     enode *p=g->list[i].find;
     visit[i]=true;
     while(p){
          if(id[i]!=id[p->adj]) in[i]++;
          if(!visit[p->adj]) dfs(g,p->adj);
          p=p->next;         
     }
}
int main(){
   int pos;
   graphic *g=(graphic *)malloc(sizeof(graphic));
   graphic *g1=(graphic *)malloc(sizeof(graphic));
   create(g,g1);
   memset(visit,0,sizeof(visit)); cnt=0;
   for(int i=0;i<g->n;i++)
       if(!visit[i]) dfs1(g1,i);
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
    int scnt = cnt;
    cnt = 0;
    for(int i = 0; i < scnt; i++){ //如果强连通则只有一个为0 
        if (in[i] == 0){
            pos = i; //保存了最后的那个部落 
            cnt++;
        }
    }
    if (cnt != 1) printf("0\n");
    else{
        cnt = 0;
        for (int i = 0; i < g->n; i++)
            if (in[id[i]] == pos) //求出最后那个部落的人数 
                cnt++;
        printf("%d\n", cnt);
    }
   system("pause");
   return 0;
}
