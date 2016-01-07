//http://blog.csdn.net/tsaid/article/details/6853736
#include <iostream>     
using namespace std;  
#define MAX 110   

typedef struct Edge//��
{  
    int u, v;// ��㣬�յ�   
    int weight;// �ߵ�Ȩֵ   
}Edge;  
Edge edge[MAX];// ����ߵ�ֵ   
int  dist[MAX];// ��㵽Դ����С����   
int nodenum, edgenum, source;// �������������Դ��   
//�ɳڼ���   
void relax(int u, int v, int weight)  
{  
    if(dist[v] < dist[u] + weight)  
        dist[v] = dist[u] + weight;//���source��v�ľ������source��u��v�ľ��룬����֮   
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