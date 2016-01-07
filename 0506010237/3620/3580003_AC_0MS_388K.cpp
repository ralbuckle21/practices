#include<iostream>
using namespace std;
bool visit[101][101]={false};
int n,m,k;
int find(int x,int y){
    int v=1;
    visit[x][y]=false;
    if(x>1 && visit[x-1][y]) v+=find(x-1,y);
    if(y>1 && visit[x][y-1]) v+=find(x,y-1);
    if(x<n && visit[x+1][y]) v+=find(x+1,y);
    if(y<m && visit[x][y+1]) v+=find(x,y+1);
    return v;     
}
int main()
{
    int x,y,mins=0;
    scanf("%d %d %d",&n,&m,&k);
    while(k--){
         scanf("%d %d",&x,&y);
         visit[x][y]=true;      
    }
    for(int i=1;i<=n;i++)
       for(int j=1;j<=m;j++){
            if(visit[i][j]){ 
                int v=find(i,j);
                if(v>mins)  mins=v;      
            }
       }
    printf("%d\n",mins);
    system("pause");
    return 0;
}
