#include<iostream>
using namespace std;
const int base=100000;
bool flag[1000];
struct{
    int v;   
    int pre1;
    int pre2;
}q[base];
int rear,front,len;
int r[10000];
int n;
void dfs(int x){
     if(x==-1) return;
     r[len++]=q[x].v;
     dfs(q[x].pre1);
     dfs(q[x].pre2);     
}
int cmp(const void *a,const void *b){
    return *(int *)a-*(int *)b;   
}
void getr(){
    int j=1;
    qsort(r,len,sizeof(r[0]),cmp);
    for(int i=1;i<len;i++) if(r[i]!=r[i-1]) r[j++]=r[i];
    for(int i=0;i<j;i++) printf("%d ",r[i]); printf("\n");
}
void bfs(){
    int v;
    front=-1,rear=0;
    q[rear].v=1; q[rear].pre1=-1; q[rear].pre2=-1; flag[1]=true;
    if(n>1)
    while(front<rear){
         front++;  
         for(int i=front;i>=0;i--){
             v=q[i].v+q[front].v;
             if(v>n || flag[v]) continue; 
             flag[v]=true;
             rear++;   q[rear].v=v; q[rear].pre1=i; q[rear].pre2=front;
             if(v==n) return;   
         }       
    }     
}
void solve(){
    memset(flag,0,sizeof(flag));
    bfs();     
    len=0;
    dfs(rear);
    getr();
}
int main(){
    while(scanf("%d",&n)!=EOF && n!=0) solve();
    system("pause");
    return 0;
}
