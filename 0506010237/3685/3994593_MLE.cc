#include<iostream>
using namespace std;
const int base=100000000;
struct node{
     int x;
     int y;
     __int64 v;  
}heap[base];
int len;
int visit[50005];
int sum[100000];
__int64 n,m,t,c;
void init(){ 
    for(int i=1;i<=n;i++)  sum[i]=sum[i-1]+i;
    for(int i=n-1;i>=1;i--) sum[i]+=sum[i-1];
    int j=0;
    while(sum[j]<m) j++; j--;
    for(int i=1;i<=n;i++){
         int k=i+n-j;
         if(k<1) k=1;
         if(k>n) k=n+1;
         visit[i]=k;     
    }
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
__int64 getmin(int &i,int &j){
     node mins=heap[1];
     heap[1]=heap[len]; 
     len--;
     heapify(1);
     i=mins.x, j=mins.y;
     return mins.v;       
}
int main(){
    int i,j;
    __int64 s,s1;
    cin>>t;
    while(t--){
         cin>>n>>m;
         init(); len=1;
         heap[1].x=1; heap[1].y=n; s1=1+n*n+n+(-n+1)*100000; visit[1]=n; heap[1].v=0;
         while(m){
               s=getmin(i,j);
               if(j>1 && visit[i]>j-1){
                     visit[i]=j-1; len++;
                     heap[len].x=i; heap[len].y=j-1; 
                     heap[len].v=s-2*j+1-i+100000;
                     increase(len);
               }
               if(i<n && visit[i+1]>j){
                     visit[i+1]=j; len++;
                     heap[len].x=i+1; heap[len].y=j;
                     heap[len].v=s+2*i+1+j+100000;
                     increase(len);                 
               }
               m--;         
         }   
         cout<<s+s1<<endl;  
    }
    system("pause");
    return 0;
}
