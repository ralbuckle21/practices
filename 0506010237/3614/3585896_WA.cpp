#include<iostream>
using namespace std;
int n,m;
typedef struct{
    int s;
    int d;     
}cow;
cow c[2500];
typedef struct{
    int v;
    int num;       
}bottle; 
bottle bt[2500];
bool map[2500][2500]={0};
int pre[2500][100];
bool searchs[2500][100];
int cmp2(const void *a,const void *b){
     return (*(bottle *)a).v-(*(bottle *)b).v;   
}
bool dfs(int data,int k){
     int i,temp;
     for(int i=0;i<m && c[data].d>=bt[i].v && i!=k;i++){
         for(int j=0;j<bt[i].num;j++){
              if(map[data][i] && !searchs[i][j]){
                   searchs[i][j]=1;
                   temp=pre[i][j];
                   pre[i][j]=data;
                   if(temp==0 || dfs(temp,i)) return true;
               }
         }
     }
     return false;
} 
void cl(){
   for(int i=0;i<m;i++)
      for(int j=0;j<bt[i].num;j++) searchs[i][j]=0;     
}
int main()
{
    memset(pre,-1,sizeof(pre));
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)  scanf("%d %d",&c[i].s,&c[i].d);
    for(int i=0;i<m;i++)  scanf("%d %d",&bt[i].v,&bt[i].num);
    qsort(bt,m,sizeof(bt[0]),cmp2);
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
             if(bt[i].v<=c[j].d && bt[i].v>=c[j].s) 
                  map[j][i]=true;
    int sum=0;
    for(int i=0;i<n;i++){
             cl();
             if(dfs(i,-1)) sum++;
    }
    printf("%d\n",sum);    
    system("pause");
    return 0;
}
