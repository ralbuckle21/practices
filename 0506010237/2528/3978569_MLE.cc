#include<iostream>
using namespace std;
struct{
     int lson,rson;
     int s,d,mid;
     int c;  
}a[10000010];
bool flag[10010];
int n,tag,t;
int num[10010][2];
void build(int k,int left,int right){
    a[k].s=left; a[k].d=right; a[k].mid=(left+right)/2; a[k].c=0;
    if(left==right){
         a[k].lson=-1; a[k].rson=-1;           
         return;
    }
    a[k].lson=++tag; build(tag,left,a[k].mid);
    a[k].rson=++tag; build(tag,a[k].mid+1,right);     
}
void insert(int k,int left,int right,int c){
     if(a[k].c!=c){
          if(a[k].s==left && a[k].d==right) a[k].c=c;              
          else{ 
               if(a[k].c>0) a[a[k].lson].c=a[a[k].rson].c=a[k].c; 
               a[k].c=-1;
               if(right<=a[k].mid) insert(a[k].lson,left,right,c);
               else if(left>a[k].mid) insert(a[k].rson,left,right,c);
               else{
                     insert(a[k].lson,left,a[k].mid,c);
                     insert(a[k].rson,a[k].mid+1,right,c);
               }     
          }         
     }     
}
void count(int k){
     if(a[k].c>0) flag[a[k].c]=true;
     else if(a[k].c==-1){
          count(a[k].lson);
          count(a[k].rson);     
     }     
}
int main(){
    int start,end;
    scanf("%d",&t);
    while(t--){
         tag=0; start=INT_MAX; end=0; 
         memset(flag,0,sizeof(flag));
         scanf("%d",&n);
         for(int i=1;i<=n;i++){
             scanf("%d%d",&num[i][0],&num[i][1]);
             if(num[i][0]<start) start=num[i][0];
             if(num[i][1]>end) end=num[i][1];     
         }  
         build(0,start,end);    
         for(int i=1;i<=n;i++) insert(0,num[i][0],num[i][1],i);
         count(0);
         int sum=0;
         for(int i=1;i<=n;i++) if(flag[i]) sum++;   
         cout<<sum<<endl;  
    }
    system("pause");
    return 0;
}
