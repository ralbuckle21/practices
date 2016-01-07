#include<iostream>
using namespace std;
const int Emax=200005;
const int Nmax=5005;
const int inf=INT_MAX;
struct node{
    int x,f;   
}list[Emax];
int len=1;
struct edge{
    int next;
    int d;
    int w;   
}g[Emax],rg[Emax];
int p[Nmax],rp[Nmax];
int dist[Nmax];
int out[Nmax];
bool visit[Nmax];
int n,m,s,t,k;
void init(){
    memset(p,-1,sizeof(p));
    memset(rp,-1,sizeof(rp));
    memset(out,0,sizeof(out));     
}
void readdata(){
    int x,y,pow;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
         scanf("%d%d%d",&x,&y,&pow);
         g[i].next=p[x]; g[i].w=pow; g[i].d=y;  p[x]=i;
         g[m+i].next=p[y]; g[m+i].w=pow; g[m+i].d=x; p[y]=m+i;
         rg[i].next=rp[y]; rg[i].w=pow; rg[i].d=x; rp[y]=i;   
         rg[m+i].next=rp[x]; rg[m+i].w=pow; rg[m+i].d=y; rp[x]=m+i; 
    } 
    s=1; t=n; k=2;    
    //scanf("%d%d%d",&s,&t,&k);
    if(s==t) k++;
}
void dijkstra(){
    int minv,u;
    memset(visit,0,sizeof(visit));
    for(int i=1;i<=n;i++) dist[i]=inf; 
    dist[t]=0; 
    while(true){
        minv=inf;
        for(int j=1;j<=n;j++){
             if(!visit[j] && dist[j]<minv){
                  minv=dist[j]; 
                  u=j;                
             }   
        }        
        if(minv==inf) break;
        visit[u]=true;
        for(int j=rp[u];j!=-1;j=rg[j].next){
             if(!visit[rg[j].d] && dist[u]+rg[j].w<dist[rg[j].d])
                dist[rg[j].d]=dist[u]+rg[j].w;         
        }
    }    
}
void swap(int a,int b){
     node tmp=list[a];
     list[a]=list[b];
     list[b]=tmp;     
}
void heap(int i){
     int lchild=2*i,rchild=2*i+1,mins=i;
     if(lchild<=len && list[lchild].f<list[mins].f) mins=lchild;
     if(rchild<=len && list[rchild].f<list[mins].f) mins=rchild;
     if(mins!=i){
          swap(list[i],list[mins]);
          heap(mins);            
     }
}
void inheap(node key){
     list[++len]=key;
     int i=len;
     while(i>1 && list[i/2].f>list[i].f){
         swap(list[i/2],list[i]);
         i=i/2;          
     }     
}
node getmin(){
    node mins=list[1];
    list[1]=list[len--];
    if(len>1) heap(1);
    return mins;     
}
int pri_bfs(){
    int ds;
    node front,rear;
    list[len].x=s; list[len].f=dist[s];
    while(len>0){
        front=getmin();
        out[front.x]++;
        if(out[t]==k) return front.f;
        if(out[front.x]>k) continue;
        for(int i=p[front.x];i!=-1;i=g[i].next){
              if(out[g[i].d]>=k) continue; 
              ds=front.f-dist[front.x]; // g(front.x)
              rear.x=g[i].d; rear.f=ds+g[i].w+dist[g[i].d];
              inheap(rear);           
        }           
    }    
    return -1;
}
void solve(){
    dijkstra();  
    printf("%d\n",pri_bfs());   
}
int main(){
    init();
    readdata();
    solve();
    system("pause");
    return 0;
}
