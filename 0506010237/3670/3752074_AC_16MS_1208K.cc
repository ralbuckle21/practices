#include<iostream>
using namespace std;
int f[30010][3]={0};
int g[30010][3]={0};
int v[30010];
int n;
int mintwo(int a,int b){ return a<b?a:b; }
int minthird(int a,int b,int c){
    int temp=mintwo(a,b);
    return mintwo(temp,c);   
} 
int main()
{
     scanf("%d",&n);
     for(int i=1;i<=n;i++){
           scanf("%d",&v[i]);
           f[i][0]=f[i-1][0];
           if(v[i]!=1) f[i][0]++;
           f[i][1]=mintwo(f[i-1][0],f[i-1][1]);
           if(v[i]!=2) f[i][1]++;
           f[i][2]=minthird(f[i-1][0],f[i-1][1],f[i-1][2]);
           if(v[i]!=3) f[i][2]++;                 
     }
     for(int i=1;i<=n;i++){
           g[i][2]=g[i-1][2];
           if(v[i]!=3) g[i][2]++;
           g[i][1]=mintwo(g[i-1][2],g[i-1][1]);
           if(v[i]!=2) g[i][1]++;
           g[i][0]=minthird(g[i-1][2],g[i-1][1],g[i-1][0]);
           if(v[i]!=1) g[i][0]++;        
     }
     int mins=100000000;
     for(int i=0;i<3;i++){
          if(mins>f[n][i]) mins=f[n][i];
          if(mins>g[n][i]) mins=g[n][i];       
     }
     printf("%d\n",mins);
     system("pause");
     return 0;
}
