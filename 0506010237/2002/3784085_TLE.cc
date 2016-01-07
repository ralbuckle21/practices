#include<iostream>
using namespace std;
const int base=100000;
int dist[1001][1001];
bool visit[1001];
struct{
     int x,y;   
}point[1001];
int n,sum=0;
struct node{
     int s,d,len;
     struct node *next;     
}*hash[base];
void insert(int len,int s,int d){
     int key=len%base;
     if(!hash[key]){ 
        hash[key]=new node;
        hash[key]->s=s; hash[key]->d=d; hash[key]->len=len; 
        hash[key]->next=NULL;
        return;
    }
    node *p=hash[key];
    while(p) p=p->next;
    p=new node; p->s=s; p->d=d; p->len=len;
    p->next=hash[key]; hash[key]=p;
} 
int search(int s,int len){
    int key=len%base;
    node *p=hash[key];
    while(p){
        if(p->s==s && p->len==len && !visit[p->d]) return p->d;
        p=p->next;         
    }
    return -1;
}
int sqr(int a){ return a*a; }
int getdist(int a,int b){ return sqr(point[a].x-point[b].x)+sqr(point[a].y-point[b].y); }
int main()
{
     while(true){
         int c,d;
         scanf("%d",&n);if(n==0) break;
         for(int i=0;i<base;i++) hash[i]=NULL;
         for(int i=1;i<=n;i++) scanf("%d%d",&point[i].x,&point[i].y);
         for(int i=1;i<=n;i++){
             dist[i][i]=0;
             for(int j=i+1;j<=n;j++){
                 dist[i][j]=getdist(i,j); 
                 dist[j][i]=dist[i][j];
                 insert(dist[i][j],i,j);
                 insert(dist[j][i],j,i);        
             }
         }
         for(int i=1;i<=n;i++)
             for(int j=i+1;j<=n;j++){
                  int len=dist[i][j];
                  memset(visit,0,sizeof(visit));
                  visit[i]=1;visit[j]=1;
                  while(true){
                      c=search(j,len);
                      if(c==-1) break;
                      visit[c]=true;
                      while(true){
                         d=search(c,len);
                         if(d==-1) break;
                         visit[d]=true;
                         if(dist[d][i]==len) sum++;            
                      }      
                  }        
         }
         cout<<sum/4<<endl;   
         sum=0;         
     }
     system("pause");
     return 0;
}
