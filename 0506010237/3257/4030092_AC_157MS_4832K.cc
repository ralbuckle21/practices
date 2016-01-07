#include<iostream>
using namespace std;
struct node{
     int s;
     int d;
     int f;
     int c;       
}com[10000];
int f[1001][1001];
bool flag[1001][1001];
int L,n,b;
void dp(){
     flag[0][0]=true;
     for(int i=0;i<n;i++){
          for(int j=b;j>=0;j--){
               if(j<com[i].c) break;
               if(!flag[com[i].s][j-com[i].c]) continue;
               int v=f[com[i].s][j-com[i].c]+com[i].f;
               if(f[com[i].d][j]<v){
                    f[com[i].d][j]=v;
                    flag[com[i].d][j]=true;                     
               }          
          }        
     }    
     int result=0; 
     for(int i=0;i<=b;i++) if(f[L][i]>result) result=f[L][i];
     if(result==0) cout<<-1<<endl;
     else cout<<result<<endl;
}
int cmp(const void *a,const void *b){
    return (*(node *)a).s-(*(node *)b).s;    
}
int main(){
    scanf("%d%d%d",&L,&n,&b);
    for(int i=0;i<n;i++){ 
       scanf("%d%d%d%d",&com[i].s,&com[i].d,&com[i].f,&com[i].c);
       com[i].d+=com[i].s;
    }
    qsort(com,n,sizeof(com[0]),cmp);
    dp();
    system("pause");
    return 0;
}
