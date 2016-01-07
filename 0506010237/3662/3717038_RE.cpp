#include<iostream>
using namespace std;
const int maxs=INT_MAX;
int n,p,k;
int cost[1010][1010];
int f[1010][501];
bool visit[1010][501];
struct node{
    int u;
    int v;   
}heap[501100];
int len=1;
int index[1010][501];
void init(){
     for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
            cost[i][j]=maxs; 
     for(int i=2;i<=n;i++)
        for(int j=0;j<=k;j++){
            f[i][j]=maxs;   
            index[i][j]=len;
            heap[len].u=i; heap[len].v=j;
            len++;
        }
}
int maxv(int a,int b){ return a>b?a:b; }
int minv(int a,int b){ return a<b?a:b; }
void heapify(int i){
     int mins=i,lchild=2*i,rchild=2*i+1;
     if(lchild<len && f[heap[lchild].u][heap[lchild].v]<f[heap[mins].u][heap[mins].v]) mins=lchild;
     if(rchild<len && f[heap[rchild].u][heap[rchild].v]<f[heap[mins].u][heap[mins].v]) mins=rchild;
     if(mins!=i){
         node temp=heap[i]; heap[i]=heap[mins]; heap[mins]=temp;
         int xt=index[heap[i].u][heap[i].v];
         index[heap[i].u][heap[i].v]=index[heap[mins].u][heap[mins].v];
         index[heap[mins].u][heap[mins].v]=xt;
         heapify(mins);       
     }    
}
void buildheap(){
     for(int i=len/2;i>0;i--) heapify(i);    
}
void getmin(){
     len--;
     heap[1]=heap[len];
     index[heap[1].u][heap[1].v]=index[heap[len].u][heap[len].v];
     heapify(1);     
}
void increase(int i){
     int parent=i/2;
     if(parent>0 && f[heap[parent].u][heap[parent].v]>f[heap[i].u][heap[i].v]){
            node temp=heap[parent]; heap[parent]=heap[i]; heap[i]=temp;
            int tx=index[heap[parent].u][heap[parent].v];
            index[heap[parent].u][heap[parent].v]=index[heap[i].u][heap[i].v];
            index[heap[i].u][heap[i].v]=tx;
            increase(parent);     
     }    
}
int shortpath(){
     int u,v;
     for(int i=2;i<=n;i++){
         if(cost[1][i]!=maxs && k>0) f[i][1]=0;
         f[i][0]=cost[1][i];    
     }
     buildheap();
    while(true){
         u=heap[1].u; v=heap[1].v; getmin();
         int min=f[u][v];
         if(u==n || min==maxs) return min;
         visit[u][v]=true;
         for(int w=2;w<=n;w++){ 
             if(cost[u][w]!=maxs){
                  int vv=maxv(f[u][v],cost[u][w]);
                  f[w][v]=minv(vv,f[w][v]);
                  increase(index[w][v]);
                  if(v<k){
                       f[w][v+1]=minv(f[u][v],f[w][v+1]);
                       increase(index[w][v+1]);
                  }                     
             }        
        }        
     }              
     return maxs;
}
int main()
{ 
     int s,d,w;  
     scanf("%d %d %d",&n,&p,&k);
     init();
     while(p--){
         scanf("%d%d%d",&s,&d,&w);
         cost[s][d]=w;
         cost[d][s]=w;           
     }
     int result=shortpath();
     if(result<maxs)  printf("%d\n",result);
     else printf("-1\n");
     system("pause");
     return 0;
}
