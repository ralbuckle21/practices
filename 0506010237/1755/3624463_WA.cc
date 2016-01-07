#include<iostream>
using namespace std;
struct{
      double v,u,w; 
}mg[100];
int n;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%lf %lf %lf",&mg[i].v,&mg[i].u,&mg[i].w);
    for(int i=0;i<n;i++){
         int j=0;
         while(j<n){
             if(i!=j)
                if(mg[i].v==mg[j].v && mg[i].u==mg[j].u && mg[i].w==mg[j].w);
                else if(mg[i].v<=mg[j].v && mg[i].u<=mg[j].u && mg[i].w<=mg[j].w) break;
             j++;                   
         }       
         if(j==n) printf("YES\n");
         else printf("No\n"); 
    }
    system("pause");
    return 0;
}
