#include<iostream>
using namespace std;
int t,n,m;
int cost[1004][1004];
int heap[1004],len; //heap[i]代表所对应的节点下标 
int index[1004];//index[i]代表节点i在heap中的位置 
bool visit[1004];
int dist[1004];
int mins(int a,int b){ return a<b?a:b; }
void init(){
     for(int i=1;i<=n;i++){
         heap[i]=i;
         index[i]=i;
     }    
}
void swap(int &a,int &b){
     int temp=a;
     a=b;
     b=temp;     
}
void heapify(int k){
     int maxs=k,lchild=2*k,rchild=2*k+1;
     if(lchild<=len && dist[heap[maxs]]<dist[heap[lchild]]) maxs=lchild;
     if(rchild<=len && dist[heap[maxs]]<dist[heap[rchild]]) maxs=rchild;
     if(maxs!=k){
         swap(heap[maxs],heap[k]);   
         swap(index[heap[maxs]],index[heap[k]]);
         heapify(maxs);         
     }
}
void increase(int k){
     int parent=k/2;
     if(parent>0 && dist[heap[parent]]<dist[heap[k]]){
         swap(heap[parent],heap[k]);
         swap(index[heap[parent]],index[heap[k]]);
         increase(parent);            
     }    
}
void buildheap(){
     len=n;
     for(int i=len/2;i>0;i--) heapify(i);    
}
int getmax(){
     int maxs=heap[1];
     heap[1]=heap[len];
     index[heap[1]]=index[heap[len]];   
     len--;
     heapify(1);
     return maxs;
}
int dijstra(){
     for(int i=2;i<=n;i++){
        dist[i]=cost[1][i];
        visit[i]=false;
     }
     buildheap();
     while(true){
          int u=getmax();       
          if(u==n || dist[u]==0) return dist[u];
          visit[u]=true;
          for(int w=2;w<=n;w++){
               int v=mins(dist[u],cost[u][w]);
               if(!visit[w] && dist[w]<v){
                    dist[w]=v;        
                    increase(index[w]);
               }
          }  
     }   
}
int main()
{
     int s,d,w;
     scanf("%d",&t);
     for(int i=1;i<=t;i++){
         scanf("%d%d",&n,&m);
         memset(cost,0,sizeof(cost));
         init();
         for(int j=0;j<m;j++){
              scanf("%d%d%d",&s,&d,&w);
              cost[s][d]=w;
              cost[d][s]=w;        
         }        
         printf("Scenario #%d:\n",i);
         printf("%d\n\n",dijstra());
     }
     system("pause");
     return 0;
}
