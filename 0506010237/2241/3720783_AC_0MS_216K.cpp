#include<iostream>
using namespace std;
/* 以每个的面积为基础在他之上所能堆的最大高度,采用记忆化搜索减少了子问题的搜索次数*/ 
int n,cs=1,k;
int num[201][3];
int f[201];
int find(int x){
    if(f[x]!=-1) return f[x];
    int mins=0,i,h;
    for(i=1;i<=k;i++){
        if(num[x][0]>num[i][0] && num[x][1]>num[i][1]){
             h=num[i][2]+find(i);
             if(h>mins) mins=h;                       
        }                  
    }
    f[x]=mins; 
    return mins;
}
int main()
{
    int i,x,y,z;
     while(true){
          scanf("%d",&n);
          if(n==0) break;
          for(i=0,k=0;i<n;i++){
                scanf("%d %d %d",&x,&y,&z);
                k++; num[k][0]=x;num[k][1]=y;num[k][2]=z; 
                k++; num[k][0]=x;num[k][1]=z;num[k][2]=y;
                k++; num[k][0]=y;num[k][1]=x;num[k][2]=z;
                k++; num[k][0]=y;num[k][1]=z;num[k][2]=x;
                k++; num[k][0]=z;num[k][1]=y;num[k][2]=x;
                k++; num[k][0]=z;num[k][1]=x;num[k][2]=y;            
          }
          for(i=0;i<=k;i++) f[i]=-1;
          num[0][0]=num[0][1]=100000;
          printf("Case %d: maximum height = %d\n",cs++,find(0));
     }
     system("pause");
     return 0;
}
