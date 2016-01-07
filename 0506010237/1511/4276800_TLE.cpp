#include<iostream>
using namespace std;
const int base=1000010;
long long maxs;
struct edge{
     int s;
     int d;
     long long w;   
}es[base],er[base];
long long dist[base];
int n,e,t;
long long sum=0;
void bellman(edge num[base]){
    bool flag;
    for(int i=1;i<=n;i++) dist[i]=maxs;
    dist[1]=0;
    while(true){
         flag=true;
         for(int j=0;j<e;j++){
               if(dist[num[j].s]+num[j].w<dist[num[j].d]){
                     dist[num[j].d]=dist[num[j].s]+num[j].w;
                     flag=false;                                           
               }        
         }
         if(flag) break;    
    }     
    for(int i=2;i<=n;i++) sum+=dist[i];
}
int main(){
    maxs=1;
    for(int i=1;i<63;i++) maxs <<= 1;
    scanf("%d",&t);
    while(t--){
         scanf("%d%d",&n,&e);
         for(int i=0;i<e;i++){
             scanf("%d%d%lld",&es[i].s,&es[i].d,&es[i].w);
             er[i].s=es[i].d; er[i].d=es[i].s; er[i].w=es[i].w;      
         }
         bellman(es);
         bellman(er);
         printf("%lld\n",sum);
         sum=0;           
    }
    system("pause");
    return 0;
}
