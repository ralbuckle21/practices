#include<iostream>
#define base 1024*1024+10
using namespace std;
struct node{ 
     int v;
     int lson,rson;    
}a[base];
int tag,n,m;
int f[base],b[base];
int powv(int k){
    int sum=1;
    for(int i=1;i<=k;i++) sum=sum*2;
    return sum;   
}
void dfs(int k){
    if(a[k].lson<=m) dfs(a[k].lson);
    if(a[k].rson<=m) dfs(a[k].rson);
    f[tag++]=a[k].v;     
}
int list(){
    int len=1,p,r,mid;    
    b[0]=-10; b[1]=f[1];
    for(int i=2;i<=m;i++){
         p=0; r=len;
         while(p<=r){
              int mid=(p+r)/2;
              if(b[mid]<f[i]) p=mid+1;
              else r=mid-1;            
         }        
         b[p]=f[i];
         if(p>len) len=len+1;
    }
    return len;
}
int main(){
    int x;
    while(scanf("%d",&n)!=EOF){
         m=powv(n)-1;  tag=1;   
         for(int i=1;i<=m;i++){
              scanf("%d",&a[i].v);
              a[i].lson=i*2; a[i].rson=i*2+1;       
         }                         
         dfs(1);
         printf("%d\n",m-list());
    }  
    system("pause");
    return 0;
}
