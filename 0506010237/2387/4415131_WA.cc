#include<iostream>
#define maxs INT_MAX
using namespace std;
struct{
    int s;//起点
	int d;//终点
	int w;//权值
}edge[10000];
int dist[1000];
int n,e;
void bellman(){
	 for(int i=0;i<=n;i++) dist[i]=maxs;
	 dist[1]=0;
	 for(int i=1;i<n;i++){//因为每次松弛时至少有一条边不需要再以其他边做为跳板
		 for(int j=0;j<e;j++)
			 if(dist[edge[j].s]!=maxs && dist[edge[j].s]+edge[j].w<dist[edge[j].d])
				 dist[edge[j].d]=dist[edge[j].s]+edge[j].w;
	 }
	 printf("%d\n",dist[n]);
}
int main()
{
    scanf("%d %d",&n,&e);
	for(int i=0;i<e;i++){
         scanf("%d %d %d",&edge[i].s,&edge[i].d,&edge[i].w);
         edge[e+i].s=edge[i].d; edge[e+i].d=edge[i].s; edge[e+i].w=edge[i].w;
    }
    e=e*2;
	bellman();
    system("pause");
	return 0;
}
