#include<iostream>
using namespace std;
const int base=70000;
int sign[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
int n,m,L,cs=1,k;
struct{
    int step; 
    int p[8][2];      
    bool flag[22][22];
}q[base];
int front,rear;
void strcpyflag(){
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            q[rear].flag[i][j]=q[front].flag[i][j];     
}
bool bfs(){
     int x,y;
     while(front!=rear && front!=base){
            front=(front+1)%base;
            if(q[front].p[0][0]==1 && q[front].p[0][1]==1){
                  cout<<q[front].step<<endl;
                  return true;                       
            }   
            for(int i=0;i<4;i++){
                  x=q[front].p[0][0]+sign[i][0]; y=q[front].p[0][1]+sign[i][1];
                  if(x<1 || y<1 || x>n || y>m || q[front].flag[x][y]) continue;
                  rear=(rear+1)%base; strcpyflag(); 
                  q[rear].step=q[front].step+1;
                  for(int j=0;j<L-1;j++){
                       q[rear].p[j+1][0]=q[front].p[j][0];
                       q[rear].p[j+1][1]=q[front].p[j][1];
                  }        
                  q[rear].p[0][0]=x; q[rear].p[0][1]=y;
                  q[rear].flag[x][y]=true; 
                  q[rear].flag[q[front].p[L-1][0]][q[front].p[L-1][1]]=false;
            }               
     }     
     return false;
}
int main(){
    int x,y;
    while(true){
        scanf("%d%d%d",&n,&m,&L);
        if(n==0) break;
        cout<<"Case "<<cs++<<": ";
        front=-1,rear=0;
        memset(q[rear].flag,0,sizeof(q[rear].flag));
        for(int i=0;i<L;i++){
             scanf("%d%d",&x,&y); 
             q[rear].flag[x][y]=true;
             q[rear].p[i][0]=x; 
             q[rear].p[i][1]=y;   
        }
        q[rear].step=0;
        scanf("%d",&k);
        for(int i=1;i<=k;i++){
             scanf("%d%d",&x,&y);
             q[rear].flag[x][y]=true;        
        }
        if(!bfs()) cout<<-1<<endl;
    }
    system("pause");
    return 0;
}
