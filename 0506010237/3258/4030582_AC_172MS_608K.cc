#include<iostream>
using namespace std;
int dist[50010];
int len,n,m;
bool half(int v){
    int pre=0,total=0;
    for(int i=0;i<n;i++){
        if(dist[i]-pre<v) total++;
        else pre=dist[i];        
    } 
    if(len-pre<v) total++;
    if(total<=m) return true;
    else return false;
}
void solve(){
    int left=0,right=len;
    while(left<=right){
         int mid=(left+right)/2;
         if(half(mid)) left=mid+1;
         else right=mid-1;                    
    }     
    printf("%d\n",left-1);
}
int cmp(const void *a,const void *b){
    return *(int *)a-*(int *)b;    
}
int main(){
    scanf("%d%d%d",&len,&n,&m);
    for(int i=0;i<n;i++) scanf("%d",&dist[i]);
    qsort(dist,n,sizeof(dist[0]),cmp);
    solve();
    system("pause");
    return 0;
}
