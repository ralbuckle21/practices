#include<stdio.h>
#include<stdlib.h>
long a[250000];
long n;
int cmp(const void *a,const void *b){
    return *(long *)a-*(long *)b;   
}
int main(){
    long i;
    double sum;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&a[i]);
    qsort(a,n,sizeof(a[0]),cmp);
    sum=a[(n-1)/2]+a[n/2];
    printf("%.1lf\n",sum/2);
    system("pause");
    return 0;
}
