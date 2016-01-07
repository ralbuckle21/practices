#include<iostream>
using namespace std;
typedef struct node{
       int x1,y1;
       int x2,y2;
       int v;
       node *child1,*child2,*child3,*child4;
}node;
int mg[1024][1024]={0};
int mins(int a,int b){
      return a<b?a:b;    
}
int maxs(int a,int b){
     return a>b?a:b;   
}
void init(node *&tree,int a,int b,int c,int d) {
       tree=(node *)malloc(sizeof(node));
       int midx=(a+c)/2,midy=(b+d)/2;
       tree->x1=a;tree->y1=b;tree->x2=c;tree->y2=d;tree->v=0;
       tree->child1=tree->child2=tree->child3=tree->child4=NULL;
       if(c<=a+1 && d<=b+1) return;
       if(d<=b+1){
            init(tree->child1,a,b,midx,d);
            init(tree->child2,midx+1,b,c,d);
       }
      else if(c<=a+1){
            init(tree->child1,a,b,c,midy);
            init(tree->child2,a,midy+1,c,d); 
       }
       else{
            init(tree->child1,a,b,midx,midy);
            init(tree->child2,midx+1,b,c,midy);
            init(tree->child3,a,midy+1,midx,d);
            init(tree->child4,midx+1,midy+1,c,d);
       }
}
void add(node *tree,int a,int b,int value)
{
    int midx=(tree->x1+tree->x2)/2,midy=(tree->y1+tree->y2)/2;
    if(tree->x1<=a && tree->x2>=a && tree->y1<=b && tree->y2>=b){
          tree->v+=value;
          if(tree->v<0) tree->v=0;
          if(tree->child1) add(tree->child1,a,b,value);
          if(tree->child2) add(tree->child2,a,b,value);
          if(tree->child3) add(tree->child3,a,b,value);
          if(tree->child4) add(tree->child4,a,b,value);
    }    
}
int find(int a,int b,int c,int d){
    int sum=0;

}
int count(node *tree,int a,int b,int c,int d)
{
    int sum=0;
    if(tree==NULL){
      for(int i=a;i<=c;i++)
        for(int j=b;j<=d;j++) 
           sum+=mg[i][j]; 
        return sum;                        
    }
    if(tree->v==0)return 0;
    int midx=(tree->x1+tree->x2)/2,midy=(tree->y1+tree->y2)/2;
    if(tree->x1==a && tree->x2==c && tree->y1==b && tree->y2==d) return tree->v;
    if(midx>=a && midy>=b) sum+=count(tree->child1,a,b,mins(midx,c),mins(midy,d));
    if(midx+1<=c && midy>=b) sum+=count(tree->child2,maxs(midx+1,a),b,c,mins(midy,d));
    if(midx>=a && midy+1<=d) sum+=count(tree->child3,a,maxs(midx+1,b),mins(midx,c),d);
    if(midx+1<=c && midy+1<=d) sum+=count(tree->child4,maxs(a,midx+1),maxs(b,midy+1),c,d); 
    return sum;           
}
int main()
{
    int sign,a,b,c,d;
    node *tree;
    while(true){
         scanf("%d",&sign);
         if(sign==3) break;
         else if(sign==0){
              scanf("%d",&a);
              init(tree,0,0,a-1,a-1);     
         }             
         else if(sign==1){
              scanf("%d %d %d",&a,&b,&c);
              mg[a][b]+=c;
              if(mg[a][b]<0) mg[a][b]=0;
              add(tree,a,b,c);     
         }
         else{
             scanf("%d %d %d %d",&a,&b,&c,&d);
             printf("%d\n",count(tree,a,b,c,d));     
         }
    }
    system("pause");
    return 0;
}
