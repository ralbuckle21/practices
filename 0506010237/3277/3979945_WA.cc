#include<iostream>
using namespace std;
struct{
     int lson,rson;
     int s,d,mid;
     int h;  
}a[200100];
int hash[80010];
int n,tag=0,len;
int num[40010][3];
long long sum=0;
void build(int k,int left,int right){
    a[k].s=left; a[k].d=right; a[k].mid=(left+right)/2; a[k].h=0;
    if(left+1==right){
         a[k].lson=-1; a[k].rson=-1;           
         return;
    }
    a[k].lson=++tag; build(tag,left,a[k].mid);
    a[k].rson=++tag; build(tag,a[k].mid,right);     
}
void insert(int k,int left,int right,int h){
     if(a[k].h!=h){
          if(a[k].s==left && a[k].d==right){
                 if(a[k].h<h) a[k].h=h;                 
          }              
          else{ 
               if(a[k].h>0) a[a[k].lson].h=a[a[k].rson].h=a[k].h; 
               a[k].h=-1;
               if(right<=a[k].mid) insert(a[k].lson,left,right,h);
               else if(left>=a[k].mid) insert(a[k].rson,left,right,h);
               else{
                     insert(a[k].lson,left,a[k].mid,h);
                     insert(a[k].rson,a[k].mid,right,h);
               }     
          }         
     }     
}
void count(int k){
     if(a[k].h>0) sum+=(hash[a[k].d]-hash[a[k].s])*(__int64)a[k].h;
     else if(a[k].h==-1){
        count(a[k].lson);
        count(a[k].rson);
     }         
}
int cmp(const void *a,const void *b){
    return *(int *)a-*(int *)b;    
}
int find(int x){
    int left=0,right=len-1,mid;
    while(left<=right){
         mid=(left+right)/2;
         if(hash[mid]<x) left=mid+1;
         else right=mid-1;                  
    }    
    return left;
}
int main(){
    scanf("%d",&n);
    int x=0,j=1;
    hash[x++]=-1;
    for(int i=1;i<=n;i++){
          scanf("%d%d%d",&num[i][0],&num[i][1],&num[i][2]);
          hash[x]=num[i][0]; x++;
          hash[x]=num[i][1]; x++;     
    }  
    qsort(hash,x,sizeof(hash[0]),cmp);
    for(int i=1;i<x;i++) if(hash[i]!=hash[i-1]) hash[j++]=hash[i];
    len=j;
    build(0,1,len-1);  
    for(int i=1;i<=n;i++) insert(0,find(num[i][0]),find(num[i][1]),num[i][2]);
    count(0);
    cout<<sum<<endl;
    system("pause");
    return 0;
}
