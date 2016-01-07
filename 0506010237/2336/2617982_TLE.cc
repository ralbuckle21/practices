#include<iostream>
using namespace std;
int a[1440],w;
int f(int k,int n,int t)
{
    if(k==1) 
       return a[w]+t;
    else
    {
       int max=(f(k-1,n,t)+t)>=a[(k-1)*n+w]?(f(k-1,n,t)+t):a[(k-1)*n+w];
       return max+t;    
    }    
}
int main()
{
    int c,i,n,t,m,j,k;
    scanf("%d",&c); 
    for(i=1;i<=c;i++)
    {
        w=0;
        scanf("%d %d %d",&n,&t,&m);
        for(j=1;j<=m;j++)
          scanf("%d",&a[j]);
        w=m%n;
        k=m/n;
        if(w)
          k++;
        else
          w=n;  
        cout<<f(k,n,t)<<" "<<k<<endl;              
    }  
    system("pause");
    return 0;
}
