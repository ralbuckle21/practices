#include<iostream>
using namespace std;
int n,m,k;
bool map[502][502],searchs[502];
int pre[502];
bool dfs(int data){
     for(int i=1;i<=m;i++){
         if(map[data][i] && !searchs[i]){
              searchs[i]=true;
              if(pre[i]==0 || dfs(pre[i])){
                   pre[i]=data;
                   return true;//这次匹配成功
              }
         }
     }
     return false;//找不到增广路 
} 
int main()
{
         int a,b;
         memset(map,0,sizeof(map));
         memset(pre,0,sizeof(pre));
         scanf("%d %d",&n,&k);
         m=n;
         for(int i=1;i<=k;i++){
              scanf("%d %d",&a,&b);
              map[a][b]=true;
         }
         int num=0;
         for(int i=1;i<=n;i++){ //从第一个顶点起每次去找一条增广路若果成功就增加一条匹配边 
                 memset(searchs,0,sizeof(searchs));
                 if(dfs(i)) num++;
         }
         printf("%d\n",num);    
    system("pause");
    return 0;
}
