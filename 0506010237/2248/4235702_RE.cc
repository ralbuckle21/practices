#include<iostream>
using namespace std;
const int base=100000;
struct{
     int v;
     int pre;   
}q[base];
int front,rear;
int n;
void print(){
     int d[110],len=0,x=front;
     while(x!=-1){
          d[len++]=q[x].v;   
          x=q[x].pre;          
     }     
     for(int i=len-1;i>=0;i--) printf("%d ",d[i]);
     printf("\n");
}
void bfs(){
     int x,v,y;
     front=-1; rear=0;
     q[rear].v=1; q[rear].pre=-1;
     while(front<rear){
         front++; 
         v=q[front].v;
         if(v==n){ print(); return; }
         x=front;
         while(x!=-1){
              y=v+q[x].v;
              x=q[x].pre;
              if(y<=n){
                  rear++;
                  q[rear].v=y;
                  q[rear].pre=front;         
              }            
         }                 
     } 
}
int main(){
    bfs();
    while(cin>>n && n!=0) bfs();
    system("pause");
    return 0;
}
