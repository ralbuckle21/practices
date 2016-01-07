#include<iostream>
#include<math.h>
using namespace std;
int n,m;
typedef struct{
      int u;
      int v;
      double w;
}enode;
int len=0;
enode e[1000000];
typedef struct{
    int x,y;
    int sign;    
}node;
node mg[1000];
int k=0;
double sum=0;
int cmp(const void *a,const void *b){
    return (*(enode *)a).w>(*(enode *)b).w?1:-1;    
}
double sqr(int a){
    return double(a*a);   
}
void find(){
    if(k>=n-1) return;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
             if(mg[i].sign!=mg[j].sign){
                  e[len].u=i;
                  e[len].v=j;
                  e[len].w=sqrt(sqr(mg[i].x-mg[j].x)+sqr(mg[i].y-mg[j].y));
                  len++;
             }
        }
    }
    qsort(e,len,sizeof(e[0]),cmp);
    int m1,m2,c=0;  
    while(k<n-1){
        m1=e[c].u; m2=e[c].v; sum+=e[c].w;
        for(int j=0;j<n;j++)
           if(mg[j].sign==mg[m1].sign)
              mg[j].sign==mg[m2].sign;   
        c++;
        k++;
    }    
}
int main()
{
    int s,d;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
         scanf("%d %d",&mg[i].x,&mg[i].y);
         mg[i].sign=i;
    }
    for(int i=0;i<m;i++){
        scanf("%d %d",&s,&d);
        for(int j=0;j<n;j++)
           if(mg[j].sign==mg[s-1].sign)
              mg[j].sign=mg[d-1].sign;   
    }
    for(int i=0;i<n;i++) if(mg[i].sign!=i) k++;
    find();
    printf("%.2f\n",sum);
    system("pause");
    return 0;
}
