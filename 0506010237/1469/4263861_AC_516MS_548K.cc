#include<iostream>
using namespace std;
int map[110][310];
int pre[310];
bool visit[310];
int n,m,t;
void init(){
    memset(map,0,sizeof(map));
    memset(pre,0,sizeof(pre));     
}
bool dfs(int k){
    for(int i=1;i<=map[k][0];i++){
         if(!visit[map[k][i]]){
              visit[map[k][i]]=true;
              if(pre[map[k][i]]==0 || dfs(pre[map[k][i]])){
                   pre[map[k][i]]=k;
                   return true;                     
              }                       
         }        
    } 
    return false;    
}
int main(){
    int k,x;
    scanf("%d",&t);
    while(t--){
        init();
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++){
             scanf("%d",&k);
             while(k--){
                   scanf("%d",&x);
                   map[i][++map[i][0]]=x;           
             }        
        } 
        int num=0;
        for(int i=1;i<=n;i++){
             memset(visit,0,sizeof(visit));
             if(dfs(i)) num++;      
             else break;  
        }          
        if(num==n) printf("YES\n");
        else printf("NO\n");
    }
    system("pause");
    return 0;
}
