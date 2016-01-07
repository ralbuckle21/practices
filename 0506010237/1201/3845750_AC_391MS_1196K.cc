#include<iostream>
using namespace std;
const int maxs=5000000;
struct{
    int s;
	int d;
	int w;
}edge[50001];
int e;
int st=maxs;
int ed=0;
int dist[50010];//保存从起点到i不包括i所需的点数 
int bellman(){
	 for(int i=st;i<=ed;i++) dist[i]=-maxs; dist[st]=0;
	 bool over;
	 for(int i=st;i<=ed;i++){
         over=true;
		 for(int j=0;j<e;j++) //bellman
			 if(dist[edge[j].s] != -maxs && dist[edge[j].s]+edge[j].w>dist[edge[j].d]){
				 dist[edge[j].d]=dist[edge[j].s]+edge[j].w;
				 over=false;
              }
         for(int i=st+1;i<=ed;i++)  
              if(dist[i]<dist[i-1]){ dist[i]=dist[i-1]; over=false; }
         for(int i=ed;i>st;i--)
              if(dist[i]>dist[i-1]+1){ dist[i-1]=dist[i]-1; over=false;}
         if(over) break; //剪枝 
	 }
	 return dist[ed];
}
int main()
{
    scanf("%d",&e);
	for(int i=0;i<e;i++){
          scanf("%d %d %d",&edge[i].s,&edge[i].d,&edge[i].w);
          edge[i].d++;
          if(ed<edge[i].d) ed=edge[i].d;
          if(st>edge[i].s) st=edge[i].s;
    }
	printf("%d\n",bellman());
    system("pause");
	return 0;
}

