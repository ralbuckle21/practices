#include<iostream>
using namespace std;
int t,n;
typedef struct{
    int v;
    bool sign;    
}node;
node num[5001];
int cmp(const void *a,const void *b){
    return (*(node *)a).v-(*(node *)b).v;   
}
int main()
{
    scanf("%d %d",&t,&n);
    for(int i=0;i<n;i++){
        scanf("%d",&num[i].v);
        if(num[i].v>=0) num[i].sign=true;
        else{
            num[i].v=-num[i].v; 
            num[i].sign=false;
        }
    }
    qsort(num,n,sizeof(num[0]),cmp);
    int x=num[0].v,i=0;
    while(i<n && t>=x){
         t-=x;
         i++;
         if(num[i].sign==num[i-1].sign) x=num[i].v-num[i-1].v;
         else x=num[i].v+num[i-1].v;   
    }
    printf("%d\n",i);
    system("pause");
    return 0;
}
