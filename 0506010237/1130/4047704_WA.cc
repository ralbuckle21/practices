#include<iostream>
using namespace std;
const int maxs=INT_MAX/100;
int map[1001][1001];
int sign[1001];
bool visit[1001];
int counts[1001];
int n,u,d;
void dfs(int k){
     int v;
     visit[k]=true;
     if(sign[k]!=maxs) return;
     for(int i=1;i<=map[k][0];i++){
          if(!visit[map[k][i]]) dfs(map[k][i]);
          v=sign[map[k][i]]+1;
          if(v<maxs) counts[k]+=counts[map[k][i]];
          if(v<sign[k]) sign[k]=v;        
     }     
     return;
}
int main(){
    int x,y;
    scanf("%d%d",&n,&d);
    for(int i=0;i<n;i++) sign[i]=maxs; sign[d]=0; counts[d]=1;
    while(scanf("%d%d",&x,&y)!=EOF) map[x][++map[x][0]]=y;          
    dfs(0); sign[d]=maxs;
    int result=maxs,v=0;
    for(int i=0;i<n;i++){
          //  cout<<counts[i]<<endl;
         if(v<counts[i] || (v==counts[i] && result>sign[i])){
              v=counts[i];
              result=sign[i];
              u=i;                   
         }
    }
    printf("Put guards in room %d.\n",u);
    system("pause");
    return 0;
}
