#include<iostream>
using namespace std;
bool visit[27][27];
int n,m,t;
bool sign;
int step[1000][2];
int ss[8][2]={{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};
void find(int x,int y,int sum){
     if(sign || visit[x][y]) return;
     step[sum][0]=x;step[sum][1]=y;sum++;
     visit[x][y]=true;           
     if(sum==n*m){
           for(int i=0;i<sum;i++) printf("%c%d",step[i][0]+'A'-1,step[i][1]);
           printf("\n");
           sign=true;
           return;           
     }  
     int dx,dy;
     for(int i=0;i<8;i++){
           dx=x+ss[i][0],dy=y+ss[i][1];
           if(dx>0 && dx<=n && dy>0 && dy<=m) find(dx,dy,sum);        
     }
     visit[x][y]=false;
}
int main()
{
     scanf("%d",&t);
     for(int i=1;i<=t;i++){
          scanf("%d%d",&m,&n);
          sign=false;
          memset(visit,0,sizeof(visit));
          printf("Scenario #%d:\n",i);
          find(1,1,0);        
          if(!sign) printf("impossible\n");
          printf("\n");
     }
     system("pause");
     return 0;
}
