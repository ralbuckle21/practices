#include<iostream>
using namespace std;
bool map[110][110];
int n,m;
bool match(int a,int b){
    for(int i=1;i<=m;i++) if(map[a][i]!=map[b][i]) return false;
    return true;     
}
void solve(){
    int sum=1,i,j;
    for(i=2;i<=n;i++){
        for(j=1;j<i;j++){
             if(match(i,j)) break;        
        }        
        if(j==i) sum++;
    }   
    printf("%d\n",sum);  
}
int main(){
    int x,y;
    memset(map,0,sizeof(map));
    scanf("%d%d",&n,&m);
    while(scanf("%d%d",&x,&y)!=EOF) map[x][y]=true;
    solve();
    system("pause");
    return 0;
}
