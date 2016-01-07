#include<iostream>
using namespace std;
int tree[100010][2];
int a[100010][2];
int c[100010];
int sign[100010];
int n,m,cs=1;
int lowbit(int x){ return (x & (x^(x-1))); }
void dfs(int k){
    if(tree[k][0]!=0) dfs(tree[k][0]);
    if(tree[k][1]!=0) dfs(tree[k][1]);
    sign[k]=cs;  a[k][0]=1;
    if(tree[k][0]==0) a[k][1]=cs;
    else a[k][1]=sign[tree[k][0]];    
    cs++; 
}
void modify(int k,int data){
    while(k<=n) {
        c[k]=c[k]+data;
        k=k+lowbit(k);           
    }
}
int sum(int x){
   int result=0;
   while(x>0){   
       result=result+c[x];
       x=x-lowbit(x);
   }
   return result;
}
int main(){
    int x,y; char p[2];
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        scanf("%d%d",&x,&y);
        if(tree[x][0]==0) tree[x][0]=y;
        else tree[x][1]=y;        
    }
    dfs(1);
    for(int i=1;i<=n;i++) modify(sign[i],1);
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        scanf("%s%d",p,&x);
        if(p[0]=='C'){
             if(a[sign[x]][0]) modify(sign[x],-1);
             else modify(sign[x],1);
             a[sign[x]][0]=1-a[sign[x]][0];
        }
        else cout<<sum(sign[x])-sum(a[x][1]-1)<<endl;     
    }
    system("pause");
    return 0;
}
