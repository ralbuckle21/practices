#include<iostream>
using namespace std;
int n,m;
typedef struct{
    int s;
    int d;     
}cow;
cow c[2500];
typedef struct{
    int v;
    int num;       
}bottle; 
bottle bt[2500];
int cmp1(const void *a,const void *b){
    return (*(cow *)a).d-(*(cow *)b).d; 
}
int cmp2(const void *a,const void *b){
     return (*(bottle *)a).v-(*(bottle *)b).v;   
}
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)  scanf("%d %d",&c[i].s,&c[i].d);
    for(int i=0;i<m;i++)  scanf("%d %d",&bt[i].v,&bt[i].num);
    qsort(c,n,sizeof(c[0]),cmp1);
    qsort(bt,m,sizeof(bt[0]),cmp2);
    int sum=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m && c[i].d>=bt[j].v;j++){
              if(bt[j].num!=0 && c[i].s<=bt[j].v){
                  sum++;
                  bt[j].num--;
                  break;              
              }        
        } 
    }
    printf("%d\n",sum);    
    system("pause");
    return 0;
}


