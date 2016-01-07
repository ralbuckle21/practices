#include<iostream>
using namespace std;
bool cost[110][110];
int n;
bool num[110];
struct node{
     bool visit;
     int mlen;
     int man[80];   
}f[101][1000],g[1000];
int len[110];
bool ok(node a,int x){
     for(int i=0;i<a.mlen;i++) 
         if(!cost[a.man[i]][x] || !cost[x][a.man[i]]) return false;
     return true;
}
int main()
{
     int x;
     scanf("%d",&n);
     for(int i=1;i<=n;i++){
          while(true){
               scanf("%d",&x); 
               if(x==0) break;
               cost[i][x]=true;            
          }        
     }
     for(int i=1;i<=n;i++){
          len[i]=1; f[i][0].man[0]=i; f[i][0].mlen=1;
          for(int j=1;j<i;j++){
              for(int c=0;c<len[j];c++){
                     if(ok(f[j][c],i)){
                          f[i][len[i]]=f[j][c]; f[i][len[i]].man[f[i][len[i]].mlen]=i; f[i][len[i]].mlen++;
                          len[i]++;           
                     }
              }        
          }
     }
     int i;
     for(int c=0;c<len[n];c++){
           memset(num,0,sizeof(num));
           for(int j=0;j<f[n][c].mlen;j++) num[f[n][c].man[j]]=true;   
           for(i=1;i<=n;i++){
               if(!num[i]){
                   if(ok(g[c],i)){ 
                        g[c].man[g[c].mlen]=i; 
                        g[c].mlen++; 
                   }       
                   else break;
               }   
           }
           if(i==n+1) f[n][c].visit=true;                 
     }   
     int mins=1000,u;
     for(int i=0;i<len[n];i++)
          if(f[n][i].visit && f[n][i].mlen<n && f[n][i].mlen>0){
               int v=abs(n-2*f[n][i].mlen);
               if(v<mins){ mins=v; u=i; }                  
          }
     if(mins==1000) printf("No solution\n");
     else{
          printf("%d",f[n][u].mlen);
          for(int i=0;i<f[n][u].mlen;i++) printf(" %d",f[n][u].man[i]);
          printf("\n%d",g[u].mlen); 
          for(int i=0;i<g[u].mlen;i++) printf(" %d",g[u].man[i]);
          printf("\n");     
     }
     system("pause");
     return 0;
}
