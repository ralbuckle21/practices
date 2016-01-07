#include<iostream>
using namespace std;
int n,m,k;
bool map[102][102],searchs[102];
int pre[102];
bool dfs(int data){
     for(int i=1;i<=m;i++){
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
int main()
{
     int x,y,i;    
     while(true){
         scanf("%d",&n); 
         if(n==0) break;
         memset(pre,0,sizeof(pre));
         memset(map,0,sizeof(map));
         scanf("%d%d",&m,&k);
         while(k--){
             scanf("%d%d%d",&i,&x,&y);
             map[x][y]=true;
         }
         int num=0;
         for(int i=1;i<=n;i++){ 
             memset(searchs,0,sizeof(searchs));
             if(dfs(i)) num++;
         }
         printf("%d\n",num);
     }     
     system("pause");
     return 0;
}
