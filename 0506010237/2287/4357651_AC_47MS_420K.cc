#include<iostream>
using namespace std;
int n;
int a[1001],b[1001];
int cmp(const void *c,const void *d){
    return *(int *)d-*(int *)c;   
}
void dp(){
    int sx=0,sy=n-1,dx=0,dy=n-1,sum=0;
    for(;dx<n;dx++){
        if(a[sx]>b[dx]){ sx++; sum+=200;}
        else if(a[sx]<b[dx]){ sy--; sum-=200; }
        else{
             for(int j=sy,k=dy;j>=sx;j--,k--){
                 if(a[j]>b[k])  sum+=200;  
                 else{
                      if(a[j]<b[dx])sum-=200;
                      sy=--j; dy=k;
                      break;     
                 }       
             }     
        }       
        if(sx>sy) break;        
    }
    printf("%d\n",sum);
}
int main(){
    while(true){
         scanf("%d",&n);
         if(n==0) break;
         for(int i=0;i<n;i++) scanf("%d",&a[i]);
         for(int i=0;i<n;i++) scanf("%d",&b[i]);
         qsort(a,n,sizeof(a[0]),cmp);
         qsort(b,n,sizeof(b[0]),cmp);
         dp();
    }
    system("pause");
    return 0;
}
