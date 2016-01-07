/*   刚看此题其状态方程：f(k,h)=min(f[k-1][x],x<=h)+abs(h-v[k]) h属于[0,1000000000]
     k属于[1,2000] ; 时间复杂度=1000000000^2*20000 ;相当高
     由于h只有在给定高度中取得最优值因此可以优化成 n^3
     但是还是会超时,继续优化分为x<h和x=h 
     f(k,h)=min(f(k-1,h),f(k,h-1)-|h-1-v[k]|+1) + |h-v[k]|
     => f(k,h)=min(f(k-1,h)+|h-v[k]|,f(k,h-1)) 
*/ 
#include<iostream>
using namespace std;
int n;
int a[2010];
int h[2010];
int f[2][2010];
int sum=INT_MAX;
int abv(int a){ return a>0?a:-a; }
int mins(int a,int b){ return a<b?a:b; }
int cmp(const void *a,const void *b){
    return *(int *)a-*(int *)b;    
}
void getvalue(){
     qsort(h,n,sizeof(h[0]),cmp);
     int k=0,pre;
     f[k][0]=abv(a[0]-h[0]);
     for(int i=1;i<n;i++) f[k][i]=mins(abv(a[0]-h[i]),f[k][i-1]);
     for(int i=1;i<n;i++){
         pre=k; k=(k+1)%2;
         f[k][0]=f[pre][0]+abv(a[i]-h[0]);
         for(int j=1;j<n;j++)
              f[k][j]=mins(f[pre][j]+abv(a[i]-h[j]),f[k][j-1]);         
     }     
     if(f[k][n-1]<sum) sum=f[k][n-1];
}
int main()
{
     scanf("%d",&n);
     for(int i=0;i<n;i++){
          scanf("%d",&a[i]);
          h[i]=a[i];
     }    
     getvalue();
     for(int i=0;i<n;i++){//利用了对称性 
          a[i]=-a[i];
          h[i]=-h[i];        
     }
     getvalue();
     printf("%d\n",sum);
     system("pause");
     return 0;
}
