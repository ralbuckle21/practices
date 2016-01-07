#include<iostream>
using namespace std;
int t,n,m;
bool visit[10010];
int pre[10010];
int map[10010][2];
bool dfs(int k){
    if(pre[map[k][0]]==0){
          pre[map[k][0]]=k;
          return true;
    }                      
    else if(pre[map[k][1]]==0){
          pre[map[k][1]]=k;
          return true;
    }
    else{
          if(!visit[map[k][0]]){//没有被抢占过 
                visit[map[k][0]]=true;
                if(dfs(pre[map[k][0]])){
                      pre[map[k][0]]=k;
                      return true;                        
                }                      
          }
          return false;           
    }
}
int main(){
    int i;
    scanf("%d",&t);
    while(t--){
         scanf("%d%d",&n,&m);
         memset(pre,0,sizeof(pre));      
         for(i=1;i<=n;i++)
           scanf("%d%d",&map[i][0],&map[i][1]);           
         for(i=1;i<=n;i++){
               memset(visit,0,sizeof(visit));
               if(!dfs(i)){
                      cout<<"rehash necessary"<<endl;    
                      break;  
               }        
         }
         if(i>n){
                cout<<"successful hashing"<<endl;
         }
    }
    system("pause");
    return 0;
}
