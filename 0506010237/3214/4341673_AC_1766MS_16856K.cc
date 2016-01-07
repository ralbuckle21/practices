#include<iostream>
#define base 1024*1024+10
using namespace std;
struct node{ 
     int v;
     int lson,rson;    
}a[base];
int tag,n,m;
int f[base],b[base];
int sub=1;
void dfs(int k){
    if(a[k].lson<=m) dfs(a[k].lson);
    if(a[k].rson<=m){sub++;  dfs(a[k].rson); }
    f[tag++]=a[k].v-sub;     
}
int list(){
    int len=1,p,r,mid;    
    b[0]=-10; b[1]=f[1];
    for(int i=2;i<=m;i++){
         p=0; r=len;
         while(p<=r){
              int mid=(p+r)/2;
              if(b[mid]<=f[i]) p=mid+1;
              else r=mid-1;            
         }        
         b[p]=f[i];
         if(p>len) len=len+1;
    }
    return len;
}
int main(){
    scanf("%d",&n);
    tag=1; m=1;   
    while(scanf("%d",&a[m].v)!=EOF && a[m].v!=-1){
       a[m].lson=m*2; 
       a[m].rson=m*2+1; 
       m++;
    }  
    m--;                           
    dfs(1);
    printf("%d\n",m-list()); 
    system("pause");
    return 0;
}
