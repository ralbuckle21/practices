#include<iostream>
#include<math.h>
using namespace std;
int stack[1000];
int r;
typedef struct enode{
   int adj;
   struct enode *next;        
}enode;
typedef struct vnode{
    enode *find;
    int v;
    int maxv;
    int len;
}vnode;
typedef vnode List[1000];
typedef struct graphic{
    List list;
    int n,e;       
}graphic;
void create(graphic *g){
    for(int i=0;i<g->n;i++){
        scanf("%d",&g->list[i].v);
        g->list[i].find=NULL;
        g->list[i].maxv=0;
        g->list[i].len=1;
    }
    for(int i=0;i<g->e;i++){
        int k,m;   
        scanf("%d %d",&k,&m);
        k--;m--;
        enode *p=(enode *)malloc(sizeof(enode));
        p->adj=m; p->next=g->list[k].find; g->list[k].find=p;    
    }
}
int dfs(graphic *g,int k){
     int ww,llen,wu=0,ulen=0;
     double aa,xy=0;
     enode *p=g->list[k].find;
     while(p){
           ww=dfs(g,p->adj);
           llen=g->list[p->adj].len;
           double aa=ww/llen;
           if(aa>xy){ 
               xy=aa;
               wu=ww;
               ulen=llen;
           }
           p=p->next;        
     } 
     g->list[k].maxv=wu+g->list[k].v;
     g->list[k].len=ulen+1;
     return g->list[k].maxv;
}
void getv(graphic *g,int k){
    int sum=0,c=1,hlen=0;
    stack[hlen++]=k;
    while(hlen){
         double ggv=0;
         int u;
         for(int i=0;i<hlen;i++){
              if(double(g->list[stack[i]].maxv)/g->list[stack[i]].len>ggv){
                   ggv= g->list[stack[i]].maxv/g->list[stack[i]].len;
                   u=i;                               
              }
         }
         sum+=g->list[stack[u]].v*c;c++;
         enode *p=g->list[stack[u]].find;
         while(p){
              stack[hlen++]=p->adj;
              p=p->next;         
         } 
         stack[u]=stack[hlen-1];
         hlen--;     
    } 
    cout<<sum<<endl;   
}
int main()
{
    while(true){
       graphic *g=(graphic *)malloc(sizeof(graphic));
       scanf("%d %d",&g->n,&r);
       if(g->n==0 && r==0) break;
       g->e=g->n-1; r--;       
       create(g);
       dfs(g,r);
      getv(g,r);
       free(g);
    }
   system("pause");
   return 0;
}

