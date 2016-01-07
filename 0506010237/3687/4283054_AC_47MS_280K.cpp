#include<iostream>
using namespace std;
int degree[210];
bool visit[210][210];
int path[210];
int n,m,t;
void topsort(){
     for(int k=n;k>=1;k--){
          int i=n;
          while(i>=1 && degree[i]!=0) i--;
          if(i<1){ printf("-1\n"); return; }
          degree[i]=-1; 
          path[i]=k; 
          for(int x=1;x<=n;x++) if(visit[x][i]) degree[x]--;
     }    
     for(int j=1;j<=n;j++) printf("%d ",path[j]);
     printf("\n");     
}
int main(){
    int x,y;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        memset(degree,0,sizeof(degree));
        memset(visit,0,sizeof(visit));
        for(int i=1;i<=m;i++){
               scanf("%d%d",&x,&y);
               if(!visit[x][y]){
                    visit[x][y]=true;
                    degree[x]++;              
               }  
        }       
        topsort();
    }
    system("pause");
    return 0;
}


