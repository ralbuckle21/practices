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
          i=n;
          while(i>=1 && degree[i]!=0) i--;
          if(i<1) break;
          degree[i]=-1; 
          path[k]=i; flag=true;
          for(int x=1;x<=c[i][0];x++) degree[c[i][x]]--;
     }    
     if(!flag) printf("-1\n");
     else{
         for(int j=n;j>=1;j--) printf("%d ",path[j]);
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
               if(!visit[y][x]){
                    visit[y][x]=true;
                    degree[x]++;
                    c[y][++c[y][0]]=x;                 
               }  
        }       
        topsort();
    }
    system("pause");
    return 0;
}

