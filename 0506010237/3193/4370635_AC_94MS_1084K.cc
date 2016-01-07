#include<iostream>
using namespace std;
char c[1000][62];
char d[10000][62];
int lenc[1000];
int n,m;
void read(){
    scanf("%d%d",&n,&m); getchar();
    for(int i=0;i<n;i++) gets(c[i]);
    for(int i=0;i<m;i++) gets(d[i]);   
}
int strcmpcd(int x,int k){
    int len=strlen(d[k]);
    if(len>lenc[x]) return strcmp(c[x],d[k]);
    for(int i=0;i<len;i++){
         if(c[x][i]<d[k][i]) return -1;
         else if(c[x][i]>d[k][i]) return 1;
    }
    return 0;                 
}
bool find(int k){
    int left=0,right=n-1,mid,v;
    while(left<=right){
         mid=(left+right)/2;
         v=strcmpcd(mid,k);
         if(v==0) return true;
         if(v<0) left=mid+1;
         else right=mid-1;                   
    }     
    return false;
}
int cmp(const void *a,const void *b){
    return strcmp((char *)a,(char *)b);   
}
void solve(){
    int sum=0;
    qsort(c,n,sizeof(c[0]),cmp);
    for(int i=0;i<n;i++) lenc[i]=strlen(c[i]);
    for(int i=0;i<m;i++){
          if(find(i)) sum++;       
    } 
    printf("%d\n",sum);    
}
int main(){
    read();
    solve();
    system("pause");
    return 0;
}
