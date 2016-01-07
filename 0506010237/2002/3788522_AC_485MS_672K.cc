#include<iostream>
using namespace std;
const int base=20000;
struct ps{
     int x,y;  
}point[1001];
int n,sum=0;
struct node{
     int x,y;  
     bool visit;  
}hash[base];
int cmp(const void *a,const void *b){
     ps *c=(ps *)a,*d=(ps *)b;
     if(c->x!=d->x) return c->x-d->x;
     return c->y-d->y;  
}
void insert(int x,int y){
    int i,adr=(x*1997+y*19)%base;
    while(adr<0) adr += base;
    while(hash[adr].visit) adr=(adr+1)%base;
    hash[adr].visit=true; hash[adr].x=x; hash[adr].y=y;          
} 
bool search(ps c,ps d){
    int adr=(c.x*1997+c.y*19)%base;
    while(adr<0) adr += base;
    while(hash[adr].visit){
       if(hash[adr].x==c.x && hash[adr].y==c.y) break;
       adr=(adr+1)%base;
    }
    if(!hash[adr].visit) return 0;
    adr=(d.x*1997+d.y*19)%base;
    while(adr<0) adr += base;
    while(hash[adr].visit){
       if(hash[adr].x==d.x && hash[adr].y==d.y) return true;
       adr=(adr+1)%base;
    }
    return false;   
}
int abs(int a){ return a>0?a:-a; }
int main()
{
     ps c,d;
     while(true){
         scanf("%d",&n);if(n==0) break;
         for(int i=0;i<base;i++) hash[i].visit=0;
         for(int i=1;i<=n;i++){
                scanf("%d%d",&point[i].x,&point[i].y);
                insert(point[i].x,point[i].y);
         }
         point[0].x=-10000000,point[0].y=-10000000;
         qsort(point,n+1,sizeof(point[0]),cmp);
         for(int i=1;i<=n;i++)
             for(int j=i+1;j<=n;j++){
                 int dx=point[i].x-point[j].x, dy=point[i].y-point[j].y;
                 int sign=dx*dy;
                 dx=abs(dx),dy=abs(dy);
                 if(sign<=0){//由逆时针方向ijdc旋转，而形成的全等三角形确定c,d
                       c.x=point[i].x+dy;
                       c.y=point[i].y+dx;
                       d.x=point[j].x+dy;
                       d.y=point[j].y+dx;           
                 }  
                 else c.x=point[i].x-1;
                 if(c.x<=point[i].x) continue;//sign==0顺逆都可的尴尬局面 
                 if(search(c,d)) sum++;          
         }
         cout<<sum<<endl;   
         sum=0;         
     }
     system("pause");
     return 0;
}
