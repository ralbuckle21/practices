#include<iostream>
using namespace std;
const int maxn=100010;
struct node{
     int lson,rson,dep;
     int lf,rf,mid;  
}a[maxn*2];
int data[maxn];
int num[18][maxn]; //pow(2,18)>2*maxn
int n,q;
int tag=0;
int x,y,rank;
void init(int k,int left,int right,int dep){
    a[k].lf=left, a[k].rf=right; a[k].mid=(left+right)/2; a[k].dep=dep;
    if(left==right){
           num[dep][left]=data[left];
           return;              
    }     
    a[k].lson=++tag;  init(tag,left,a[k].mid,dep+1);
    a[k].rson=++tag;  init(tag,a[k].mid+1,right,dep+1);
    int i=left,j=a[k].mid+1,g=left;
    while(i<=a[k].mid && j<=right){
         if(num[dep+1][i]<=num[dep+1][j])  num[dep][g++]=num[dep+1][i++]; 
         else num[dep][g++]=num[dep+1][j++];                   
    } 
    while(i<=a[k].mid)  num[dep][g++]=num[dep+1][i++]; 
    while(j<=right) num[dep][g++]=num[dep+1][j++];    
}
int find(int k,int v){
    if(x<=a[k].lf && a[k].rf<=y){
         if(num[a[k].dep][a[k].lf]>=v) return 0;
         else if(num[a[k].dep][a[k].rf]<v) return a[k].rf-a[k].lf+1;
         else if(num[a[k].dep][a[k].rf]==v) return a[k].rf-a[k].lf;
         int left=a[k].lf,right=a[k].rf,mid;
         while(left<=right){
              mid=(left+right)/2;
              if(v>num[a[k].dep][mid]) left=mid+1;
              else right=mid-1;                    
         }           
         return left-a[k].lf;
    }   
    else{
        int sum=0;
        if(x<=a[k].mid) sum+=find(a[k].lson,v);
        if(y>a[k].mid)  sum+=find(a[k].rson,v);
        return sum;    
    }   
}
int main(){
    scanf("%d%d",&n,&q);
    for(int i=0;i<n;i++) scanf("%d",&data[i]);
    init(0,0,n-1,0);
    while(q--){
         scanf("%d%d%d",&x,&y,&rank);
         x-- ; y--; rank--;
         int left=0,right=n-1,mid;
         while(left<=right){
              mid=(left+right)/2;
              if(find(0,num[0][mid])<=rank) left=mid+1;
              else right=mid-1;                   
         }     
         printf("%d\n",num[0][left-1]);
    }
    system("pause");
    return 0;
}
