#include<iostream>
using namespace std;
const int maxs=0x7fffffff;
const int Nmax=1000010;
typedef struct node{ //邻接表 
     int next;  
     int d;
     int w;
}node;
node g[Nmax],rg[Nmax];
int p[Nmax],rp[Nmax];
int dist[Nmax];
bool used[Nmax];
int q[Nmax];
int front,rear;
int n,e,t;
long long sum=0;
void init(){
    memset(p,-1,sizeof(p));
    memset(rp,-1,sizeof(rp));     
}
void SPFA(node g[],int p[]){
    for(int i=1;i<=n;i++) dist[i]=maxs; dist[1]=0;
    memset(used,0,sizeof(used));
    front=-1; rear=0;
    q[rear]=1; used[1]=true;
    while(front!=rear){
         front=(front+1)%Nmax;
         int tmp=q[front];
         for(int j=p[tmp];j!=-1;j=g[j].next){
              if(dist[tmp]<maxs && dist[tmp]+g[j].w<dist[g[j].d]){
                   dist[g[j].d]=dist[tmp]+g[j].w;
                   if(!used[g[j].d]){
                         used[g[j].d]=true;
                         rear=(rear+1)%Nmax;
                         q[rear]=g[j].d;                  
                   }                  
              }        
         } 
         used[tmp]=false;                  
    }
    for(int i=1;i<=n;i++) sum += dist[i];
}
int main(){
    int x,y,pow;
    scanf("%d",&t);
    while(t--){
         init();
         scanf("%d%d",&n,&e);
         for(int i=0;i<e;i++){
              scanf("%d%d%d",&x,&y,&pow);
              g[i].next=p[x];
              g[i].w=pow;
              g[i].d=y;
              p[x]=i;
              /******/
              rg[i].next=rp[y];
              rg[i].w=pow;
              rg[i].d=x;
              rp[y]=i;     
         }  
         SPFA(g,p);
         SPFA(rg,rp);       
         printf("%lld\n",sum);
         sum=0;    
    }
    system("pause");
    return 0;
}
