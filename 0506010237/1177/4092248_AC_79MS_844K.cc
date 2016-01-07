#include<iostream>
using namespace std;
typedef struct node{
     int sx;      
     int dx;
     int y;
     bool sign; 
}square;
square num[10000],nuy[10000];
int x[10000],y[10000];
int n;
int cmp1(const void *a,const void *b){
    return *(int *)a-*(int *)b;    
}
int cmp2(const void *a,const void *b){
    square *c=(square *)a,*d=(square *)b;
    return c->y-d->y; 
}
int main(){
    int x1,x2,y1,y2;
    int xn=0,seg=0,yn=0,sef=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
         scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
         x[xn++]=x1;     x[xn++]=x2;
         num[seg].sx=x1; num[seg].dx=x2;
         num[seg].y=y1;  num[seg++].sign=0;
         num[seg].sx=x1; num[seg].dx=x2;
         num[seg].y=y2;  num[seg++].sign=1;  
         y[yn++]=y1;     y[yn++]=y2;
         nuy[sef].sx=y1; nuy[sef].dx=y2;
         nuy[sef].y=x1;  nuy[sef++].sign=0;
         nuy[sef].sx=y1; nuy[sef].dx=y2;
         nuy[sef].y=x2;  nuy[sef++].sign=1;     
    }
    qsort(x,xn,sizeof(x[0]),cmp1);
    qsort(y,yn,sizeof(y[0]),cmp1);
    int k=0,k1=0;
    for(int i=1;i<xn;i++) if(x[i]!=x[k]) x[++k]=x[i];
    for(int i=1;i<yn;i++) if(y[i]!=y[k1]) y[++k1]=y[i];
    qsort(num,seg,sizeof(num[0]),cmp2);
    qsort(nuy,sef,sizeof(nuy[0]),cmp2);  
    int area=0,ys;
    for(int i=0;i<k;i++){
         int cn=0,ys=0;
         for(int j=0;j<seg;j++){
                if(num[j].sx<=x[i] && num[j].dx>=x[i+1]){
                     if(cn==0) ys++;
                     if(!num[j].sign) cn--;
                     else cn++;
                }
         }  
         area+=(x[i+1]-x[i])*ys;                                     
    }
    for(int i=0;i<k1;i++){
         int cn=0,ys=0;
         for(int j=0;j<sef;j++){
                if(nuy[j].sx<=y[i] && nuy[j].dx>=y[i+1]){
                     if(cn==0) ys++;
                     if(!nuy[j].sign) cn--;
                     else cn++;
                }
         }  
         area+=(y[i+1]-y[i])*ys;                                     
    }    
    cout<<2*area<<endl;
    system("pause");
    return 0;
}
