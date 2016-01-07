#include<iostream>
using namespace std;
int n;
int dist[30][30];
int result=0;
void prim(){
     int low[30];
     for(int i=0;i<n;i++){
         low[i]=dist[0][i];
         if(low[i]==0) low[i]=INT_MAX;
     }  
     for(int i=1;i<n;i++){
         int mins=INT_MAX,u;
         for(int j=1;j<n;j++)
              if(low[j]>0 && low[j]<mins){
                    mins=low[j];
                    u=j;            
              }        
         result+=mins;
         low[u]=0;
         for(int j=1;j<n;j++)
              if(dist[u][j]!=0 && dist[u][j]<low[j])
                  low[j]=dist[u][j];                
     }
}
int main()
{
     int len,d;
     char c;
     while(true){
         scanf("%d ",&n);
         if(n==0) break;
         memset(dist,0,sizeof(dist));
         for(int i=0;i<n-1;i++){
              c=getchar(); 
              while(c==' ' || c=='\n') c=getchar();
              scanf("%d",&len);
              for(int j=0;j<len;j++){
                  c=getchar();
                  while(c==' ' || c=='\n') c=getchar();
                  scanf("%d",&d);
                  dist[i][c-'A']=d;
                  dist[c-'A'][i]=d;        
              }      
         }  
         prim();    
         cout<<result<<endl;
         result=0;      
     }
     system("pause");
     return 0;
}
