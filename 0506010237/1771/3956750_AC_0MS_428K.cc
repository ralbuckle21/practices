#include<iostream>
using namespace std;
const int maxs=100000000;
int f[34][34];
int r[34][34];
int floor[34];
int s[34],sum;
int n;
void dfs(int x,int y){
     if(x>31 || y>=n) return;
     if(r[x][y]<0) dfs(x+1,y);
     else{
         if(x>1) s[sum++]=x;
         dfs(x,r[x][y]+1);     
     }    
}
int main(){
    while(scanf("%d",&n) && n!=0){
          for(int i=0;i<n;i++) scanf("%d",&floor[i]);
          memset(f,0,sizeof(f));
          for(int i=0;i<n;i++) f[32][i]=maxs;
          for(int i=31;i>=1;i--)                  
              for(int j=n-1;j>=0;j--){
                   f[i][j]=f[i+1][j]+4;
                   r[i][j]=-1;
                   int walk=0;
                   for(int k=j;k<n;k++){
                       walk=max(walk,abs(floor[k]-i)*20);
                       int p;
                       if(k<n-1){
                            int t=f[i][k+1];
                            if(i>1) t+=10;
                            p=max(walk,t);         
                       }        
                       else p=walk;
                       if(p<f[i][j]){
                            f[i][j]=p;
                            r[i][j]=k;
                       }
                   }       
              }  
          printf("%d\n",f[1][0]);
          sum=0;
          dfs(1,0);
          printf("%d",sum);
          for(int i=0;i<sum;i++) printf(" %d",s[i]);
          printf("\n");      
    }
    system("pause");
    return 0;
}
