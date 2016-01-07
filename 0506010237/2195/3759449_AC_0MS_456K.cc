#include<iostream>
using namespace std;
char c[210][210];
int n,m;
int map[110][110];
bool x[110],y[110];
int pre[110];
int lx[110],ly[110];
struct{
    int x,y;      
}point[220];
int len;
int abv(int a){ return a>0?a:-a; }
bool find(int k){
     x[k]=true;
     for(int j=1;j<=n;j++){
          if(!y[j] && lx[k]+ly[j]==map[k][j]){
                y[j]=true;
                if(pre[j]==0 || find(pre[j])){
                      pre[j]=k;
                      return true;             
                }   
          }        
     }    
     return false;
}
int main()
{
     while(true){
         scanf("%d %d",&n,&m);
         if(n==0 && m==0) break;
         len=1;
         for(int i=0;i<n;i++) scanf("%s",c[i]);
         for(int i=0;i<n;i++)
             for(int j=0;j<m;j++)
                 if(c[i][j]=='m'){point[len].x=i; point[len].y=j; len++;}        
         for(int i=0;i<n;i++)
             for(int j=0;j<m;j++)
                 if(c[i][j]=='H'){point[len].x=i; point[len].y=j; len++;}
         len--; n=len/2;
         memset(ly,0,sizeof(ly));
         memset(pre,0,sizeof(pre)); 
         for(int i=1;i<=n;i++){ 
             lx[i]=-10000000;
             for(int j=1;j<=n;j++)
                 map[i][j]=-abv(point[i].x-point[j+n].x)-abv(point[i].y-point[j+n].y);
         }
         for(int i=1;i<=n;i++)
              for(int j=1;j<=n;j++)
                 if(lx[i]<map[i][j]) lx[i]=map[i][j];
         for(int k=1;k<=n;k++){
             while(true){
                   memset(x,0,sizeof(x));
                   memset(y,0,sizeof(y)); 
                   if(find(k)) break; 
                   int d=INT_MAX;
                   for(int i=1;i<=n;i++){
                        if(x[i])
                        for(int j=1;j<=n;j++)
                            if(!y[j] && d>lx[i]+ly[j]-map[i][j])
                                d=lx[i]+ly[j]-map[i][j];         
                   }
                   for(int i=1;i<=n;i++){
                        if(x[i]) lx[i]-=d;
                        if(y[i]) ly[i]+=d;       
                   }           
             }  
         }
         int sum=0;
         for(int i=1;i<=n;i++) sum += map[pre[i]][i];
         printf("%d\n",-sum);                  
     }
     system("pause");
     return 0;
}
