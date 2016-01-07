#include<iostream>
using namespace std;
bool flag[1010];
char c[1010][22];
int len[1010];
int s[127];
int f[127];
int n,t;
void init(){
    memset(flag,0,sizeof(flag));
    memset(s,0,sizeof(s));  
    for(int i='a';i<='z';i++) f[i]=i;   
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
void print(int k){
    int sslen=n-1,start=0; char mg;
    int i;
    qsort(c,n,sizeof(c[0]),cmp);
    if(k==2){
         for(i=0;i<n;i++){
            if(s[c[i][0]]%2==1){ start=i; break; }
         }    
    } 
    cout<<c[start]; flag[start]=true; mg=c[start][len[start]-1]; 
    while(sslen--){
          for(i=0;i<n;i++) 
             if(!flag[i] && c[i][0]==mg){
                   cout<<"."<<c[i];
                   flag[i]=true;
                   mg=c[i][len[i]-1];            
             }        
    }
    cout<<endl;
}
int main(){
    scanf("%d",&t);
    while(t--){
         init();
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
         else cout<<"***"<<endl;        
    }
    system("pause");
    return 0;
}
