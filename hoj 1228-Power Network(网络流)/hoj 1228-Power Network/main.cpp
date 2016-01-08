/*#include<iostream>
using namespace std;
int n,m,np,nc;
int cost[110][110];
int net(){
     bool visit[110];
     int u,dist[110],path[110];
     for(int i=0;i<=n;i++){
        visit[i]=0;
        dist[i]=cost[0][i]; 
        path[i]=0;      
     }    
     visit[0]=1;path[0]=-1;
     for(int i=1;i<=n;i++){
        int max=0;
        for(int j=1;j<=n;j++){
            if(visit[j]==0 && dist[j]>max){   
               max=dist[j];
               u=j;     
            }
        }
        if(max==0) return 0;
        visit[u]=1;
        if(u==n){
            int w1=path[n],w2=n;
            while(w1!=-1){
               cost[w1][w2]=cost[w1][w2]-dist[n];  
               if(w1!=0 && w2!=n) cost[w2][w1]=cost[w2][w1]+dist[n];     
               w2=w1;w1=path[w2];
            }   
            return dist[n];
        }  
        for(int w=1;w<=n;w++){
            int minpath=dist[u]<cost[u][w]?dist[u]:cost[u][w];
            if(visit[w]==0 && dist[w]<minpath){
                   dist[w]=minpath;
                   path[w]=u;
             }        
        }
     }
}
void total(){
    int w1,w2,pow,totals=0;
    char c;
    memset(cost,0,sizeof(cost));
    for(int i=0;i<m;i++){
         c=getchar();
         while(c!='(') c=getchar();
         scanf("%d",&w1);getchar();
         scanf("%d",&w2);getchar();
         scanf("%d",&pow);
         cost[w1+1][w2+1]=pow;       
    }
    for(int i=0;i<np;i++){
         c=getchar();
         while(c!='(') c=getchar();
         scanf("%d",&w2);getchar();
         scanf("%d",&pow);
         cost[0][w2+1]=pow;                  
    }
    for(int i=0;i<nc;i++){
         c=getchar();
         while(c!='(') c=getchar();
         scanf("%d",&w1);getchar();
         scanf("%d",&pow);
         cost[w1+1][n]=pow;                  
    }
    if(nc!=0)
    while(true){
          int maxs=net();
          if(maxs<=0) break;
          totals=totals+maxs;           
    }
    printf("%d\n",totals);          
}
int main()
{
     while(scanf("%d %d %d %d",&n,&np,&nc,&m)!=EOF){
        n=n+1;
        total();                
     }
}
*/
/*BFS+压入重标法*/
//多源多汇最大流问题
//Memory  Time 
//384K    860MS  

#include<iostream>
using namespace std;

const int inf=10001;

int n;  //总节点数
int np; //电站数
int nc; //用户数
int line;  //线路数
int cap[102][102];  //弧(u,v)的容量
int flow[102][102];  //弧(u,v)的流量
bool vist[102];   //标记点v是否已标号
int s,t;  //超级源，超级汇

class info   //当前点v的标记信息
{
public:
	int pre;  //当前点v的前驱u
	int lv;  //l(v)
	int nei[101];  //当前结点直接指向的邻居结点
	int pn;  //邻居结点的指针
}node[102];

int min(int a,int b)
{
	return a<b?a:b;
}

void back(void)
{
	int x=t;
	while(x!=s)
	{
		flow[ node[x].pre ][x] += node[t].lv;  //改进增广路
		x=node[x].pre;

	}
	return;
}

bool bfs(void)
{
	memset(vist,false,sizeof(vist));
	node[s].pre=-1;
	node[s].lv=inf;
	vist[s]=true;

	int queue[102];
	int head=0;
	int tail=0;
	queue[tail++]=s;

	while(head<=tail-1)  //注意，这是再也找不到增广路的结束条件
	{
		int x=queue[head];
		int y;
		for(int i=0;i<node[x].pn;i++)
		{
			y=node[x].nei[i];
			if(!vist[y] && flow[x][y]<cap[x][y])   //搜索的目标要求是 未标记 & 非饱和弧
			{
				queue[tail++]=y;

				vist[y]=true;
				node[y].pre=x;
				node[y].lv=min( node[x].lv , cap[x][y]-flow[x][y] );
			}
			if(vist[t])  //当超级汇被标记
				break;
		}
		if(!vist[t])
			head++;
		else
			return true;  //搜索到一条增广路
	}
	return false;
}

int main(int i,int j,int u,int v,int z,char temp)
{
	while(cin>>n>>np>>nc>>line)
	{
		/*Initial*/
		s=n;
		t=n+1;
		for(i=0;i<n+1;i++)
			node[i].pn=0;

		/*Input & Structure Maps*/

		for(i=1;i<=line;i++)
		{
			cin>>temp>>u>>temp>>v>>temp>>z;
			if(u==v)
				continue;   //不需要环
			cap[u][v]=z;
			flow[u][v]=0;   //每条边的流量都初始化为0
			node[u].nei[ node[u].pn++ ]=v;
		}
		for(i=1;i<=np;i++)
		{
			cin>>temp>>v>>temp>>z;
			cap[s][v]=z;     //建立超级源，指向所有电站
			flow[s][v]=0;
			node[s].nei[ node[s].pn++ ]=v;
		}
		for(i=1;i<=nc;i++)
		{
			cin>>temp>>u>>temp>>z;
			cap[u][t]=z;     //建立超级汇，被所有用户指向
			flow[u][t]=0;
			node[u].nei[ node[u].pn++ ]=t;
		}

		/*标号法找增广轨*/

		while(true)
		{
			if(bfs())  //如果能搜到到增广路
				back();  //从超级汇开始回溯,改进增广路
			else
			{
				int max=0;        //输出最大流
				for(i=0;i<node[s].pn;i++)
					max+=flow[s][ node[s].nei[i] ];
				cout<<max<<endl;
				break;
			}
		}
	}
	return 0;
}
