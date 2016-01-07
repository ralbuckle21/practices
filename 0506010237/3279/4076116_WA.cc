#include<iostream>
using namespace std;
bool c[15][15];
bool v[15][15];
int sign[5][2]={{0,0},{-1,0},{0,1},{1,0},{0,-1}};
int n,m,cs=1000;
bool flag=false;
bool total[15][15];
bool ok(){
    for(int i=0;i<m;i++)
         for(int j=0;j<n;j++)
             if(c[i][j]) return false;
    return true;
}
void find(int x,int y,int t){
    if(x==m){
        if(ok()){
             flag=true;
             if(t<cs){
                 cs=t;
                 for(int i=0;i<m;i++)
                     for(int j=0;j<n;j++)
                         total[i][j]=v[i][j];
             }     
        }
        return;        
    }     
    if(c[x-1][y]){
         v[x][y]=true;
         for(int i=0;i<5;i++){
             int a=x+sign[i][0],b=y+sign[i][1];
             if(a>=0 && a<m && b>=0 && b<n) c[a][b]=!c[a][b];        
         }
         if(y==n) find(x+1,0,t+1);
         else find(x,y+1,t+1);
         v[x][y]=false;
         for(int i=0;i<5;i++){
             int a=x+sign[i][0],b=y+sign[i][1];
             if(a>=0 && a<m && b>=0 && b<n) c[a][b]=!c[a][b];        
         }             
    } 
    else{
         if(y==n) find(x+1,0,t);
         else find(x,y+1,t);     
    }    
}
void dfs(int k,int t){
    if(k==n){
         find(1,0,t);
         return;         
    }
    dfs(k+1,t);
    for(int i=0;i<5;i++){
         int x=sign[i][0],y=k+sign[i][1];
         if(x>=0 && x<m && y>=0 && y<n) c[x][y]=!c[x][y];        
    }
    v[0][k]=true;
    dfs(k+1,t+1);
    v[0][k]=false;     
    for(int i=0;i<5;i++){
         int x=sign[i][0],y=k+sign[i][1];
         if(x>=0 && x<m && y>=0 && y<n) c[x][y]=!c[x][y];        
    }         
}
int main(){
    scanf("%d%d",&m,&n);
    for(int i=0;i<m;i++)
         for(int j=0;j<n;j++)
              scanf("%d",&c[i][j]);
    dfs(0,0);
    if(flag){
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)
               printf("%d ",total[i][j]);
            printf("\n");
        }           
    }
    else printf("IMPOSSIBLE\n");       
    system("pause");
    return 0;
}
