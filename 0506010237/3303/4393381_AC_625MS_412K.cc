#include<iostream>
using namespace std;
struct node{
    int s,d;  
    int h[9]; 
}r[12];
int times[9];
int t,n;
bool dfs(int k){
    int temp;
    if(k==n) return true;
    for(int i=1;i<=r[k].h[0];i++){
         if(r[k].s>times[r[k].h[i]]){
               temp=times[r[k].h[i]];
               times[r[k].h[i]]=r[k].d;
               if(dfs(k+1)) return true;
               times[r[k].h[i]]=temp;                           
         }        
    }      
    return false;
}
int cmp(const void *a,const void *b){
    return (*(node *)a).s-(*(node *)b).s;   
}
int main(){
    scanf("%d",&t);
    while(t--){
         memset(r,0,sizeof(r));
         memset(times,-1,sizeof(times));
         scanf("%d",&n);
         for(int i=0;i<n;i++){
             scanf("%d%d%d",&r[i].s,&r[i].d,&r[i].h[0]);
             for(int j=1;j<=r[i].h[0];j++)  scanf("%d",&r[i].h[j]);      
         }       
         qsort(r,n,sizeof(r[0]),cmp);
         if(dfs(0)) printf("YES\n");
         else printf("NO\n");
    }
    system("pause");
    return 0;
}
