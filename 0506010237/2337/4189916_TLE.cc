#include<iostream>
using namespace std;
bool flag[1010];
char c[1010][22];
int d[1010];
int len[1010];
int s[127];
int n,t;
bool ok;
void init(){
    memset(flag,0,sizeof(flag));
    memset(s,0,sizeof(s));  
}
int cmp(const void *a,const void *b){
     return strcmp((char *)a,(char *)b);   
}
void dfs(int k,char mg){
      if(ok) return;
      if(k==n){ 
            printf("%s",c[d[0]]);
            for(int i=1;i<k;i++) printf(".%s",c[d[i]]);
            ok=true;
      }
      for(int i=0;i<n;i++){
           if(!flag[i] && c[i][0]==mg){
                flag[i]=true; 
                d[k]=i;
                dfs(k+1,c[i][len[i]-1]);
                flag[i]=false;             
           }        
      }    
}
void print(int k){
    int start=0; char mg;
    qsort(c,n,sizeof(c[0]),cmp);
    if(k==2){
         for(int i=0;i<n;i++){
            if(s[c[i][0]]%2==1){ start=i; break; }
         }    
    } 
    d[0]=start; flag[start]=true; mg=c[start][len[start]-1]; 
    dfs(1,mg);
    if(!ok) printf("***");
    printf("\n");
}
int main(){
    scanf("%d",&t);
    while(t--){
         init(); ok=false;
         scanf("%d",&n);
         for(int i=0;i<n;i++){
               scanf("%s",c[i]); 
               len[i]=strlen(c[i]);
               s[c[i][0]]++;  s[c[i][len[i]-1]]++;  
         }
         int sign=0,ss;
         for(int i='a';i<='z';i++){
               if(s[i]==0) continue;
               if(s[i]%2) sign++;       
         }   
         if(sign==0) print(0);
         else if(sign==2) print(2);
         else printf("***\n");        
    }
    system("pause");
    return 0;
}
