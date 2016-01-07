#include<iostream>
#define MAXS 10000000
using namespace std;
int n,m,t;
int dist[300][300];
int maxdist(int a,int b){
     return a>b?a:b;   
}
void shortpath(){
     for(int u=0;u<n;u++)
        for(int v=0;v<n;v++)
            for(int w=0;w<n;w++){
                int h=maxdist(dist[v][u],dist[u][w]);
                if(dist[v][w]>h)
                     dist[v][w]=h;
            }
}
void input(){
    int s,d,v;
    scanf("%d %d %d",&n,&m,&t);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
             dist[i][j]=MAXS;
    for(int i=0;i<n;i++) dist[i][i]=0;
    for(int i=0;i<m;i++){
         scanf("%d %d %d",&s,&d,&v);
         dist[s-1][d-1]=v;    
    }  
    shortpath();
    while(t--){
        scanf("%d %d",&s,&d);
        if(dist[s-1][d-1]!=MAXS)  printf("%d\n",dist[s-1][d-1]);
        else printf("-1\n");           
    }
}
int main()
{
    input();
    system("pause");
    return 0;
}
