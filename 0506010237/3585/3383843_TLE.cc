#include<iostream>
#include<math.h>
using namespace std;
int sign[200002],sum=0;
bool visit[200002]={0};
typedef struct enode{
   int adj;  
   int len; 
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
        p->adj=m; p->len=w;
        p->next=g->list[k].find;g->list[k].find=p;
        p=(enode *)malloc(sizeof(enode));
        p->adj=k; p->len=w;
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
                if(sign[p->adj]==1) mins+=p->len;               
                else if(sign[p->adj]>1) mins+=minvalue(p->len,dfs(g,p->adj));
           }
           p=p->next;        
       }  
       visit[i]=false;
       return mins;
}
void total(){
    int t,totals=0,max;
    scanf("%d",&t);
    while(t--){
         graphic *g=(graphic *)malloc(sizeof(graphic));
         scanf("%d",&g->n);
         memset(sign,0,g->n+2);
         create(g);
         for(int i=1;i<=g->n;i++){
             visit[i]=true;
             for(enode *p=g->list[i].find;p;p=p->next){ 
                if(sign[p->adj]==1) totals=totals+p->len;   
                else if(sign[p->adj]>1) totals=totals+minvalue(p->len,dfs(g,p->adj));          
             }  
             visit[i]=false;           
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


