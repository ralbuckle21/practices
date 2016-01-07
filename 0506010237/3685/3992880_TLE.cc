#include<iostream>
using namespace std;
const int base=10000000;
struct node{
     int x;
     int y;
     int v;  
}heap[base];
int len;
int visit[50005];
int n,m,t,c;
void init(){
    for(int i=1;i<=n;i++)  visit[i]=n+1;     
}
void heapify(int k){
     int mins=k,lchild=2*k,rchild=2*k+1;
     if(lchild<=len && heap[mins].v>heap[lchild].v) mins=lchild;
     if(rchild<=len && heap[mins].v>heap[rchild].v) mins=rchild;
     if(mins!=k){
         swap(heap[mins],heap[k]);   
         heapify(mins);         
     }
}
void increase(int k){
     int parent=k/2;
     if(parent>0 && heap[parent].v>heap[k].v){
         swap(heap[parent],heap[k]);
         increase(parent);            
     }    
}
int getmin(int &i,int &j){
     node mins=heap[1];
     heap[1]=heap[len]; 
     len--;
     heapify(1);
     i=mins.x, j=mins.y;
     return mins.v;       
}
int main(){
    int i,j,s;
    scanf("%d",&t);
    while(t--){
         scanf("%d%d",&n,&m);
         init(); len=1;
         heap[1].x=1; heap[1].y=n; heap[1].v=1+n*n+n+100000*(1-n); visit[1]=n;
         while(m){
               s=getmin(i,j);
               if(j>1 && visit[i]>j-1){
                     visit[i]=j-1; len++;
                     heap[len].x=i; heap[len].y=j-1; 
                     heap[len].v=i*i+(j-1)*(j-1)+i*(j-1)+100000*(i-(j-1));
                     increase(len);
               }
               if(i<n && visit[i+1]>j){
                     visit[i+1]=j; len++;
                     heap[len].x=i+1; heap[len].y=j;
                     heap[len].v=(i+1)*(i+1)+j*j+(i+1)*j+100000*((i+1)-j);
                     increase(len);                 
               }
               m--;         
         }         
         printf("%d\n",s);  
    }
    system("pause");
    return 0;
}
