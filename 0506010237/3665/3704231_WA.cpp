#include<iostream>
using namespace std;
int n,t,cnt=-1;
int rank[1000];
int main()
{
     scanf("%d %d",&n,&t);
     for(int i=0;i<n;i++) scanf("%d",&rank[i]);
     while(t--){
          int mins=-100000000,u=0;         
          for(int i=0;i<n;i++){
               if(rank[i]>mins){
                     mins=rank[i];
                     u=i;
               }             
          }    
          rank[u]=cnt--;;
          printf("%d\n",u+1);       
     }
     system("pause");
     return 0;
}
