#include<iostream>
using namespace std;
struct{
    bool visit;
    int sign;
    int len;
}f[15005];
int w[22],sum=0;
int n,m;
int c[22];
int down,up;
int main()
{
     scanf("%d%d",&m,&n);
     for(int i=1;i<=m;i++) scanf("%d",&c[i]);
     for(int i=1;i<=n;i++){
         scanf("%d",&w[i]);
         sum+=w[i];
     }
   //  down=7500+c[1]*sum; up=7500+c[m]*sum;
     down=0; up=15000;
     f[7500].visit=true;  
     for(int i=1;i<=n;i++){
           for(int j=down;j<=up;j++)
               if(f[j].visit)
                   for(int x=1;x<=m;x++)
                       f[j+c[x]*w[i]].sign++;            
           for(int j=down;j<=up;j++)
               if(f[j].sign){
                    f[j].visit=true;
                    f[j].len += f[j].sign;
                    f[j].sign=0;            
               }        
     }
     printf("%d\n",f[7500].len);
     system("pause");
     return 0;
}
