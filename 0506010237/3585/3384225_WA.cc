#include<iostream>
#include<math.h>
using namespace std;
int sign[200002],sum=0;
bool visit[200002]={0};
typedef struct enode{
   int adj;  
   int len; 
   int value;
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
void create(graphic *g){ 
    for(int i=1;i<=g->n;i++) g->list[i].find=NULL;      
    for(int i=1;i<g->n;i++){
        enode *p=(enode *)malloc(sizeof(enode));
        int k,m,w;  
        scanf("%d %d %d",&k,&m,&w);
        p->adj=m; p->len=w;p->value=-1;
        p->next=g->list[k].find;g->list[k].find=p;
        p=(enode *)malloc(sizeof(enode));
        p->adj=k; p->len=w;p->value=-1;
        p->next=g->list[m].find;g->list[m].find=p;
        sign[k]++;sign[m]++;     
    }
}
int minvalue(int a,int b){
    return  a<b?a:b;    
}
int dfs(graphic *g,int i){
       int mins=0,mins1;
       enode *p=g->list[i].find;
       visit[i]=true;
       while(p)
       {
           if(!visit[p->adj]){
                if(p->value==-1)
                {
                   if(sign[p->adj]==1) p->value=p->len;               
                   else if(sign[p->adj]>1) p->value=minvalue(p->len,dfs(g,p->adj));
                }
                mins+=p->value;
           }
           p=p->next;        
       }  
       visit[i]=false;
       return mins;
}
void total(){
    int t,totals=0,max;
    graphic *g;
    scanf("%d",&t);
    while(t--){
         g=(graphic *)malloc(sizeof(graphic));
         scanf("%d",&g->n);
         for(int i=0;i<=g->n;i++) sign[i]=0;
         create(g);
         for(int i=1;i<=g->n;i++){
             if(sign[i]>1){
                 visit[i]=true;
                 for(enode *p=g->list[i].find;p;p=p->next){
                     if(p->value==-1){
                            if(sign[p->adj]==1) p->value=p->len;   
                            else p->value=minvalue(p->len,dfs(g,p->adj));
                     }          
                     totals=totals+p->value;
                 }  
                 visit[i]=false;        
                 if(sum<totals) sum=totals;
                 totals=0;
             }
         }
         printf("%d\n",sum);  
         sum=0;  
         free(g);
    }
}
int main()
{
   total();
   system("pause");
   return 0;
}
