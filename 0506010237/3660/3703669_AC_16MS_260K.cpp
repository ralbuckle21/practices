#include<iostream>
using namespace std;
int n,m;
struct{
    int w;
    int f;      
}rank[110];
int visit[110][110];
int main()
{
     int a,b;
     memset(rank,0,sizeof(rank));
     memset(visit,0,sizeof(visit));
     scanf("%d %d",&n,&m);
     while(m--){
         scanf("%d %d",&a,&b);
         if(visit[a][b]==0){
              visit[a][b]=2; visit[b][a]=1;
              rank[a].w++; rank[b].f++;
              for(int j=1;j<=n;j++){
                    if(visit[j][b]==1 && visit[a][j]==0){
                           visit[a][j]=2; visit[j][a]=1;
                           rank[a].w++; rank[j].f++;                    
                    }        
              } 
              for(int i=1;i<=n;i++){
                  if(visit[i][a]==2){
                        if(visit[i][b]==0 && i!=b){
                              visit[i][b]=2; visit[b][i]=1;
                              rank[i].w++; rank[b].f++;             
                              for(int j=1;j<=n;j++){
                                   if(visit[j][b]==1 && visit[i][j]==0){
                                       visit[i][j]=2; visit[j][i]=1;
                                       rank[i].w++; rank[j].f++;                    
                                   }        
                              }  
                        }      
                  }
             }
         }  
         /*for(int i=1;i<=n;i++) cout<<rank[i].w<<","<<rank[i].f<<"  ";
         cout<<endl; */         
     }
     int sum=0;
     for(int i=1;i<=n;i++) if(rank[i].w+rank[i].f==n-1) sum++;
     printf("%d\n",sum);
     system("pause");
     return 0;
}
