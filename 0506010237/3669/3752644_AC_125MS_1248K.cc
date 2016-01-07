#include<iostream>
using namespace std;
const int base=1000000;
int n,k=0; 
bool saft[400][400]={0};
bool csaft[400][400]={0};
int sign[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
typedef struct{
    int x;
    int y;
    int t;    
}node;
node rect[50010];
node mg[1000000];
int front=-1,rear=0;
bool ok=false;
int cmp(const void *a,const void *b){
     return (*(node *)a).t-(*(node *)b).t;   
}

int main()
{
     int x,y;
     scanf("%d",&n);
     for(int i=0;i<n;i++){
          scanf("%d%d%d",&rect[i].x,&rect[i].y,&rect[i].t);
          saft[rect[i].x][rect[i].y]=true;
          if(rect[i].x>0) saft[rect[i].x-1][rect[i].y]=true;
          if(rect[i].y>0) saft[rect[i].x][rect[i].y-1]=true;
          saft[rect[i].x+1][rect[i].y]=true;
          saft[rect[i].x][rect[i].y+1]=true;        
     } 
     qsort(rect,n,sizeof(rect[0]),cmp);
     mg[0].x=0; mg[0].y=0; mg[0].t=0;
     while(front<rear){
           front=(front+1)%base;
           while(rect[k].t<=mg[front].t){
                   for(int i=0;i<4;i++){
                        x=rect[k].x+sign[i][0]; y=rect[k].y+sign[i][1];
                        if(x>=0 && y>=0) csaft[x][y]=true;        
                   }
                   k++;                               
           } 
           if(csaft[mg[front].x][mg[front].y]) continue; 
           if(!saft[mg[front].x][mg[front].y]){
               ok=true;
               break;                                    
           }     
           csaft[mg[front].x][mg[front].y]=true;
           for(int i=0;i<4;i++){
               x=mg[front].x+sign[i][0]; y=mg[front].y+sign[i][1];
               if(x>=0 && y>=0 && !csaft[x][y]){
                   rear=(rear+1)%base;
                   mg[rear].x=x; mg[rear].y=y; mg[rear].t=mg[front].t+1;        
               }        
           }
     }
     if(ok==true) printf("%d\n",mg[front].t);
     else printf("-1\n");
     system("pause");
     return 0;
}
