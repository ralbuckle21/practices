#include<iostream>
using namespace std;
int visit[110],low[110];
int n,result;
int map[110][110];
bool cute[110];
int tot[110];
void init(){
     memset(visit,0,sizeof(visit));
     memset(cute,0,sizeof(cute));
     memset(tot,0,sizeof(tot));
     memset(map,0,sizeof(map));
     result=0;
}
void dfs(int k,int sign){
     visit[k]=sign;
     int mins=sign;
     for(int i=1;i<=map[k][0];i++){
           if(visit[map[k][i]]==0){
               tot[k]++;
               dfs(map[k][i],sign+1);
               if(low[map[k][i]]<mins) mins=low[map[k][i]];
               if(k!=1 && low[map[k][i]]>=visit[k]) cute[k]=true;
               if(k==1 && tot[k]>1) cute[k]=true;
           }
           else if(visit[map[k][i]]<mins) mins=visit[map[k][i]];              
     }  
     low[k]=mins;   
}
void solve(){
    char c;
    int x,y;
    init();
    while(scanf("%d",&x)!=EOF && x!=0){
         while(c=getchar()!='\n'){
              scanf("%d",&y);
              map[x][++map[x][0]]=y;
              map[y][++map[y][0]]=x;                         
         }
    } 
    dfs(1,1);
    for(int i=1;i<=n;i++) if(cute[i]) result++;
    printf("%d\n",result);
}
int main(){
    while(scanf("%d",&n)!=EOF && n!=0) solve();
    system("pause");
    return 0;
}
