#include<iostream>
using namespace std;
int cash,n;
struct node{
     int bill;
     int v;
     int s;  
}num[20];
bool h[100010];
int cmp(const void *a,const void *b){
       return (*(node *)a).s-(*(node *)b).s;  
}
int main()
{
    while(scanf("%d%d",&cash,&n)!=EOF){
        for(int i=0;i<n;i++){
                scanf("%d %d",&num[i].bill,&num[i].v);
                num[i].s=num[i].bill*num[i].v;
        }
        qsort(num,n,sizeof(num[0]),cmp);
        memset(h,0x00,sizeof(h));  
        h[0]=true;
        int sum=0;
        for(int i=0;i<n;i++){
             for(int j=1;j<=num[i].bill;j++){
                   sum+=num[i].v;  
                   if(sum>cash) sum=cash;
                   for(int w=num[i].v*j;w<=sum;w++)
                        if(h[w-num[i].v]) 
                             h[w]=true;
             }
        }
        for(int i=cash;i>=0;i--) 
             if(h[i]){
                  printf("%d\n",i);
                  break;         
             }          
    }
    system("pause");
    return 0;
}
