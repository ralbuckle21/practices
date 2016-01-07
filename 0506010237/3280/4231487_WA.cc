#include<iostream>
using namespace std;
const int maxs=200010000;
int f[2005][2005];
char c[2005],mg[2];
int v[128],w[128];
int n,m;
void init(){
    memset(v,0,sizeof(v));
    memset(w,0,sizeof(w));
    memset(f,0,sizeof(f));
    for(int i=0;i<=n+1;i++)
        for(int j=0;j<=n+1;j++)
           f[i][j]=maxs;
}
int minv(int a,int b){ return a<b?a:b; }
void dp(){
    f[1][n]=0;
    for(int i=1;i<=n;i++){
        for(int j=n;j>=i;j--){
             if(c[i-1]==c[j+1]) f[i][j]=minv(f[i][j],f[i-1][j+1]);
             f[i][j]=minv(f[i][j],f[i-1][j]+minv(v[c[i-1]],w[c[i-1]]));
             f[i][j]=minv(f[i][j],f[i][j+1]+minv(v[c[j+1]],w[c[j+1]]));        
        }        
    }     
    int result=maxs;
    for(int i=1;i<=n;i++)
        if(f[i][i]<result) result=f[i][i];
    cout<<result<<endl; 
}
int main(){
    int x,y;
    scanf("%d%d",&m,&n);
    init();
    scanf("%s",c+1); 
    c[0]=0; c[n+1]=0;
    for(int i=0;i<m;i++){
         scanf("%s%d%d",mg,&x,&y);
         v[mg[0]]=x; w[mg[0]]=y;         
    }
    dp();
    system("pause");
    return 0;
}
