#include<iostream>
using namespace std;
char a[1010],b[1010];
int n,m;
int f[1001][1001];
int minv(int x,int y){ return x<y?x:y; }
void dp(){
    for(int i=0;i<=m;i++) f[0][i]=i;
    for(int i=0;i<=n;i++) f[i][0]=i;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
            if(a[i]==b[j]) f[i][j]=f[i-1][j-1]+1;
            else  f[i][j]=minv(f[i-1][j],f[i][j-1]);         
    } 
    cout<<f[n][m]<<endl;    
}
int main(){
    while(scanf("%d %s",&n,a+1)!=EOF){
        scanf("%d %s",&m,b+1);
        dp();
    }
    system("pause");
    return 0;
}
