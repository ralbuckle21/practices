#include<iostream>
#include<math.h>
using namespace std;
int sign[200002],sum=0;
typedef struct enode{
   int adj;  
   int len,lens; 
   struct enode *next;        
}enode;
typedef struct vnode{
    enode *find;
}vnode;
typedef vnode List[200002];
typedef struct graphic{
    List list;
    int n;       
}graphic;
int net(int s,int t,graphic *gs){
     bool visit[200002];
     int u,dist[200002],path[200002];
     enode *p;
    // for(int i=1;i<=gs->n;i++){ visit[i]=0;path[i]=s;dist[i]=0;}
     memset(visit,0,gs->n+1);
     memset(path,s,gs->n+1);
     memset(dist,0,gs->n+1);
     for(p=gs->list[s].find;p;p=p->next) dist[p->adj]=p->len;           
     visit[s]=1;path[s]=-1;
     for(int i=1;i<gs->n;i++){
        int max=0;
        for(int j=1;j<=gs->n;j++){ 
            if(visit[j]==0 && j!=s && dist[j]>max){   
               max=dist[j];
               u=j;     
            }
        }
        if(max==0) return 0;
        visit[u]=1;
        if(u==t){
            int w1=path[t],w2=t;
            while(w1!=-1){
                for(p=gs->list[w1].find;p;p=p->next)
                    if(p->adj==w2) break; 
                p->len=p->len-dist[t]; 
                if(w1!=s && w2!=t){
                    for(p=gs->list[p->adj].find;p;p=p->next)
                       if(p->adj==w1) break;
                    p->len=p->len+dist[t];  
                }
                w2=w1;w1=path[w2];
            }   
            return dist[t];
        }  
        for(int w=1;w<=gs->n;w++){
            for(p=gs->list[u].find;p;p=p->next)
                 if(p->adj==w) break;             
            if(!p) continue;
            int f=p->len;
            int minpath=dist[u]<f?dist[u]:f;
            if(visit[w]==0 && dist[w]<minpath){
                   dist[w]=minpath;
                   path[w]=u;
            }        
        }
     }
}
void create(graphic *g){ 
    for(int i=1;i<=g->n;i++) g->list[i].find=NULL;      
    for(int i=1;i<g->n;i++){
        enode *p=(enode *)malloc(sizeof(enode));
        int k,m,w;  
        scanf("%d %d %d",&k,&m,&w);
        p->adj=m; p->lens=w;
        p->next=g->list[k].find;g->list[k].find=p;
        p=(enode *)malloc(sizeof(enode));
        p->adj=k; p->lens=w;
        p->next=g->list[m].find;g->list[m].find=p;     
        sign[k]++;
        sign[m]++;
    }
}
void total(){
    int t,totals=0,max=0;
    scanf("%d",&t);
    while(t--){
         graphic *g=(graphic *)malloc(sizeof(graphic));
         scanf("%d",&g->n);
         memset(sign,0,g->n+2);
         create(g);
         for(int i=1;i<=1;i++){
             for(int j=1;j<=g->n;j++){
                 for(int x=1;x<=g->n;x++){
                      enode *p=g->list[x].find;
                      while(p){
                           p->len=p->lens;
                           p=p->next;
                      }        
                 }
                 if(sign[j]==1 && j!=i){ 
                       while(true){
                           max=net(i,j,g);
                           if(max<=0) break;//找不到增广路
                           totals=totals+max;
                       }
                 }           
             }        
             if(sum<totals) sum=totals;
             totals=0;
         }
         printf("%d\n",sum);  
         sum=0;  
    }
}
int main()
{
   total();
   system("pause");
   return 0;
}
