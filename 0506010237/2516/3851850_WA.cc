#include<iostream>
using namespace std;
const int maxs=INT_MAX/10;
int n,m,k,sum,len;
int supply[120][60];
int stock[120][60];
bool visit[120],flat;
int u,c[120],pre[120],f[120];
struct{
      int cost,c;
      int f,rf;
}num[120][120];
int mins(int a,int b){ return a<b?a:b; }
int feiyong(int t){
       for(int i=1;i<len;i++){
           visit[i]=0;
           c[i]=num[0][i].cost;
           f[i]=num[0][i].f;
           pre[i]=0; 
       }
       visit[0]=1;pre[0]=-1;
       while(true){
          int min=maxs;
          for(int j=1;j<len;j++)
               if(visit[j]==0 && c[j]<min){   
                  min=c[j];
                  u=j;   
               }
          if(min==maxs) return min;
          visit[u]=1;
          if(u==len-1){
             int w1=pre[u],w2=u;
             while(w1!=-1){
                 if(num[w1][w2].rf>0){
                         num[w1][w2].rf=num[w1][w2].rf-f[u];
                         stock[w2][t]+=f[u];
                         supply[w1][t]+=f[u];
                 }
                 else{
                     if(w1!=0 && w2!=len-1){
                           num[w2][w1].rf=num[w2][w1].rf+f[u]; 
                           supply[w1][t]-=f[u];
                           stock[w2][t]-=f[u];
                     }
                 }
                 w2=w1;w1=pre[w1];
              }   
              return f[u]*c[u];
           } 
           for(int w=1;w<len;w++){
                if(visit[w]==0){
                    if(num[u][w].rf>0 && c[w]>c[u]-num[w][u].c){
                         c[w]=c[u]-num[w][u].c;
                         f[w]=f[u]<=num[u][w].rf?f[u]:num[u][w].rf;   
                         pre[w]=u;
                    }
                    else if(c[w]>c[u]+num[u][w].cost){
                         c[w]=c[u]+num[u][w].cost;
                         f[w]=f[u]<=num[u][w].f?f[u]:num[u][w].f;
                         pre[w]=u;    
                    }                   
               }      
           }
      }
}
void startfei(int t){
     int v=0; 
     while(true){
        for(int i=1;i<=n;i++)
           for(int j=n+1;j<=n+m;j++)
               num[i][j].f=mins(supply[i][t],stock[j][t]);
         for(int i=0;i<len;i++)
             for(int j=0;j<len;j++)
                  if(num[i][j].f==0) num[i][j].cost=maxs;
                  else num[i][j].cost=num[i][j].c;
        v=feiyong(t);
        if(v==maxs) break;
        sum+=v;     
     }     
}
void input(){
     int v; flat=false;
     sum=0; len=n+m+2;
     for(int i=1;i<=n;i++)
          for(int j=0;j<k;j++)
              scanf("%d",&supply[i][j]);
     for(int i=n+1;i<=n+m;i++)
          for(int j=0;j<k;j++)
              scanf("%d",&stock[i][j]); 
     for(int t=0;t<k;t++){
        memset(num,0,sizeof(num));
        for(int i=1;i<=n;i++)
            for(int j=n+1;j<=n+m;j++)
               scanf("%d",&num[i][j].c);    
        for(int i=1;i<=n;i++){ num[0][i].f=maxs; num[0][i].c=0;}
        for(int i=n+1;i<=n+m;i++){ num[i][n+m+1].f=maxs; num[i][n+m+1].c=0;}   
        if(!flat){  
              startfei(t);
              for(int i=1;i<=n;i++) if(supply[i][t]!=0){flat=true; break;}
        }
     }          
}
int main()
{
     while(true){
         scanf("%d%d%d",&n,&m,&k);
         if(n==0 && m==0 && k==0) break;
         input();    
         if(flat) printf("-1\n");
         else printf("%d\n",sum);          
     }
     system("pause");
     return 0;
}
