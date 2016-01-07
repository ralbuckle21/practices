#include<iostream>
using namespace std;
int n,b,k;
struct{
     int dif;
     int v;  
}c[250][250];
int main()
{
     int a,b;
     scanf("%d%d%d",&n,&b,&k);
     for(int i=0;i<n;i++)
         for(int j=0;j<n;j++){
             scanf("%d",&c[i][j].v);
             c[i][j].dif=0;        
         }
     for(int i=0;i<=n-b;i++)
         for(int j=0;j<=n-b;j++){
             int mins=INT_MAX;
             int maxs=0;
             for(int x=i;x<i+b;x++)
                for(int y=j;y<j+b;y++){
                      if(c[x][y].v>maxs) maxs=c[x][y].v;
                      if(c[x][y].v<mins) mins=c[x][y].v;         
                }
             c[i][j].dif=maxs-mins;
         }
     for(int i=0;i<k;i++){
         scanf("%d %d",&a,&b);
         printf("%d\n",c[a-1][b-1].dif);    
     }
     system("pause");
     return 0;
}
