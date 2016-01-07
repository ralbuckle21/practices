#include<iostream>
#include<math.h>
using namespace std;
int sign[200002]={0},sum=0;
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
    int e;      
}graphic;
void create(graphic *g){ 
    for(int i=1;i<=g->n;i++) g->list[i].find=NULL;    
    for(int i=1;i<=g->e;i++){
        enode *p=(enode *)malloc(sizeof(enode));
        int k,m,w;
        char c;  
        scanf("%d %d %d %c",&k,&m,&w,&c);
        p->adj=m; p->len=w;p->value=-1;
        p->next=g->list[k].find;g->list[k].find=p;
        p=(enode *)malloc(sizeof(enode));
        p->adj=k; p->len=w;p->value=-1;
        p->next=g->list[m].find;g->list[m].find=p;
        sign[k]++;sign[m]++;     
    }
}
int maxvalue(int a,int b){
    return  a>b?a:b;    
}
int dfs(graphic *g,int i){
       int maxs=0;
       enode *p=g->list[i].find;
       visit[i]=true;
       while(p)
       {
           if(!visit[p->adj]){
                if(p->value==-1)
                {
                   if(sign[p->adj]==1) p->value=p->len;               
                   else if(sign[p->adj]>1) p->value=p->len+dfs(g,p->adj);
                }
                maxs=maxvalue(p->value,maxs);
           }
           p=p->next;        
       }  
       visit[i]=false;
       return maxs;
}
void total(){
    int t,totals=0,max;
    graphic *g=(graphic *)malloc(sizeof(graphic));
    scanf("%d %d",&g->n,&g->e);
    if(g->n<=1){free(g);printf("0\n");}
    else{
    create(g);
    for(int i=1;i<=g->n;i++){
       if(sign[i]==1){
            visit[i]=true;
            for(enode *p=g->list[i].find;p;p=p->next){
                 if(p->value==-1){
                        if(sign[p->adj]==1) p->value=p->len;   
                        else p->value=dfs(g,p->adj)+p->len;
                 }          
                 totals=maxvalue(totals,p->value);
            }  
            visit[i]=false;        
            if(sum<totals) sum=totals;
            totals=0;
       }
    }
    printf("%d\n",sum);
    }  
}
int main()
{
   total();
   system("pause");
   return 0;
}
