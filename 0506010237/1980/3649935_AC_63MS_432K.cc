#include<iostream>
using namespace std;
int p,q,a,n;
int gcd(int c,int b){
    int r;
    if(c<b){
        r=c;
        c=b;
        b=r;        
    }
    while(b){
       r=c%b;
       c=b;
       b=r;      
    }
    return c;
}
int f(int x,int y,int k,int mins,int qq){
    int v=0;
    if(x<=0 || y<=0 || qq*mins>a) return 0;
    if(qq>a) return 0;
    int r=gcd(y,x); 
    x=x/r; y=y/r;
    if(x==1 && qq*y<=a && y>=mins)  v=1;
    int maxs=y*(n-k+1)/x;
    if(maxs>=a) maxs=a-1;   
    if(k==n) return v;
    int s=(y+x-1)/x;  
    if(s>mins) mins=s; 
    for(int i=mins;i<=maxs;i++) v+=f(i*x-y,i*y,k+1,i,qq*i);
    return v;             
}
int main()
{
  //  freopen("book.txt","w",stdout);
    while(true){
        scanf("%d%d%d%d",&p,&q,&a,&n);
        if(p==0 && q==0 && a==0 && n==0) break;
        int mins=(q+p-1)/p;
        if(mins<1) mins=1;
        cout<<f(p,q,1,mins,1)<<endl;            
    }
    system("pause");
    return 0;
}
