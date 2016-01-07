#include<iostream>
using namespace std;
int tree[100010][10];
int a[100010][2];
int c[100010];
int sign[100010];
bool visit[100010];
int n,m,cs=1;
inline int lowbit(int x){ return (x & -x); }
int dfs(int k){
    int start=INT_MAX;
    visit[k]=true;
    for(int i=1;i<=tree[k][0];i++) 
       if(!visit[tree[k][i]]){ 
          int x=dfs(tree[k][i]);
          if(x<start) start=x;
       }
    sign[k]=cs;  a[k][0]=1;
    if(start>cs) start=cs;
    a[k][1]=start;   
    cs++; 
    return sign[k];
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
        tree[x][++tree[x][0]]=y;  
        tree[y][++tree[y][0]]=x;      
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
