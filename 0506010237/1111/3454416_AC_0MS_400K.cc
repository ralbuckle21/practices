#include<iostream>
using namespace std;
bool visit[22][22];
int row,col,sum=0;
char c[23][23];
void f(int x,int y){
     if(x<0 || y<0 || x>=row || y>=col || visit[x][y] || c[x][y]!='X') return;
     visit[x][y]=true;
     sum=sum+4;
     f(x+1,y);
     f(x,y-1);
     f(x-1,y);
     f(x,y+1);
     f(x+1,y+1);
     f(x+1,y-1);
     f(x-1,y-1);
     f(x-1,y+1);
     if(x>0 && c[x-1][y]=='X') sum--;   
     if(y>0 && c[x][y-1]=='X') sum--;
     if(x<row-1 && c[x+1][y]=='X') sum--;
     if(y<col-1 && c[x][y+1]=='X') sum--;
}
int main()
{
    int x,y;
    while(true){
         scanf("%d%d%d%d",&row,&col,&x,&y);        
         if(row==0) break;  
         memset(visit,0,sizeof(visit));
         for(int i=0;i<row;i++) scanf("%s",c[i]);
         f(x-1,y-1);
         printf("%d\n",sum);
         sum=0;     
    }
    system("pause");
    return 0;
}
