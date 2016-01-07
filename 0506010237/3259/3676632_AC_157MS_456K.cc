#include<iostream>
#define maxs INT_MAX 
using namespace std;
struct{
    int s;//起点
	int d;//终点
	int w;//权值
}edge[20000];
int n,e,t,k,len;
bool bellman(){
     int dist[1001];      
	     for(int i=0;i<n;i++) dist[i]=maxs/2;
	     dist[0]=0;
	     for(int i=1;i<n;i++){//因为最多n-1边做为跳板
		     for(int j=0;j<len;j++)
			     if(dist[edge[j].s]+edge[j].w<dist[edge[j].d])
				     dist[edge[j].d]=dist[edge[j].s]+edge[j].w;
	     }
         for(int j=0;j<len;j++)//存在负圈,更新就会存在相互减少每次松弛后d[u]+w[u,v]<d[v]
		     if(dist[edge[j].s]+edge[j].w<dist[edge[j].d]) return false;
 
	  return true;
}
int main()
{
    //freopen("book.txt","r",stdin);
    //freopen("bb.txt","w",stdout);    
    scanf("%d",&t);
    while(t--){
        len=0;
        scanf("%d %d %d",&n,&e,&k);
   	    for(int i=0;i<e;i++){
               scanf("%d %d %d",&edge[len].s,&edge[len].d,&edge[len].w);
               edge[len].s--; edge[len].d--; len++;
               edge[len].s=edge[len-1].d; edge[len].d=edge[len-1].s; 
               edge[len].w=edge[len-1].w; len++;
        }
   	    for(int i=0;i<k;i++){
            scanf("%d %d %d",&edge[len].s,&edge[len].d,&edge[len].w);
            edge[len].s--; edge[len].d--;
            edge[len].w = -edge[len].w; len++;
        } 
 	    if(bellman()) printf("NO\n");
 	    else printf("YES\n");
    }
    system("pause");
	return 0;
}

