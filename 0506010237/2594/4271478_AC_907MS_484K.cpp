/*   最少路径覆盖数 = 顶点数 - 最大匹配数 
     证明：匹配，每条简单的路径除了最后一个顶点以外都有后继，匹配数就是非路径结尾的顶点数 
*/ 
#include<iostream>
using namespace std;
int n,m;
bool map[502][502],searchs[502];
int pre[502];
bool dfs(int data){
     for(int i=1;i<=n;i++){
         if(map[data][i] && !searchs[i]){
              searchs[i]=true;
              if(pre[i]==0 || dfs(pre[i])){
                  pre[i]=data;
                  return true;
              }
          }
     }
     return false;
} 
void cup(){
     for(int q=1;q<=n;q++)
        for(int p=1;p<=n;p++)
           for(int r=1;r<=n;r++)
               map[p][r] |= map[p][q] & map[q][r];        
}
int main(){
    int x,y;
    while(true){
         scanf("%d %d",&n,&m);
         if(n==0 && m==0) break;
         memset(map,0,sizeof(map));
         memset(pre,0,sizeof(pre));
         for(int i=1;i<=m;i++){
              scanf("%d%d",&x,&y);
              map[x][y]=true;
         }
         cup();
         int num=0;
         for(int i=1;i<=n;i++){ 
                 memset(searchs,0,sizeof(searchs));
                 if(dfs(i)) num++;
         }
         printf("%d\n",n-num);
    }     
    system("pause");
    return 0;
}
