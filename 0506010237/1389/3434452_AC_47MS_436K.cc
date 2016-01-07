#include<iostream>
using namespace std;
typedef struct node{
     int sx;      
     int dx;
     int y;
     bool sign;  
}square;
square num[2002];
int x[2002];
int cmp1(const void *a,const void *b){
    if(*(int *)a-*(int *)b<0) return -1;
    else return 1;    
}
int cmp2(const void *a,const void *b){
    square *c=(square *)a,*d=(square *)b;
    if(c->y<d->y) return -1;
    else return 1;   
}
int main()
{
    int x1,x2,y1,y2;
    while(true){
        int xn=0,seg=0;
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        if(x1==-1 && y1==-1 && x2==-1 && y2==-1)break;
        x[xn++]=x1;x[xn++]=x2;
        num[seg].sx=x1;
        num[seg].dx=x2;
        num[seg].y=y1;
        num[seg++].sign=0;
        num[seg].sx=x1;
        num[seg].dx=x2;
        num[seg].y=y2;
        num[seg++].sign=1; 
        while(true){
            scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
            if(x1==-1 && y1==-1 && x2==-1 && y2==-1)break;
            x[xn++]=x1;x[xn++]=x2;
            num[seg].sx=x1;
            num[seg].dx=x2;
            num[seg].y=y1;
            num[seg++].sign=0;
            num[seg].sx=x1;
            num[seg].dx=x2;
            num[seg].y=y2;
            num[seg++].sign=1;       
        }
        qsort(x,xn,sizeof(x[0]),cmp1);
        int k=0;
        for(int i=1;i<xn;i++)
             if(x[i]!=x[k]) x[++k]=x[i];
        qsort(num,seg,sizeof(num[0]),cmp2);
        int area=0,ys;
        for(int i=0;i<k;i++){
            int cn=0;
            for(int j=0;j<seg;j++){
                  if(num[j].sx<=x[i] && num[j].dx>=x[i+1]){
                        if(cn==0) ys=num[j].y;
                        if(!num[j].sign) cn--;
                        else cn++;
                        if(cn==0) area+=(x[i+1]-x[i])*(num[j].y-ys);
                  }                               
            }        
        }
        printf("%d\n",area); 
    }
    system("pause");
    return 0;
}
