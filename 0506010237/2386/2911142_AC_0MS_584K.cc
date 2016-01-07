#include<iostream>
using namespace std;
int top=-1;
int m,n,c;
char oil[105][105];
int visit[105][105];
void dfs(int x,int y)
{
      visit[x][y]=true;
      if(oil[x][y-1]=='W' && visit[x][y-1]==false)
         dfs(x,y-1);
      if(oil[x-1][y-1]=='W' && visit[x-1][y-1]==false)
         dfs(x-1,y-1);
      if(oil[x-1][y]=='W' && visit[x-1][y]==false)
         dfs(x-1,y);
      if(oil[x-1][y+1]=='W' && visit[x-1][y+1]==false)
         dfs(x-1,y+1);
      if(oil[x][y+1]=='W' && visit[x][y+1]==false)
         dfs(x,y+1);
      if(oil[x+1][y+1]=='W' && visit[x+1][y+1]==false)
         dfs(x+1,y+1);
      if(oil[x+1][y]=='W' && visit[x+1][y]==false)
         dfs(x+1,y);
      if(oil[x+1][y-1]=='W' && visit[x+1][y-1]==false)
         dfs(x+1,y-1);
}
int main()
{
    int i,j;
   // while(true)
    //{
        scanf("%d %d",&m,&n);
       // if(m==0 && n==0)
          //break;   
        for(i=0;i<=n+1;i++)
        {
           oil[0][i]='*';
           oil[m+1][i]='*';
        }
        for(i=1;i<=m;i++)
        {   
           scanf("%s",&oil[i][1]);
           oil[i][n+1]='*';
        }
        for(i=1;i<=m;i++)
          for(j=1;j<=n;j++)
            visit[i][j]=false;
        c=0;
        for(i=1;i<=m;i++)
          for(j=1;j<=n;j++)
          {
              if(oil[i][j]=='W' && visit[i][j]==false)     
              {        
                  dfs(i,j);
                  c++;
              }              
          }   
        printf("%d\n",c);  
   // }
    system("pause");
    return 0;   
}

