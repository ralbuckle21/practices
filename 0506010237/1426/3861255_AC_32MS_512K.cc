#include<iostream>
using namespace std;
const int base=1000000;
bool r[202];
int n;
struct{
      int c[101];
      int len;      
}node[base];
int rear;
int div(int m){
     int v=1;
     for(int i=1;i<m;i++){
          v=v*10;
          v=v%n;
     }
     return v;
}
int add(int a,int b){
    node[rear]=node[a];
    node[rear].len=b; node[rear].c[b]=1;
    int v=0;
    for(int i=b;i>0;i--){
        v=v*10+node[rear].c[i];
        v=v%n;        
    }     
    return v;
}
void output(int k){
    for(int i=node[k].len;i>0;i--) printf("%d",node[k].c[i]);
    printf("\n"); 
}
void bfs(){
    rear=1;
    node[rear].c[1]=1; node[rear].len=1;
    for(int i=2;i<=100;i++){
         int x=div(i),d=rear; 
         if(!r[x]){ 
               rear++;
               node[rear]=node[0];
               node[rear].len=i; node[rear].c[i]=1;
               r[x]=true;
               if(x==0){output(rear); return; }
         }     
         for(int s=0;s<=d;s++){
               rear++;
               int k=add(s,i); 
               if(r[k]) { rear--; continue;  }
               if(k==0) { output(rear); return; }
               r[k]=true;                   
         } 
    }
}
int main()
{
     while(true){
          scanf("%d",&n);
          if(n==0) break;
          memset(r,0,sizeof(r));
          bfs();            
     }
     system("pause");
     return 0;
}
