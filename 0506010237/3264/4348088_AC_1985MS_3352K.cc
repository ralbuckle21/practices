#include<iostream>
using namespace std;
const int base=50010;
struct tree{
     int lf,rf,mid;
     int lson,rson;
     int vmax,vmin;  
}a[2*base];
int data[base];
int n,q,tag=0;
int lmin,rmax;
int maxv(int x,int y){ return x>y?x:y; }
int minv(int x,int y){ return x<y?x:y; }
void change(int k){
    a[k].vmax=maxv(a[a[k].lson].vmax,a[a[k].rson].vmax);
    a[k].vmin=minv(a[a[k].lson].vmin,a[a[k].rson].vmin);     
}
void init(int k,int left,int right){
    a[k].lf=left,a[k].rf=right,a[k].mid=(left+right)/2;
    if(left==right){
         a[k].vmax=a[k].vmin=data[left];
         return;                
    }     
    a[k].lson=++tag; init(tag,left,a[k].mid);
    a[k].rson=++tag; init(tag,a[k].mid+1,right);
    change(k);
}
void search(int k,int x,int y){
    if(a[k].lf==x && a[k].rf==y){
        lmin=minv(lmin,a[k].vmin);
        rmax=maxv(rmax,a[k].vmax);
        return;              
    }     
    if(y<=a[k].mid) search(a[k].lson,x,y);
    else if(x>a[k].mid) search(a[k].rson,x,y);
    else{
         search(a[k].lson,x,a[k].mid);
         search(a[k].rson,a[k].mid+1,y);     
    }
}
int main(){
    int x,y;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++) scanf("%d",&data[i]);
    init(0,1,n);
    for(int i=0;i<q;i++){
        scanf("%d%d",&x,&y);
        lmin=INT_MAX; rmax=0;
        search(0,x,y);    
        printf("%d\n",rmax-lmin);
    }
    system("pause");
    return 0;
}
