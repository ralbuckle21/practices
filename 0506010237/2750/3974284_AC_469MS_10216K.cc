#include<iostream>
using namespace std;
struct{
     int s,d,mid;
     int sum,max,min;
     int lmax,lmin;
     int rmax,rmin;
     int lson,rson;  
}a[300100];
int data[100050];
int n,m,tag=0;
int maxv(int a,int b){ return a>b?a:b; }
int minv(int a,int b){ return a<b?a:b; }
void change(int k){
    a[k].sum=a[a[k].lson].sum+a[a[k].rson].sum;
    a[k].max=maxv(maxv(a[a[k].lson].max,a[a[k].rson].max),a[a[k].lson].rmax+a[a[k].rson].lmax);
    a[k].min=minv(minv(a[a[k].lson].min,a[a[k].rson].min),a[a[k].lson].rmin+a[a[k].rson].lmin);
    a[k].lmax=maxv(a[a[k].lson].lmax,a[a[k].lson].sum+a[a[k].rson].lmax);
    a[k].lmin=minv(a[a[k].lson].lmin,a[a[k].lson].sum+a[a[k].rson].lmin);
    a[k].rmax=maxv(a[a[k].rson].rmax,a[a[k].rson].sum+a[a[k].lson].rmax);
    a[k].rmin=minv(a[a[k].rson].rmin,a[a[k].rson].sum+a[a[k].lson].rmin); 
}
void build(int left,int right,int k){
    a[k].s=left,a[k].d=right,a[k].mid=(left+right)/2;
    if(left==right){
         a[k].sum=data[left];     
         a[k].max=a[k].min=data[left];
         a[k].lmax=a[k].lmin=data[left];
         a[k].rmax=a[k].rmin=data[left];
         a[k].lson=a[k].rson=-1;
         return;           
    } 
    tag++; a[k].lson=tag; build(left,a[k].mid,tag);
    tag++; a[k].rson=tag; build(a[k].mid+1,right,tag);
    change(k);
}
void updata(int x,int y,int k){
    if(x==a[k].s && a[k].lson==-1){
         a[k].sum=y;     
         a[k].max=a[k].min=y;
         a[k].lmax=a[k].lmin=y;
         a[k].rmax=a[k].rmin=y;
         return;        
    } 
    if(x<=a[k].mid) updata(x,y,a[k].lson);
    else updata(x,y,a[k].rson);
    change(k);
}
int main(){
    int x,y;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&data[i]);
    build(1,n,0);
    scanf("%d",&m);
    while(m--){
        scanf("%d%d",&x,&y);
        updata(x,y,0);
        int ans;
        if(a[0].sum == a[0].max) ans = a[0].sum - a[0].min;
        else ans = maxv(a[0].max,a[0].sum - a[0].min);
        printf("%d\n", ans);           
    }
    system("pause");
    return 0;
}
