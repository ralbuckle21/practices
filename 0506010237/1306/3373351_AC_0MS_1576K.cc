#include<iostream>
using namespace std;
struct{
     int num[40];       
     int len;
}f[102][102];
int n,m;
int maxs(int x,int y){
     return x>y?x:y;
}
void add(int x,int y)
{
    int i=1,c=0; 
    f[x][y].len=maxs(f[x-1][y-1].len,f[x-1][y].len)+1;
    while(i<=f[x][y].len){
          f[x][y].num[i]=f[x-1][y-1].num[i]+f[x-1][y].num[i]+c;
          c=f[x][y].num[i]/10;
          f[x][y].num[i]=f[x][y].num[i]%10;   
          i++;          
    }  
    int k=f[x][y].len;
    while(f[x][y].num[k]==0) k--;
    f[x][y].len=k;   
}
void init(){
    for(int i=1;i<=100;i++){
        f[i][0].num[1]=f[i][i].num[1]=1;
        f[i][0].len=f[i][i].len=1;
        for(int j=1;j<i;j++) add(i,j);        
    }
}
int main()
{
    init();
   	while(true){
        scanf("%d %d",&n,&m);
        if(n==0 && m==0) break;
        printf("%d things taken %d at a time is ",n,m);
        for(int i=f[n][m].len;i>=1;i--) printf("%d",f[n][m].num[i]);   
        printf(" exactly.\n");
	}
    system("pause");
    return 0;
}
