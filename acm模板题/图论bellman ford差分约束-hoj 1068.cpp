//http://blog.csdn.net/tsaid/article/details/6853736
#include <iostream>     
using namespace std;  
#define MAX 110   

typedef struct Edge//边
{  
    int u, v;// 起点，终点   
    int weight;// 边的权值   
}Edge;  
Edge edge[MAX];// 保存边的值   
int  dist[MAX];// 结点到源点最小距离   
int nodenum, edgenum, source;// 结点数，边数，源点   
//松弛计算   
void relax(int u, int v, int weight)  
{  
    if(dist[v] < dist[u] + weight)  
        dist[v] = dist[u] + weight;//如果source到v的距离大于source到u到v的距离，更新之   
}  

bool Bellman_Ford()  
{  
    int i,j;
    for(i=0;i<=nodenum;++i)  
        for(j=0; j<edgenum;++j)  
            relax(edge[j].u,edge[j].v,edge[j].weight);  
    bool flag=1;
    for(i=0; i<edgenum; ++i)
        if(dist[edge[i].v]< dist[edge[i].u] + edge[i].weight) 
		{  
            flag = 0;  
            break;  
		}  
    return flag;  
}  

int main()  
{     
    int u,v,d,i;  
    char str[5];  
    while(scanf("%d",&nodenum)&&nodenum)  
    {  
        scanf("%d",&edgenum);  
        for(i=0;i<edgenum;++i)  
        {  
            scanf("%d %d %s %d",&u,&v,str,&d);  
            if(str[0]=='g')  
            {  
                edge[i].u=u;  
                edge[i].v=u+v+1;  
                edge[i].weight=d+1;  
            }  
            else  
            {  
                edge[i].u=u+v+1;  
                edge[i].v=u;  
                edge[i].weight=1-d;  
            }  
        }  
        for(i=0;i<=nodenum;++i)  
            dist[i]=-100000000;  
        if(Bellman_Ford())  
            printf("lamentable kingdom\n");  
        else  
            printf("successful conspiracy\n");  
    } 
}