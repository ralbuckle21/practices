#include<iostream>
using namespace std;
const int base=10000000;
int lstep,rstep,step;
int t,h,w;
struct{
    int x,y;
    int sign,v;       
}cub[base];
int len,front,rear;
char c[100][100],d[100][100];
bool g;
int sx,sy,s;
void strcpycd(){ for(int i=0;i<h;i++) strcpy(d[i],c[i]); }
void ldfs(){
     if(g) return;
     int sign=(cub[len].sign-2+4)%4,x,y;
     for(int i=0;i<3;i++){
         sign=(sign+1)%4;
         switch(sign){
              case 0: x=cub[len].x; y=cub[len].y-1; break;
              case 1: x=cub[len].x-1; y=cub[len].y; break;
              case 2: x=cub[len].x; y=cub[len].y+1; break;
              case 3: x=cub[len].x+1; y=cub[len].y; break;             
         }        
         if(d[x][y]=='E'){ lstep=cub[len].v+1; g=true; return; }
         if(d[x][y]=='.'){ 
               len++; cub[len].x=x; cub[len].y=y; cub[len].sign=sign; cub[len].v=cub[len-1].v+1; 
               d[x][y]='#'; ldfs(); 
         }
     }  
     len--; cub[len].v=cub[len+1].v+1;  
}
void rdfs(){
     if(g) return;
     int sign=(cub[len].sign-2+4)%4,x,y;
     for(int i=0;i<3;i++){
         sign=(sign+1)%4;
         switch(sign){
              case 0: x=cub[len].x; y=cub[len].y-1; break;
              case 1: x=cub[len].x+1; y=cub[len].y; break;
              case 2: x=cub[len].x; y=cub[len].y+1; break;
              case 3: x=cub[len].x-1; y=cub[len].y; break;             
         }      
         if(d[x][y]=='E'){ rstep=cub[len].v+1; g=true; return; }
         if(d[x][y]=='.'){ 
               len++; cub[len].x=x; cub[len].y=y; cub[len].sign=sign; cub[len].v=cub[len-1].v+1; 
               d[x][y]='#'; rdfs(); 
         }
     }       
     len--; cub[len].v=cub[len+1].v+1;
}
void bfs(){
     int x,y;
     front=-1,rear=0;
     cub[0].x=sx,cub[0].y=sy,cub[0].v=1;     
     while(front<rear){
          front=(front+1)%base;
          if(c[cub[front].x][cub[front].y]=='E'){ step=cub[front].v; return; }
          for(int i=0;i<4;i++){
              switch(i){
                   case 0: x=cub[front].x;y=cub[front].y-1; break;
                   case 1: x=cub[front].x-1;y=cub[front].y; break;
                   case 2: x=cub[front].x;y=cub[front].y+1; break;
                   case 3: x=cub[front].x+1;y=cub[front].y; break;             
              }
              if(c[x][y]=='.' || c[x][y]=='E'){
                   rear=(rear+1)%base;
                   cub[rear].x=x; cub[rear].y=y; cub[rear].v=cub[front].v+1;
                   if(c[x][y]=='.') c[x][y]='#';                           
              }         
          }                  
     }
}
int main()
{
     scanf("%d",&t);
     while(t--){
          scanf("%d%d",&w,&h);
          for(int i=0;i<h;i++) scanf("%s",c[i]);
          for(int i=0;i<h;i++){
               if(c[i][0]=='S'){ sx=i; sy=0; s=2; break;}
               if(c[i][w-1]=='S'){ sx=i; sy=w-1; s=0; break; }                 
          }           
          for(int i=0;i<w;i++){
               if(c[0][i]=='S'){ sx=0; sy=i; s=3; break; }
               if(c[h-1][i]=='S'){ sx=h-1; sy=i; s=1; break; }        
          }
          strcpycd();
          len=0; cub[0].x=sx; cub[0].y=sy; cub[0].sign=s; cub[0].v=1;
          g=false;  ldfs();
          if(s==1 || s==3) s=(s+2)%4; 
          strcpycd();
          len=0; cub[0].x=sx; cub[0].y=sy; cub[0].sign=s; cub[0].v=1;
          g=false;  rdfs();
          bfs(); 
          printf("%d %d %d\n",lstep,rstep,step);
     }
     system("pause");
     return 0;
}
