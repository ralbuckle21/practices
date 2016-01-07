#include<iostream>
#define maxs INT_MAX 
using namespace std;
struct{
    int s;//起点
	int d;//终点
	int w;//权值
}edge[2600];
int n,e,t,k;
bool bellman(){
     int dist[1000];
     for(int x=0;x<n;x++){
	     for(int i=0;i<n;i++) dist[i]=maxs/2;
	     dist[x]=0;
	     for(int i=1;i<n;i++){//因为最多n-1边做为跳板
		     for(int j=0;j<e;j++)
			     if(dist[edge[j].s]+edge[j].w<dist[edge[j].d])
				     dist[edge[j].d]=dist[edge[j].s]+edge[j].w;
	     }
         for(int j=0;j<e;j++)//存在负圈,更新就会存在相互减少每次松弛后d[u]+w[u,v]<d[v]
		     if(dist[edge[j].s]+edge[j].w<dist[edge[j].d]) return false;
      }
	  return true;
}
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d %d %d",&n,&e,&k);
        e=e+k;
   	    for(int i=k;i<e;i++) scanf("%d %d %d",&edge[i].s,&edge[i].d,&edge[i].w);
   	    for(int i=0;i<k;i++){
            scanf("%d %d %d",&edge[i].s,&edge[i].d,&edge[i].w);
            edge[i].w = -edge[i].w;
        } 
 	    if(bellman()) printf("NO\n");
 	    else printf("YES\n");
    }
    system("pause");
	return 0;
}

