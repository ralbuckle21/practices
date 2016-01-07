#include<iostream>
using namespace std;
struct point{
    int x,y;       
};
struct node{
    point a,b;       
}s[13];
int f[13];
int n;
int maxs(int a,int b){ return a>b?a:b; }
int mins(int a,int b){ return a<b?a:b; }
int find(int x){
    int r=x;
    while(r!=f[r]) r=f[r];
    while(f[x]!=r){
         int temp=f[x];
         f[x]=r;
         x=temp;               
    }    
    return r;
}
void unions(int a,int b){
     int x=find(a),y=find(b);
     if(x!=y) f[x]=y;
}
int mul(point p1,point p2,point p0){
   return((p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y));
}
bool intersect(node u,node v){
     if(maxs(u.a.x,u.b.x)>=mins(v.a.x,v.b.x)) 
     if(mins(u.a.x,u.b.x)<=maxs(v.a.x,v.b.x)) 
     if(maxs(u.a.y,u.b.y)>=mins(v.a.y,v.b.y)) 
     if(maxs(v.a.y,v.b.y)>=mins(u.a.y,u.b.y)) 
     if(mul(v.a,u.b,u.a)*mul(u.b,v.b,u.a)>=0) 
     if(mul(u.a,v.b,v.a)*mul(v.b,u.b,v.a)>=0)
     return true;
     return false;    
}
void solve(){
    int x,y;
    for(int i=0;i<n;i++) f[i]=i;
    for(int i=0;i<n;i++){ 
        scanf("%d%d%d%d",&s[i].a.x,&s[i].a.y,&s[i].b.x,&s[i].b.y);    
        for(int j=0;j<i;j++)
            if(intersect(s[i],s[j])) unions(i,j); 
    }
    while(true){
        scanf("%d%d",&x,&y);
        if(x==0 && y==0) break;
        if(find(x-1)==find(y-1)) printf("CONNECTED\n");
        else printf("NOT CONNECTED\n");            
    }
}
int main(){
    while(true){
        scanf("%d",&n); 
        if(n==0) break;
        solve();            
    }
    system("pause");
    return 0;
}
