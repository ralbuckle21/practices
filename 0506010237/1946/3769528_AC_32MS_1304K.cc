#include<iostream>
using namespace std;
/*   首先分析题目可知对于每一只牛要吗是降低能量继续跑，要么是出列，然而由于每一个大概搜索时间复杂度很高
     大概pow(5,20)。因此设置状态方程 f(x,k,e)其中x代表时间k代表第几头牛e代表已发完多少能量 */
int n,m,d; 
int sum=0;
int f[110][21][110];
int maxs(int a,int b){return a>b?a:b; }
void getresult(){
     for(int x=0;x<=m;x++)
         for(int k=0;k<=n;k++)
             for(int e=0;e<=m;e++)
                   f[x][k][e]=-1;       
    f[0][1][0]=0;
    for(int x=0;x<=m;x++)
         for(int k=1;k<=n;k++)
             for(int e=0;e<=m;e++)   
                 if(f[x][k][e]>=0)
                 for(int t=1;t<=10;t++){
                     if(e+t*t<=m) f[x+1][k][e+t*t]=maxs(f[x+1][k][e+t*t],f[x][k][e]+t);
                     if(f[x][k][e]+t*t<=m)  
                         f[x+1][k+1][f[x][k][e]+t*t]=maxs(f[x+1][k+1][f[x][k][e]+t*t],f[x][k][e]+t);       
                 }                  
    for(int x=0;x<=m;x++)
       for(int k=0;k<=n;k++)
           for(int e=0;e<=m;e++)
                 if(f[x][k][e]>=d){
                      sum=x;
                      return;
                 } 
                   
}
int main()
{
     scanf("%d%d%d",&n,&m,&d);
     if(m>=d) getresult();
     printf("%d\n",sum);
     system("pause");
     return 0;
}
