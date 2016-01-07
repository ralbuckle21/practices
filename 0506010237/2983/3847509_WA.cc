#include<iostream>
using namespace std;
const int maxs=INT_MAX;
struct{
    int s;
	int d;
	int w;
}edge[100001];
int dist[400001];
int n,m,e;
bool bellman(){
	 for(int i=0;i<=n;i++) dist[i]=0;
	 for(int i=1;i<n;i++){
		 for(int j=0;j<e;j++)
			 if(dist[edge[j].s]+edge[j].w<dist[edge[j].d])
				 dist[edge[j].d]=dist[edge[j].s]+edge[j].w;
	 }
     for(int j=0;j<e;j++)
		  if(dist[edge[j].s]+dist[edge[j].w]<dist[edge[j].d]) return false;
	 return true;
}
int main()
{
    char c; int x,y,w;
    while(scanf("%d %d",&n,&m)!=EOF){
          e=0;
          while(m--){
              scanf("%c",&c);
              while(c==' ' || c=='\n') scanf("%c",&c);
              if(c=='P'){
                    scanf("%d %d %d",&x,&y,&w);
                    edge[e].s=y; edge[e].d=x; edge[e].w=w; e++;
                    edge[e].s=x; edge[e].d=y; edge[e].w=-w; e++;     
              }
              else{
                   scanf("%d%d",&x,&y);
                   edge[e].s=x; edge[e].d=y; edge[e].w=-1;e++;     
              }
          }
          if(bellman()) printf("Reliable\n");
          else printf("Unreliable\n");
    }
    system("pause");
	return 0;
}
