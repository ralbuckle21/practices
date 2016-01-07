#include<iostream>
using namespace std;
struct node{
    int v;
    int index;   
}a[100000];
int n,m;
void read(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
       scanf("%d",&a[i].v);
       a[i].index=i+1;
    }     
}
int cmp(const void *c,const void *b){
    return (*(node *)c).v-(*(node *)b).v;    
}
void solve(){
    int x,y,k,s;
    qsort(a,n,sizeof(a[0]),cmp);
    for(int i=0;i<m;i++){
       scanf("%d%d%d",&x,&y,&k);
       s=0;
       for(int j=0;j<n;j++){
            if(a[j].index>=x && a[j].index<=y) s++;
            if(s==k){ printf("%d\n",a[j].v); break; }           
       }
    }  
}
int main(){
    read();
    solve();
    system("pause");
    return 0;
}
