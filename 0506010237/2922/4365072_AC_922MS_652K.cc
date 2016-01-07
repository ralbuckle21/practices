#include<iostream>
using namespace std;
int sign[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
bool flag[100][100];
int h[100][100];
int t,n,cs=1;
bool find(int x,int y,int minh,int maxh){
     int sx,sy,i;
     if(flag[x][y]) return false;
     flag[x][y]=true;
     if(h[x][y]<minh || h[x][y]>maxh) return false;
     if(x==n-1 && y==n-1)  return true;
     for(i=0;i<4;i++){
          sx=x+sign[i][0]; sy=y+sign[i][1];
          if(sx<0 || sx>=n || sy<0 || sy>=n) continue;
          if(find(sx,sy,minh,maxh)) return true;              
     }    
     return false;
}
void search(int minh,int maxh){
     int left=0,right=maxh-minh,mid,i;
     while(left<=right){
          mid=(left+right)/2;
          for(i=minh;i<=maxh-mid;i++){
               memset(flag,0,sizeof(flag));
               if(find(0,0,i,i+mid)) break;                              
          }
          if(i>maxh-mid) left=mid+1;
          else right=mid-1;
     }
     printf("%d\n\n",left);
}
int main(){
    int minh,maxh;
    scanf("%d",&t);
    while(t--){
        minh=1000; maxh=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                scanf("%d",&h[i][j]);
                if(h[i][j]>maxh) maxh=h[i][j];
                if(h[i][j]<minh) minh=h[i][j];
            }
        }
        printf("Scenario #%d:\n",cs++);
        search(minh,maxh);           
    }
    system("pause");
    return 0;
}
