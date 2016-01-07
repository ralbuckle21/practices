#include<iostream>
using namespace std;
const int maxs=INT_MAX/100;
int n,p;
int num[160][160];
int f[160][160];
int m[160][160];
void readdata(){
     int x,y;
     scanf("%d%d",&n,&p);
     for(int i=1;i<n;i++){
         scanf("%d%d",&x,&y);
         num[x][++num[x][0]]=y;        
     }     
}
int minv(int a,int b){ return a<b?a:b; }
void updata(int root){
     if(num[root][0]==0){ m[root][1]=0;return; }
     for(int i=0;i<=n;i++)
         for(int j=0;j<=p;j++)
             f[i][j]=maxs;
     f[1][1]=1;
     for(int j=2;j<=p;j++)
           f[1][j]=m[num[root][1]][j-1];
     for(int i=2;i<=num[root][0];i++)
         for(int j=1;j<=p;j++){
             for(int k=0;k<j;k++)
                  f[i][j]=minv(f[i-1][k]+m[num[root][i]][j-k],f[i][j]);
             f[i][j]=minv(f[i-1][j]+1,f[i][j]);
         }
     for(int j=1;j<=p;j++) m[root][j]=f[num[root][0]][j];          
}
void dfs(int root){
     for(int i=1;i<=num[root][0];i++)
         dfs(num[root][i]);
     updata(root);     
}
void solve(){
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
            m[i][j]=maxs; 
    dfs(1);
    int count=m[1][p];
    for(int i=2;i<=n;i++)
        if(m[i][p]+1<count)
             count=m[i][p]+1;
    cout<<count<<endl;      
}
int main(){
    readdata();
    solve();
    system("pause");
    return 0;
}
