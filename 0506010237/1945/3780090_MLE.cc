#include<iostream>
using namespace std;
const int base=10000000;
bool visit[40002][20001];
int n;
int up1,up2;
struct{
     int x,y,step;   
}node[base];
int front=-1,rear=0;
void swap(int &a,int &b){ int temp=a; a=b; b=temp; }
int main()
{
    // freopen("bb.txt","w",stdout);
     int x,y,s,dx,dy;
     int a[6];
     scanf("%d",&n);
     up1=2*n,up2=n;
     node[rear].x=1;node[rear].y=0;node[rear].step=0;
     visit[1][0]=1;
     while(front!=rear){
           front=(front+1)%base;
           x=node[front].x,y=node[front].y,s=node[front].step;
           //cout<<x<<" "<<y<<" "<<s<<endl;
           if(node[front].x==n) break;
           a[0]=x; a[1]=y;a[2]=x+y;a[3]=x-y;a[4]=2*x;a[5]=2*y;
           for(int i=0;i<6;i++){
                dx=a[i],dy=y;
                if(dx<dy) swap(dx,dy);
                if(dx<up1 && dy<up2 && dy>=0 && !visit[dx][dy]){
                      rear = (rear+1) % base;
                      node[rear].x=dx,node[rear].y=dy,node[rear].step=s+1;
                      visit[dx][dy]=true;     
                }   
                dx=x,dy=a[i];
                if(dx<dy) swap(dx,dy);
                if(dx<up1 && dy<up2 && dy>=0 && !visit[dx][dy]){
                      rear = (rear+1) % base;
                      node[rear].x=dx,node[rear].y=dy,node[rear].step=s+1;
                      visit[dx][dy]=true;     
                }             
           }   
     }
     printf("%d\n",node[front].step);
     system("pause");
     return 0;
}
