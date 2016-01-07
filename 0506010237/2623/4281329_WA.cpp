#include<stdio.h>
#include<stdlib.h>
int a[250000];
int n;
int cmp(const void *a,const void *b){
    return *(int *)a-*(int *)b;   
}
int main(){
    int i,sum;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&a[i]);
    qsort(a,n,sizeof(a[0]),cmp);
    sum=a[(n-1)/2]+a[n/2];
    printf("%.1lf\n",double(sum)/2);
    system("pause");
    return 0;
}
