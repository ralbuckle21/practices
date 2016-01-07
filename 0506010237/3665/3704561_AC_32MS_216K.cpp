#include<iostream>
using namespace std;
int n,t,cnt=-1;
int rank[1000];
int main()
{
     scanf("%d %d",&n,&t);
     for(int i=0;i<n;i++) scanf("%d",&rank[i]);
     while(t--){
          int mins=0,u=0;         
          for(int i=0;i<n;i++){
               if(rank[i]>mins){
                     mins=rank[i];
                     u=i;
               }             
          }  
          int s=rank[u]%(n-1);
          int s1=rank[u]/(n-1);
          for(int i=0;i<n;i++) rank[i]+=s1; 
          rank[u]=0;
          int t1=0,t2=0;
          while(t2<s){
               if(t1!=u){
                    rank[t1]++;
                    t2++;         
               }  
               t1++;         
          }
          printf("%d\n",u+1);       
     }
     system("pause");
     return 0;
}
