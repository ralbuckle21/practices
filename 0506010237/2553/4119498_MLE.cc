#include<iostream>
using namespace std;
short map[5001][5001];
int n,m;
bool flag[5001];
bool visit[5001][5001];
void dfs(int k,int x){
    flag[k]=true;
    for(int i=1;i<=map[k][0];i++){
        if(!flag[map[k][i]]){
              visit[x][map[k][i]]=true;
              dfs(map[k][i],x);                     
        }        
    }     
}
void solve(){
    for(int i=1;i<=n;i++){
         memset(flag,0,sizeof(flag));
         dfs(i,i);        
    }   
    memset(flag,0,sizeof(flag));
    for(int i=1;i<=n;i++){
         for(int j=1;j<=n;j++){
               if(i==j) continue;
               if(visit[i][j] && !visit[j][i]){
                    flag[i]=true;    
                    break;           
               }     
         }        
    }  
    for(int i=1;i<=n;i++) if(!flag[i]) printf("%d ",i);
    printf("\n");
}
int main(){
    int x,y;
  //  cout<<sizeof(map)/1024<<endl;
    while(true){
         scanf("%d",&n);
         if(n==0) break;
         scanf("%d",&m); 
         memset(map,0,sizeof(map));
         memset(visit,0,sizeof(visit));
         for(int i=1;i<=m;i++){
               scanf("%d%d",&x,&y);
               map[x][++map[x][0]]=y;        
         }           
         solve();
    }
    system("pause");
    return 0;
}
