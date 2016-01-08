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
/*BFS+ѹ���ر귨*/
//��Դ������������
//Memory  Time 
//384K    860MS  

#include<iostream>
using namespace std;

const int inf=10001;

int n;  //�ܽڵ���
int np; //��վ��
int nc; //�û���
int line;  //��·��
int cap[102][102];  //��(u,v)������
int flow[102][102];  //��(u,v)������
bool vist[102];   //��ǵ�v�Ƿ��ѱ��
int s,t;  //����Դ��������

class info   //��ǰ��v�ı����Ϣ
{
public:
	int pre;  //��ǰ��v��ǰ��u
	int lv;  //l(v)
	int nei[101];  //��ǰ���ֱ��ָ����ھӽ��
	int pn;  //�ھӽ���ָ��
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
		flow[ node[x].pre ][x] += node[t].lv;  //�Ľ�����·
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

	while(head<=tail-1)  //ע�⣬������Ҳ�Ҳ�������·�Ľ�������
	{
		int x=queue[head];
		int y;
		for(int i=0;i<node[x].pn;i++)
		{
			y=node[x].nei[i];
			if(!vist[y] && flow[x][y]<cap[x][y])   //������Ŀ��Ҫ���� δ��� & �Ǳ��ͻ�
			{
				queue[tail++]=y;

				vist[y]=true;
				node[y].pre=x;
				node[y].lv=min( node[x].lv , cap[x][y]-flow[x][y] );
			}
			if(vist[t])  //�������㱻���
				break;
		}
		if(!vist[t])
			head++;
		else
			return true;  //������һ������·
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
				continue;   //����Ҫ��
			cap[u][v]=z;
			flow[u][v]=0;   //ÿ���ߵ���������ʼ��Ϊ0
			node[u].nei[ node[u].pn++ ]=v;
		}
		for(i=1;i<=np;i++)
		{
			cin>>temp>>v>>temp>>z;
			cap[s][v]=z;     //��������Դ��ָ�����е�վ
			flow[s][v]=0;
			node[s].nei[ node[s].pn++ ]=v;
		}
		for(i=1;i<=nc;i++)
		{
			cin>>temp>>u>>temp>>z;
			cap[u][t]=z;     //���������㣬�������û�ָ��
			flow[u][t]=0;
			node[u].nei[ node[u].pn++ ]=t;
		}

		/*��ŷ��������*/

		while(true)
		{
			if(bfs())  //������ѵ�������·
				back();  //�ӳ����㿪ʼ����,�Ľ�����·
			else
			{
				int max=0;        //��������
				for(i=0;i<node[s].pn;i++)
					max+=flow[s][ node[s].nei[i] ];
				cout<<max<<endl;
				break;
			}
		}
	}
	return 0;
}
