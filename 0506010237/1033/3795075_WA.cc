#include<iostream>
using namespace std;
int g[10010],c[10010];
int n,k;
bool sign=false;
void dfs(int x,int y){//x去y 
     if(g[y]==0){
           printf("%d %d\n",x,y);
           g[x]=0; c[y]=x;          
     }
     else{
         if(g[y]<y){ //发现y去前面 
              int i=n;
              while(g[i]!=0) i--;
              printf("%d %d\n",x,i);
              g[i]=y; c[y]=i;            
         }     
         else{ 
               dfs(y,g[y]);
               printf("%d %d\n",x,y);
               g[x]=0; c[y]=x;
         }
     }
}
int main()
{   
     int len,x,s=1;
     scanf("%d%d",&n,&k);
     for(int i=0;i<k;i++){
         scanf("%d",&len);
         for(int j=0;j<len;j++){
              scanf("%d",&x);
              g[x]=s; c[s]=x; s++;  //c指s来自哪里，g指x去哪里      
         }    
     }
     for(int i=1;i<s;i++){
         if(c[i]!=i){
               sign=true;
               dfs(c[i],i);            
         }        
     }
     system("pause");
     return 0;
}
