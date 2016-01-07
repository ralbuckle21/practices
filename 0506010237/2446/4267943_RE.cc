#include<iostream>
using namespace std;
int n,m,k,num;
bool flag[1000];
bool searchs[1000];
int pre[1000];
bool dfs(int data){
     int x=data-m;
     if(x>=1 && !flag[x] && !searchs[x]){
           searchs[x]=true;
           if(pre[x]==0 || dfs(pre[x])){
                 pre[x]=data;
                 return true;             
           }        
     }
     x=data+1;
     if(x<=num && !flag[x] && !searchs[x]){
           searchs[x]=true;
           if(pre[x]==0 || dfs(pre[x])){
                 pre[x]=data;
                 return true;             
           }         
     }
     x=data+m;
     if(x<=num && !flag[x] && !searchs[x]){
           searchs[x]=true;
           if(pre[x]==0 || dfs(pre[x])){
                 pre[x]=data;
                 return true;             
           }         
     }
     x=data-1;
     if(x>=1 && !flag[x] && !searchs[x]){
           searchs[x]=true;
           if(pre[x]==0 || dfs(pre[x])){
                 pre[x]=data;
                 return true;             
           }         
     }
     return false;
} 
int main(){
    int x,y,w;
    scanf("%d%d%d",&n,&m,&k);
    memset(pre,0,sizeof(pre));
    memset(flag,0,sizeof(flag));
    while(k--){
        scanf("%d%d",&x,&y);
        flag[(x-1)*m+y]=true;
    }
    num=n*m;
    bool ok=true;
    for(int i=1;i<=num;i++){ 
        memset(searchs,0,sizeof(searchs));
        if(!flag[i] && !dfs(i)){ ok=false; break; }
    }
    if(ok) printf("YES\n");
    else printf("NO\n");
    system("pause");
    return 0;
}
