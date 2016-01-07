#include<iostream>
using namespace std;
char s[12][23];
int a[12][12];
bool use[12];
int t,n,cnt;
int comb(char a[],char b[]){
    int la,lb,j=0,len=0,i;
    la=strlen(a); lb=strlen(b);
    int k=la>lb?la-lb:0;
    for(i=k;i<la;){
        if(a[i]!=b[j]){len=0;j=0;k++;i=k;}
        else {i++;j++;len++;}
    }
    return lb-len;
}
void dfs(int k,int len,int pre){
    if(k==n+1){
         if(len<cnt) cnt=len;
         return;         
    }     
    for(int i=1;i<=n;i++){
         if(!use[i] && len+a[pre][i]<cnt){
               use[i]=true;
               dfs(k+1,len+a[pre][i],i);
               use[i]=false;     
         }        
    }
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%s",s[i]);
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                 a[i][j]=comb(s[i],s[j]);
                 a[j][i]=comb(s[j],s[i]);        
            }
            a[0][i]=strlen(s[i]);        
        }
        cnt=10000000;
        memset(use,0,sizeof(use));
        dfs(1,0,0);
        printf("%d\n",cnt);      
    }
    system("pause");
    return 0;
}
