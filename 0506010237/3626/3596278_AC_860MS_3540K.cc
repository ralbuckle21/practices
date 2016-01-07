#include<iostream>
using namespace std;
int dx,dy,n;
bool visit[1010][1010]={0};
bool mg[1010][1010]={0};
typedef struct{
    int step;      
    int x,y;
}node;
node q[100000];
int front=-1,rear=0;
int find(){
     int tempx,tempy,tempstep;
     q[rear].x=q[rear].y=q[rear].step=0;
     while(true){
         front=(front+1)%100000;
         tempx=q[front].x; tempy=q[front].y; tempstep=q[front].step;
         if(tempx==dx && tempy==dy) return tempstep;
         if(tempx<500 && !visit[tempx+501][tempy+500] && !mg[tempx+501][tempy+500]){
             rear=(rear+1)%100000;
             q[rear].x=tempx+1;
             q[rear].y=tempy;
             q[rear].step=tempstep+1;    
             visit[tempx+501][tempy+500]=1;        
         }                  
         if(tempy<500 && !visit[tempx+500][tempy+501] && !mg[tempx+500][tempy+501]){
             rear=(rear+1)%100000;
             q[rear].x=tempx;
             q[rear].y=tempy+1;
             q[rear].step=tempstep+1;    
             visit[tempx+500][tempy+501]=1;         
         }
         if(tempx>-500 && !visit[tempx+499][tempy+500] && !mg[tempx+499][tempy+500]){
             rear=(rear+1)%100000;
             q[rear].x=tempx-1;
             q[rear].y=tempy;
             q[rear].step=tempstep+1; 
             visit[tempx+499][tempy+500]=1;           
         } 
         if(tempy>-500 && !visit[tempx+500][tempy+499] && !mg[tempx+500][tempy+4999]){
             rear=(rear+1)%100000;
             q[rear].x=tempx;
             q[rear].y=tempy-1;
             q[rear].step=tempstep+1;  
             visit[tempx+499][tempy+500]=1;           
         }
     }
}
int main()
{
    int s,t;
    scanf("%d %d %d",&dx,&dy,&n);
    for(int i=0;i<n;i++){
        scanf("%d %d",&s,&t);
        mg[s+500][t+500]=true;        
    }
    cout<<find()<<endl;
    system("pause");
    return 0;
}
