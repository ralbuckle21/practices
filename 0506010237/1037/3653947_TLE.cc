#include<iostream>
using namespace std;
int t,n,c;
int ok=false;
int sum;
void find(int num[22],bool visit[22],int len,bool sign){
    if(ok) return;
    if(len==n){
          sum++;
          if(c==sum){
              for(int i=1;i<=len;i++) cout<<num[i]<<" ";
              cout<<endl;
              ok=true;
          }
          return ;
    }
    if(!sign){
        for(int i=1;i<=n;i++){
             if(i<num[len] && !visit[i]){
                   num[len+1]=i;
                   visit[i]=true;
                   find(num,visit,len+1,1);
                   visit[i]=false;              
             }        
        }          
    }    
    else if(sign){
        for(int i=1;i<=n;i++){
             if(i>num[len] && !visit[i]){
                   num[len+1]=i;
                   visit[i]=true;
                   find(num,visit,len+1,0);   
                   visit[i]=false;           
             }        
        }          
    } 
}
int main()
{
     int num[22];
     bool visit[22];
     scanf("%d",&t);
     while(t--){
         ok=0; sum=0;
         memset(visit,0,sizeof(visit));
         scanf("%d %d",&n,&c);
         for(int i=1;i<=n;i++){
              num[1]=i; 
              visit[i]=true;
              find(num,visit,1,0); 
              find(num,visit,1,1);
              visit[i]=false;  
         }           
     }
     system("pause");
     return 0;
}
