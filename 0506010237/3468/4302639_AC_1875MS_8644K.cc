#include<iostream>
using namespace std;
struct{
     int s,d,mid;
     long long sum,c;
     int lson,rson;     
}a[200020];
int data[100010];
long long result;
int n,q,tag=0;
void change(int k){
    a[k].sum=a[a[k].lson].sum+a[a[k].rson].sum+a[k].c*(a[k].d-a[k].s+1);     
}
void build(int left,int right,int k){
    a[k].s=left,a[k].d=right,a[k].mid=(left+right)/2;
    a[k].c=0;
    if(left==right){
        a[k].sum=a[k].c=data[left];
        a[k].lson=a[k].rson=-1;
        return;                
    }     
    tag++; a[k].lson=tag; build(left,a[k].mid,tag);
    tag++; a[k].rson=tag; build(a[k].mid+1,right,tag);
    change(k);
}
void updata(int k,int x,int y,long long z){
    if(x==a[k].s && y==a[k].d){
          a[k].c+=z; a[k].sum+=z*(y-x+1); 
          return;               
    }     
    if(y<=a[k].mid) updata(a[k].lson,x,y,z);
    else if(x>a[k].mid) updata(a[k].rson,x,y,z);
    else{   
          updata(a[k].lson,x,a[k].mid,z);
          updata(a[k].rson,a[k].mid+1,y,z);
    }
    change(k);
}
void search(int k,int x,int y,long long v){
     if(a[k].s==x && a[k].d==y){
           result+=a[k].sum+(y-x+1)*v;
           return;                
     }
     if(y<=a[k].mid) search(a[k].lson,x,y,v+a[k].c);
     else if(x>a[k].mid) search(a[k].rson,x,y,v+a[k].c);
     else{
         search(a[k].lson,x,a[k].mid,v+a[k].c); 
         search(a[k].rson,a[k].mid+1,y,v+a[k].c);    
     }     
}
int main(){
    int x,y,z;
    char s[2];
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++) scanf("%d",&data[i]);
    build(1,n,0);
    for(int i=0;i<q;i++){
         scanf("%s",s);
         if(s[0]=='Q'){
              scanf("%d%d",&x,&y);
              result=0; 
              search(0,x,y,result);
              printf("%I64d\n",result);             
         }        
         else{
              scanf("%d%d%d",&x,&y,&z);
              updata(0,x,y,z);    
         }
    }
    system("pause");
    return 0;
}
