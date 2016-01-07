#include<iostream>
using namespace std;
const int maxs=INT_MAX/10;
struct{
     int s;
     int d;
     int w;   
}node[2000001];
int dist[2000001];
int n,m1,m2,e;
bool bellman(){
     bool flat;
     for(int i=1;i<n;i++) dist[i]=maxs; dist[0]=0;
     for(int i=1;i<n;i++){
          flat=true;   
          for(int j=0;j<e;j++)
                if(dist[node[j].s]!=maxs & dist[node[j].s]+node[j].w<dist[node[j].d]){
                       dist[node[j].d]=dist[node[j].s]+node[j].w; 
                       flat=false;     
                }
          for(int j=n-1;j>0;j--){
               if(dist[j-1]>dist[j]) dist[j-1]=dist[j]; 
               flat=0;
          }        
          if(flat) break;
     }
     for(int j=0;j<e;j++)
         if(dist[node[j].s]+node[j].w<dist[node[j].d]) return false;
     return true;
}
int main()
{
     int x,y,w;
     scanf("%d%d%d",&n,&m1,&m2); e=m1+m2;
     for(int i=0;i<m1;i++){
           scanf("%d%d%d",&x,&y,&w);
           x--; y--;
           node[i].s=x; node[i].d=y; node[i].w=w;  
     }
     for(int i=m1;i<e;i++){
           scanf("%d%d%d",&x,&y,&w);
           x--; y--;
           node[i].s=y; node[i].d=x; node[i].w=-w;        
     }
     if(bellman()){
           if(dist[n-1]==maxs) printf("-2\n");
           else printf("%d\n",dist[n-1]);              
     }
     else printf("-1\n");
     system("pause");
     return 0;
}
