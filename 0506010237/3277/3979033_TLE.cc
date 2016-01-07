#include<iostream>
using namespace std;
struct node{
     int s;      
     int d;
     int h;
}num[40010];
int x[80010];
int n,cs=1;
int cmp1(const void *a,const void *b){
    return *(int *)a-*(int *)b;  
}
int cmp2(const void *a,const void *b){
    node *c=(node *)a,*d=(node *)b;
    return c->h-d->h;   
}
int main(){
    int x1,x2,y;
    int xn=0,seg=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
         scanf("%d%d%d",&x1,&x2,&y);
         x[xn++]=x1;x[xn++]=x2;
         num[seg].s=x1; num[seg].d=x2; num[seg].h=y; seg++;
    }
    qsort(x,xn,sizeof(x[0]),cmp1);
    int k=0;
    for(int i=1;i<xn;i++) if(x[i]!=x[k]) x[++k]=x[i];
    qsort(num,seg,sizeof(num[0]),cmp2);
    long long area=0,ys;
    for(int i=0;i<k;i++){
         ys=0;
         for(int j=0;j<seg;j++)
              if(num[j].s<=x[i] && num[j].d>=x[i+1]) ys=num[j].h;
         area+=(x[i+1]-x[i])*ys;                               
    }
    cout<<area<<endl;
    system("pause");
    return 0;
}
