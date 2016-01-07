#include<iostream>
using namespace std;
const int base=20000;
struct ps{
     int x,y;   
}point[1001];
int n,sum=0;
typedef struct node{
     int x,y;
     struct node *next;     
}node;
int cmp(const void *a,const void *b){
     ps *c=(ps *)a,*d=(ps *)b;
     if(c->x!=d->x) return c->x-d->x;
     return c->y-d->y;  
}
void insert(node *hash[base],int x,int y){
     int key=(x*39+y*19)%base;
     while(key<0) key+=base;
     if(!hash[key]){ 
        hash[key]=new node;
        hash[key]->x=x; hash[key]->y=y;
        hash[key]->next=NULL;
        return;
    }
    node *p=hash[key];
    while(p) p=p->next;
    p=new node; p->x=x; p->y=y;
    p->next=hash[key]; hash[key]=p;
} 
int search(node *hash[base],ps c,ps d){
    int key=(c.x*39+c.y*19)%base;
    while(key<0)key+=base;
    node *p=hash[key];
    if(p)
    while(p){
        if(p->x==c.x && p->y==c.y) break;
        p=p->next;         
    }
    if(!p) return false;
    key=(d.x*39+d.y*19)%base;
    while(key<0) key+=base;
    p=hash[key];
    while(p){
        if(p->x==d.x && p->y==d.y) return true;
        p=p->next;         
    }
    return false;
}
int abs(int a){ return a>0?a:-a; }
int main()
{
     ps c,d;
     while(true){
         scanf("%d",&n);if(n==0) break;
         node *hash[base];
         for(int i=1;i<=n;i++){
                scanf("%d%d",&point[i].x,&point[i].y);
                insert(hash,point[i].x,point[i].y);
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
                 if(search(hash,c,d)) sum++;          
         }
         cout<<sum<<endl;   
         sum=0;         
     }
     system("pause");
     return 0;
}
