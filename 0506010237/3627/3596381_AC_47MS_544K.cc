#include<iostream>
using namespace std;
int h[20000];
int n,b;
int cmp(const void *a,const void *b){
    return *(int *)a-*(int *)b;    
}
int main()
{
    scanf("%d %d",&n,&b);
    for(int i=0;i<n;i++) scanf("%d",&h[i]);
    qsort(h,n,sizeof(h[0]),cmp);
    int j=n-1,sum=0;
    while(sum<b){
        sum+=h[j];
        j--;             
    }
    j=n-1-j;
    cout<<j<<endl;
    system("pause");
    return 0;
}
