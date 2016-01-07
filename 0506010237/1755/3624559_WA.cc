#include<iostream>
using namespace std;
struct{
      int v,u,w; 
}mg[200];
int n;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d %d %d",&mg[i].v,&mg[i].u,&mg[i].w);
    for(int i=0;i<n;i++){
         int j=0;
         while(j<n){
             if(i==j || mg[i].v>mg[j].v || mg[i].u>mg[j].u || mg[i].w>mg[j].w) j++;
             else break;              
         }       
         if(j==n) printf("YES\n");
         else printf("No\n"); 
    }
    system("pause");
    return 0;
}
