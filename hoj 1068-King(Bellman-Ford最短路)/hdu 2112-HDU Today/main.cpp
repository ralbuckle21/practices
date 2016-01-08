//http://blog.csdn.net/tsaid/article/details/6853736
#include <iostream>     
using namespace std;  
#define MAX 110   
#define INF 99999999
typedef struct Edge
{  
    int u,v;
    int weight; 
}Edge;  
Edge edge[MAX]; 
int  dist[MAX];  
int nn,en,ss;  
void relax(int u, int v, int weight)  
{  
    if(dist[v] < dist[u] + weight)  
        dist[v] = dist[u] + weight;   
}  
bool Bellman_Ford()  
{  
    int i,j;
    for(i=0;i<=nn;++i)  
        for(j=0; j<en;++j)  
            relax(edge[j].u,edge[j].v,edge[j].weight);  
        bool flag=1;
        for(i=0; i<en; ++i)  
            if(dist[edge[i].v] < dist[edge[i].u] + edge[i].weight)  
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
    while(scanf("%d",&nn)&&nn!=0)
    {
        scanf("%d",&en);
        for(i=0;i<en;++i)
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
        for(i=0;i<=nn;++i)
            dist[i]=-INF;
        if(Bellman_Ford())  printf("lamentable kingdom\n");  
        else  printf("successful conspiracy\n");
    } 
}