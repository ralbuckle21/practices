#include<iostream>
using namespace std;
int n,m,r;
typedef struct{
    int s;
    int d;
    int v;   
}node;
node mg[1001];
int num[2000000]={0};
int cmp(const void *a,const void *b){
    return (*(node *)a).d-(*(node *)b).d;   
}
int main()
{
    int j;
    scanf("%d %d %d",&n,&m,&r);
    for(int i=0;i<m;i++){
         scanf("%d %d %d",&mg[i].s,&mg[i].d,&mg[i].v);
         mg[i].d+=r;        
    }
    qsort(mg,m,sizeof(mg[0]),cmp);
    for(int i=0;i<m;i++){
         if(num[mg[i].s]+mg[i].v>num[mg[i].d])
             num[mg[i].d]=num[mg[i].s]+mg[i].v;
         j=mg[i].d+1;
         if(i<m-1){
             while(j<=mg[i+1].d){
                 num[j]=num[j-1];
                 j++;
             }
         }            
    }
    printf("%d\n",num[mg[m-1].d]);
    system("pause");
    return 0;
}
