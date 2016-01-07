#include<iostream>
using namespace std;
int n,m,t,cnt;
bool map[1402][1401],searchs[1402];
int pre[1402];
char s[42][12]; 
int id[42][12];
int sign[4][2]={{0,-1},{-1,0},{0,1},{1,0}};
bool dfs(int data){
     for(int i=1;i<=cnt;i++){
         if(map[data][i] && !searchs[i]){
              searchs[i]=true;
              if(pre[i]==0 || dfs(pre[i])){
                  pre[i]=data;
                  return true;
              }
          }
     }
     return false;
} 
int main()
{
    int x,y;
    scanf("%d",&t);
    while(t--){
         scanf("%d %d",&n,&m);
         memset(map,0,sizeof(map));
         memset(pre,0,sizeof(pre));
         cnt=0;
         for(int i=0;i<n;i++){
             scanf("%s",s[i]);
             for(int j=0;j<m;j++)
                 if(s[i][j]=='*') 
                     id[i][j]=++cnt;
         }
         for(int i=0;i<n;i++)
              for(int j=0;j<m;j++)
                   if(s[i][j]=='*')
                       for(int k=0;k<4;k++){
                            x=i+sign[k][0]; y=j+sign[k][1];
                            if(x>=0 && y>=0 && x<n && y<m) 
                                 map[id[i][j]][id[x][y]]=true;        
                       }        
         int num=0;
         for(int i=1;i<=cnt;i++){
                 memset(searchs,0,sizeof(searchs));
                 if(dfs(i)) num++;
         }
         num=num/2;
         for(int i=1;i<=cnt;i++) 
                if(pre[i]==0) num++;
         printf(" %d\n",num);
    }     
    system("pause");
    return 0;
}
