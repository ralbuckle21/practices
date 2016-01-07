#include<iostream>
using namespace std;
const int base=500000;
int sign[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
int n,m,L,cs=1,k;
bool flag[6553600];
bool visit[20][20];
struct{
    int step;
    int x,y; 
    int s[7]; 
    int p[7][2];     
}q[base];
int front,rear;
int ssign(int sx,int sy,int dx,int dy){
     int x=dx-sx,y=dy-sy;
     if(x==-1) return 1;
     else if(x==1) return 3;
     else if(y==-1) return 2;
     return 0;   
}
int getv(){
    int sum=20*q[front].x+q[front].y;
    for(int i=0;i<L-1;i++) sum=sum*4+q[front].s[i];
    return sum;
}
bool zishan(int dx,int dy){
    for(int i=0;i<L-1;i++) 
       if(dx==q[front].p[i][0] && dy==q[front].p[i][1]) return true;
    return false; 
}
bool bfs(){
     int x,y,v;
     while(front!=rear){
            front=(front+1)%base;
            v=getv();
            if(flag[v]) continue;
            flag[v]=true;
            if(q[front].x==0 && q[front].y==0){
                  cout<<q[front].step<<endl;
                  return true;                       
            }   
            for(int i=0;i<4;i++){
                  x=q[front].x+sign[i][0]; y=q[front].y+sign[i][1];
                  if(x<0 || y<0 || x>=n || y>=m || visit[x][y]) continue;
                  if(zishan(x,y)) continue;
                  rear=(rear+1)%base; 
                  q[rear].step=q[front].step+1; q[rear].x=x; q[rear].y=y;
                  for(int j=0;j<L-2;j++){
                       q[rear].s[j+1]=q[front].s[j];
                       q[rear].p[j+1][0]=q[front].p[j][0];
                       q[rear].p[j+1][1]=q[front].p[j][1];
                  }      
                  q[rear].s[0]=ssign(x,y,q[front].x,q[front].y);
                  q[rear].p[0][0]=q[front].x;
                  q[rear].p[0][1]=q[front].y;
            }               
     }     
     return false;
}
int main(){
    int sx,x,sy,y;
    while(true){
        scanf("%d%d%d",&n,&m,&L);
        if(n==0) break;
        front=-1,rear=0;
        memset(flag,0,sizeof(flag));
        memset(visit,0,sizeof(visit));
        scanf("%d%d",&x,&y); x--; y--;
        q[rear].x=x,q[rear].y=y;q[rear].step=0;
        sx=x,sy=y;
        for(int i=0;i<L-1;i++){
             scanf("%d%d",&x,&y); x--; y--;
             q[rear].s[i]=ssign(sx,sy,x,y);
             q[rear].p[i][0]=x; q[rear].p[i][1]=y;
             sx=x,sy=y;
        }
        scanf("%d",&k);
        for(int i=1;i<=k;i++){
             scanf("%d%d",&x,&y); x--; y--;
             visit[x][y]=true;        
        }
        cout<<"Case "<<cs++<<": ";
        if(!bfs()) cout<<-1<<endl;
    }
    system("pause");
    return 0;
}


