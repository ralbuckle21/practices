#include<iostream>
using namespace std;
int n;
int a[1001],b[1001];
int cmp(const void *c,const void *d){
    return *(int *)c-*(int *)d;   
}
int main(){
    while(true){
         scanf("%d",&n);
         if(n==0) break;
         for(int i=0;i<n;i++) scanf("%d",&a[i]);
         for(int i=0;i<n;i++) scanf("%d",&b[i]);
         qsort(a,n,sizeof(a[0]),cmp);
         qsort(b,n,sizeof(b[0]),cmp);
         int i=0,j=0,sum=0;
         while(i<n){
              if(a[i]>b[j]){ j++; sum+=200; }
              else if(a[i]==b[j]){ j++; }
              else sum-=200;
              i++;          
         }        
         printf("%d\n",sum);    
    }
    system("pause");
    return 0;
}
