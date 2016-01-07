#include<iostream>
using namespace std;
int degree[210];
int c[210][210];
bool visit[210][210];
int path[210];
int n,m,t;
void topsort(){
     bool flag;
     int i,k=n;
     for(int k=1;k<=n;k++){
          flag=false;
          i=1;
          while(i<=n && degree[i]!=0) i++;
          if(i>n) break;
          degree[i]=-1; 
          path[k]=i; flag=true;
          for(int x=1;x<=c[i][0];x++) degree[c[i][x]]--;
     }    
     if(!flag) printf("-1\n");
     else{
          printf("%d",path[1]);
         for(int j=2;j<=n;j++) printf(" %d",path[j]);
         printf("\n");     
     } 
}
int main(){
    int x,y;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        memset(degree,0,sizeof(degree));
        memset(c,0,sizeof(c));
        memset(visit,0,sizeof(visit));
        for(int i=1;i<=m;i++){
               scanf("%d%d",&x,&y);
               if(!visit[x][y]){
                    visit[x][y]=true;
                    degree[y]++;
                    c[x][++c[x][0]]=y;                 
               }  
        }       
        topsort();
    }
    system("pause");
    return 0;
}
