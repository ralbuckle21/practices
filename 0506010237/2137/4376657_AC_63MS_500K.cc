#include<iostream>
#include<math.h>
using namespace std;
struct node{
    int len;
    int x[42],y[42];   
}a[110];
int len[110];
double f[110][42];
int n;
int pow2(int x){ return x*x; }
double dist(int i,int k,int j){
    return sqrt(pow2(a[i-1].x[k]-a[i].x[j])+pow2(a[i-1].y[k]-a[i].y[j]));       
}
double mins(double x,double y){
    return x<y?x:y;       
}
void dp(){
    double ans=10000000;
    for(int s=0;s<a[0].len;s++){
        for(int j=0;j<a[1].len;j++) f[1][j]=dist(1,s,j);
        for(int i=2;i<n;i++){
           for(int j=0;j<a[i].len;j++){
                f[i][j]=1000000;
                for(int k=0;k<a[i-1].len;k++)
                    f[i][j]=mins(f[i-1][k]+dist(i,k,j),f[i][j]);             
           }                  
        } 
        f[n][s]=10000000;
        for(int i=0;i<a[n-1].len;i++) f[n][s]=mins(f[n][s],f[n-1][i]+dist(n,i,s));
        if(f[n][s]<ans) ans=f[n][s];
    }   
    ans=100*ans;
    printf("%d\n",int(ans)); 
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
         scanf("%d",&a[i].len);
         for(int j=0;j<a[i].len;j++) scanf("%d%d",&a[i].x[j],&a[i].y[j]);        
    }
    a[n]=a[0];
    dp();
    system("pause");
    return 0;
}
