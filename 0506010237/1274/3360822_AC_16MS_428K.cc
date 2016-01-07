/*  二分图指的是这样一种图：其所有的顶点分成两个集合M和N，其中M或N中任意两个
    在同一集合中的点都不相连。二分图匹配是指求出一组边，其中的顶点分别在两个
    集合中，并且任意两条边都没有相同的顶点，这组边叫做二分图的匹配，而所能得
    到的最大的边的个数，叫做最大匹配。 
    最大二分图匹配 (匈牙利算法) 实现 ：从第一个顶点起每次去找一条增广路若果成功
    就增加一条匹配边 
*/ 
#include<iostream>
using namespace std;
int n,m,k,temp;
bool map[202][201],searchs[202];
int pre[202];
bool dfs(int data){
     int i,temp;
     for(int i=1;i<=m;i++){
         if(map[data][i] && !searchs[i]){
              searchs[i]=1;
              temp=pre[i];
              pre[i]=data;
              if(temp==0 || dfs(temp)) return true;//这次匹配成功
         }
     }
     return false;//找不到增广路 
} 
int main()
{
    while(scanf("%d %d",&n,&m)!=EOF){
         memset(map,0,sizeof(map));
         memset(pre,0,sizeof(pre));
         for(int i=1;i<=n;i++){
             scanf("%d",&k);
             for(int j=1;j<=k;j++){
                  scanf("%d",&temp);
                  map[i][temp]=true;
             }
         }
         int num=0;
         for(int i=1;i<=n;i++){ //从第一个顶点起每次去找一条增广路若果成功就增加一条匹配边 
                 memset(searchs,0,sizeof(searchs));
                 if(dfs(i)) num++;
         }
         printf("%d\n",num);
    }     
    system("pause");
    return 0;
}
