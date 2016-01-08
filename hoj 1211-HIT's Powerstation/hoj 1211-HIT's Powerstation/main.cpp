#include <cstdio>
#include<cstring> 
#define MAX 105
#define INF 9999999
int N;
int dis[MAX][MAX];
void floyd_warshall()
{
	for(int k=0;k<N;k++){
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				if(dis[i][j]>dis[i][k]+dis[k][j]){
					dis[i][j]=dis[i][k]+dis[k][j];
					dis[j][i]=dis[i][j];
				}
			}
		}
	}
} 
int main()
{ 
	int ca,M,x,y,w;
	scanf("%d",&ca);
	while(ca--)
	{
		scanf("%d%d",&N,&M);
		for(int i=0;i<N;i++){
			for(int j=0;j<=N;j++){
				if(i==j) dis[i][j]=0;
				else dis[i][j]=INF;
			}
		}
		for(int i=0;i<M;i++) { 
			scanf("%d%d%d",&x,&y,&w); 
			dis[x][y]=w;
			dis[y][x]=w;
		}
		floyd_warshall();
		int max; 
		int tmp=INF; 
		int v; 
		for(int i=0;i<N;i++){ 
			max=0;
			for(int j=0;j<N;j++){
				max+=dis[i][j]; 
			} 
			if(tmp>max){ 
				tmp=max; 
				v=i; 
			}
		} 
		printf("%d %d\n",v,tmp);
	} 
}

/*#include <cstdio>
#include<cstring> 
#define MAX 103
#define INF 99999999 
int N; 
int map[MAX][MAX];
int dis[MAX][MAX]; 
void floyd_warshall(){ 
	int i,j,k; 
	for(k=0;k<N;k++) { 
		for(i=0;i<N;i++) 
			for(j=0;j<N;j++) { 
				if(dis[i][j]>dis[i][k]+dis[k][j]) 
					dis[i][j]=dis[i][k]+dis[k][j]; 
			}
	} 
} 
int main()
{ 
	int ca,M,i,j,x,y,w; 
	scanf("%d",&ca);
	while(ca--) { 
		scanf("%d%d",&N,&M);
		for(i=0;i<N;i++) { 
			for(j=0;j<=N;j++) i==j?dis[i][j]=0:dis[i][j]=INF; 
		} 
		for(i=0;i<M;i++) { 
			scanf("%d%d%d",&x,&y,&w);
			dis[x][y]=w; 
			dis[y][x]=w; 
		}
		floyd_warshall();
		int max; 
		int tmp=INF; 
		int v; 
		for(i=0;i<N;i++) {
			max=0; 
			for(j=0;j<N;j++) { 
				max+=dis[i][j]; 
			} 
			if(tmp>max) { 
				tmp=max; v=i;
			} 
		}
		printf("%d %d\n",v,tmp); 
	} 
	return 0;
}*/