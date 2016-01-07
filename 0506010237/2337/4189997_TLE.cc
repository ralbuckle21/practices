#include<iostream>
using namespace std;
bool flag[1010];
char c[1010][22];
int d[1010];
int len[1010];
int s[127];
int f[127];
int gs[127];
int gt[127];
int n,t;
bool ok;
void init(){
    memset(flag,0,sizeof(flag));
    memset(s,0,sizeof(s));  
    for(int i='a';i<='z';i++){
          f[i]=i;
          gs[i]=100000;
          gt[i]=0;
    }   
}
int find(int a){
    int root=a;
    while(root!=f[root]) root=f[root];
    while(a!=root){
         int temp=f[a];
         f[a]=root;
         a=temp;               
    }     
    return a;
}
void unions(int a,int b){
    f[find(a)]=f[find(b)];     
}
int cmp(const void *a,const void *b){
     return strcmp((char *)a,(char *)b);   
}
void dfs(int k,int sslen,char mg){
      if(ok) return;
      if(k==sslen){ 
            for(int i=0;i<k;i++) printf(".%s",c[d[i]]);
            ok=true;
      }
      for(int i=gs[mg];i<=gt[mg];i++){
           if(!flag[i] && c[i][0]==mg){
                flag[i]=true; 
                d[k]=i;
                dfs(k+1,sslen,c[i][len[i]-1]);
                flag[i]=false;             
           }        
      }    
}
void print(int k){
    int sslen=n-1,start=0; char mg;
    qsort(c,n,sizeof(c[0]),cmp); 
    if(k==2){
         for(int i=0;i<n;i++){
            if(s[c[i][0]]%2==1){ start=i; break; }
         }    
    } 
    printf("%s",c[start]); flag[start]=true; mg=c[start][len[start]-1]; 
    for(int i=0;i<n;i++){
         if(!flag[i]){
               if(gs[c[i][0]]>i) gs[c[i][0]]=i;
               if(gt[c[i][0]]<i) gt[c[i][0]]=i;            
         }        
    }
    dfs(0,sslen,mg);
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
               unions(c[i][0],c[i][len[i]-1]);      
         }
         int sign=0,ss;
         for(int i='a';i<='z';i++) if(s[i]!=0){ ss=find(i); break; }
         for(int i='a';i<='z';i++){
               if(s[i]==0) continue;
               if(s[i]%2) sign++;
               if(find(i)!=ss){
                     sign=-1;
                     break;                
               }        
         }   
         if(sign==0) print(0);
         else if(sign==2) print(2);
         else printf("***\n");        
    }
    system("pause");
    return 0;
}
