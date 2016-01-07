#include<iostream>
using namespace std;
const int maxs=2000;
int f[4004];
int t,n,m,cs=1;
void init(){
    for(int i=1;i<=4000;i++) f[i]=i;    
}
int find(int x){
    int r=x;
    while(r!=f[r]) r=f[r]; //找到根结点
    while(x!=r){  //路径压缩 
         int temp=f[x];
         f[x]=r;
         x=temp;            
    }   
    return r;
}
void unions(int x,int y){
    x=find(x),y=find(y);
    if(x>y) f[y]=x;
    else if(x<y) f[x]=y;    
}
int main(){
    int x,y,i;
    scanf("%d",&t);
    while(t--){
         init();           
         scanf("%d%d",&n,&m);
         for(i=1;i<=m;i++){
              scanf("%d%d",&x,&y);
              if(find(x)==find(y)) break;
              unions(x,y+maxs);
              unions(x+maxs,y);        
              //cout<<find(x)<<" * "<<find(y)<<endl;
         }
         for(int j=i+1;j<=m;j++) scanf("%d%d",&x,&y);
         printf("Scenario #%d:\n",cs++);
         if(i<=m) printf("Suspicious bugs found!\n");
         else printf("No suspicious bugs found!\n");
    }
    system("pause");
    return 0;
}
