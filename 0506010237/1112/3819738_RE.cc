#include<iostream>
using namespace std;
bool cost[110][110];
int n;
bool num[110];
struct node{
     bool visit;
     int mlen;
     int man[100];   
}f[2][10000],g[10000];
int len[110]={0};
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
     int base=0,pre=1;
     for(int i=1;i<=n;i++){
          base=pre; pre=1-pre; len[i]=len[i-1]; 
          for(int c=0;c<len[i];c++) f[base][c]=f[pre][c];
          f[base][len[i]].man[0]=i; f[base][len[i]].mlen=1;len[i]++;
          for(int c=0;c<len[i-1];c++){
              if(ok(f[pre][c],i)){
                   f[base][len[i]]=f[pre][c]; f[base][len[i]].man[f[base][len[i]].mlen]=i; 
                   f[base][len[i]].mlen++;
                   len[i]++;           
              }        
          }
     }
     int i;
     for(int c=0;c<len[n];c++){
           memset(num,0,sizeof(num));
           for(int j=0;j<f[base][c].mlen;j++) num[f[base][c].man[j]]=true;   
           for(i=1;i<=n;i++){
               if(!num[i]){
                   if(ok(g[c],i)){ 
                        g[c].man[g[c].mlen]=i; 
                        g[c].mlen++; 
                   }       
                   else break;
               }   
           }
           if(i==n+1) f[base][c].visit=true;                 
     }   
     int mins=1000,u;
     for(int i=0;i<len[n];i++)
          if(f[base][i].visit && f[base][i].mlen<n && f[base][i].mlen>0){
               int v=abs(n-2*f[base][i].mlen);
               if(v<mins){ mins=v; u=i; }                  
          }
     if(mins==1000) printf("No solution\n");
     else{
          printf("%d",f[base][u].mlen);
          for(int i=0;i<f[base][u].mlen;i++) printf(" %d",f[base][u].man[i]);
          printf("\n%d",g[u].mlen); 
          for(int i=0;i<g[u].mlen;i++) printf(" %d",g[u].man[i]);
          printf("\n");     
     }
     system("pause");
     return 0;
}
