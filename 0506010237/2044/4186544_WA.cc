#include<iostream>
using namespace std;
const int base=500000;
int sign[9]={0,1,-4,-1,2,-8,-2,8};
struct{
     int x;
     int step;
     int rain[16];  
}q[base],s;
int front,rear;
bool r[367][16];
int cnt=0;
int n;
bool match(){
      int x=s.x,k=s.step;  
      if(r[k][x] || r[k][x+1] || r[k][x+4] || r[k][x+5]) return true;
      for(int i=0;i<16;i++) if(s.rain[i]>6) return true;
      return false;  
}
void bfs(){
     int x,y;
     front=-1,rear=0;
     q[0].x=5; q[0].step=0;
     for(int i=0;i<16;i++) q[0].rain[i]=1;
     q[0].rain[5]=0; q[0].rain[6]=0; q[0].rain[9]=0; q[0].rain[10]=0;
     if(match()){ cout<<0<<endl; return;}
     while(front!=rear){
          front=(front+1)%base; 
          if(q[front].step==n-1){ cout<<1<<endl; return; }
          for(int i=0;i<9;i++){
               x=q[front].x+sign[i];
               if((x>=0 && x<=2) || (x>=4 && x<=6) || (x>=8 && x<=10)){
                     for(int j=0;j<16;j++) s.rain[j]=q[front].rain[j]+1;
                     s.rain[x]=0; s.rain[x+1]=0; s.rain[x+4]=0; s.rain[x+5]=0; 
                     s.x=x; s.step=q[front].step+1;      
                     if(match()) continue;
                     rear=(rear+1)%base;
                     q[rear]=s; 
                     cnt++;
               }      
          }                 
     }    
    // cout<<q[rear].step<<" "<<cnt<<" "<<front<<" "<<rear<<endl;
     cout<<0<<endl;
}
int main(){
    while(true){
         scanf("%d",&n);
         if(n==0) break;
         for(int i=0;i<n;i++)
             for(int j=0;j<16;j++)
                  cin>>r[i][j];
         bfs();            
    }
    system("pause");
    return 0;
}
