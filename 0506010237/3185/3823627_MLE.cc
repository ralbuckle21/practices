#include<iostream>
using namespace std;
const int base=10000000;
bool visit[1048576];
struct{
     bool v[21];
     int step;  
}node[base];
int front=-1,rear=0;
int getv(int k){
     int r=0;
     for(int i=0;i<20;i++) r=r*2+node[k].v[i];
     return r;   
}
int main()
{
     for(int i=0;i<20;i++) cin>>node[rear].v[i];
     node[rear].step=0;
     while(front<rear){
          front=(front+1)%base;
          int v=getv(front);
          if(v==0) {cout<<node[front].step<<endl; break;}
          if(visit[v]) continue;
          visit[v]=true;
          for(int i=0;i<20;i++){
               if(node[front].v[i]){
                     rear=(rear+1)%base;
                     node[rear]=node[front]; node[rear].step++;
                     for(int j=i-1;j<=i+1;j++) 
                          if(j>=0 && j<20) node[rear].v[j]=!node[rear].v[j];                     
               }        
          }                   
     }
     system("pause");
     return 0;
}
