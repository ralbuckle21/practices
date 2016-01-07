#include<iostream>
using namespace std;
const int base=500000;
bool visit[1048578];
struct{
     bool v[20];
     int step;  
}node[base];
int front=-1,rear=0;
int getv(int k){
     int r=0;
     for(int i=0;i<20;i++) r=r*2+node[k].v[i];
     return r;   
}
void bfs(){
     int v=getv(0);
     if(v==0){ cout<<0<<endl; return;}
     while(true){
          front=(front+1)%base;
          for(int i=0;i<20;i++){
                rear=(rear+1)%base;
                node[rear]=node[front]; node[rear].step++;
                for(int j=i-1;j<=i+1;j++) 
                     if(j>=0 && j<20) node[rear].v[j]=!node[rear].v[j];       
               int v=getv(rear);
               if(v==0){ cout<<node[rear].step<<endl;return;}
               if(visit[v]) rear=(rear+base-1)%base;
               else visit[v]=true;                      
          }         
     }     
}
int main()
{
     for(int i=0;i<20;i++) cin>>node[rear].v[i];
     node[rear].step=0;
     bfs();
     system("pause");
     return 0;
}
