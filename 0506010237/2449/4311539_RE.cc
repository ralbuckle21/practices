#include<iostream>
using namespace std;
const int base=5000000;
const int maxs=INT_MAX;
int map[1010][1010];
int mpw[1010][1010];
int n,m,k,s,d;
int c[1010];
struct node{
    int u;
    int v;   
}list[base];
int len=1;
void swap(int a,int b){
     node tmp=list[a];
     list[a]=list[b];
     list[b]=tmp;     
}
void heap(int i){
     int lchild=2*i,rchild=2*i+1,mins=i;
     if(lchild<=len && list[lchild].v<list[mins].v) mins=lchild;
     if(rchild<=len && list[rchild].v<list[mins].v) mins=rchild;
     if(mins!=i){
          swap(list[i],list[mins]);
          heap(mins);            
     }
}
void inheap(node key){
     list[++len]=key;
     int i=len;
     while(i>1 && list[i/2].v>list[i].v){
         swap(list[i/2],list[i]);
         i=i/2;          
     }     
}
node getmin(){
    node mins=list[1];
    list[1]=list[len];
    len--;
    if(len>1) heap(1);
    return mins;     
}
int dbfs(){
    int u,v;
    memset(c,0,sizeof(c));
    list[len].u=s; list[len].v=0;
    while(len>0){
        node front=getmin();
        u=front.u; v=front.v;
        c[u]++;
        if(c[d]==k) return v;
        if(c[u]>k) continue;
        for(int i=1;i<=map[u][0];i++){
             node rear;
             rear.v=v+mpw[u][i];
             rear.u=map[u][i];
             inheap(rear);        
        }             
    }    
    return -1;
}
int main(){
    int x,y,pow;
    memset(map,0,sizeof(map));
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&x,&y,&pow);
        map[x][++map[x][0]]=y;    
        mpw[x][map[x][0]]=pow;
    }
    scanf("%d%d%d",&s,&d,&k);
    if(s==d) k++;
    printf("%d\n",dbfs());
    system("pause");
    return 0;
}
