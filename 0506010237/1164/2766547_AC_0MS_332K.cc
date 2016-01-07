#include<iostream>
using namespace std;
typedef struct
{
    int sign[4];
    int biaoji;    
}nodes;
nodes node[51][51];
int row,col,sum=0,maxs=0;
int yingyong(int x,int y)
{
    if(node[x][y].biaoji==1)
       return 0;
    int k=1;
    node[x][y].biaoji=1;
    if(node[x][y].sign[0]==1)
       k=k+yingyong(x,y-1);
    if(node[x][y].sign[1]==1)
        k=k+yingyong(x-1,y);
    if(node[x][y].sign[2]==1)
       k=k+yingyong(x,y+1);
    if(node[x][y].sign[3]==1)
       k=k+yingyong(x+1,y);
    return k;            
}
int main()
{
    int k;
    scanf("%d %d",&row,&col);
    for(int i=0;i<row;i++)
       for(int j=0;j<col;j++)
        {
              scanf("%d",&k);
              node[i][j].biaoji=0;
              for(int x=0;x<4;x++)
                 node[i][j].sign[x]=1;
              if(k>=8)
              {
                node[i][j].sign[3]=0;
                k=k-8;
              }
              if(k>=4)
              {
                  node[i][j].sign[2]=0;
                  k=k-4;        
              }      
              if(k>=2)
              {
                  node[i][j].sign[1]=0;
                  k=k-2;        
              }
              if(k==1)
                node[i][j].sign[0]=0;
        }
    for(int i=0;i<row;i++)
      for(int j=0;j<col;j++)
      {
          if(node[i][j].biaoji==0)
          {
             int k=yingyong(i,j);
             sum++;
             if(k>maxs)
               maxs=k;
          }      
      }
    printf("%d\n%d\n",sum,maxs);
    system("pause");
    return 0;
}
