#include<iostream>
using namespace std;
int n,s;
int h[20000];
int cmp(const void *a,const void *b){
     return *(int *)a-*(int *)b;   
}
int sum=0;
int main()
{
     scanf("%d %d",&n,&s);
     for(int i=0;i<n;i++) scanf("%d",&h[i]);
     qsort(h,n,sizeof(h[0]),cmp);
     for(int i=0;i<n;i++){
         if(h[i]>=s) break;
         for(int j=i+1;j<n;j++){
               if(h[i]+h[j]>s) break;
               sum++;   
         }        
     }
     printf("%d\n",sum);
     system("pause");
     return 0;
}
