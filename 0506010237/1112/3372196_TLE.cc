#include<iostream>
using namespace std;
int n,h;
bool num[100][100]={0};
bool ok=1;
int result[100],result1[100];
int sr=0,sl=0;
int mins=100;
bool test(int visit[100],int k,int ge){
     for(int i=1;i<=ge;i++)
          if(!num[visit[i]][k]||!num[k][visit[i]]) return 0;        
     return true;
}
void find(int visit[100],int visit1[100],int k,int yes,int no){
     int r=n-k;
     if(n+1==k){
            if(yes==0 || no==0) return;
            int x=abs(yes-no);
            if(x<mins){
                  mins=x;
                  for(int i=1;i<=yes;i++) result[i]=visit[i];
                  for(int i=1;i<=no;i++) result1[i]=visit1[i];
                  sr=yes;
                  sl=no;                          
            }    
            return;      
     }
     if(yes-no-r>=mins || no-yes-r>=mins) return; //剪枝
     if(test(visit,k,yes)){
         visit[yes+1]=k;
         find(visit,visit1,k+1,yes+1,no); 
     }
     if(test(visit1,k,no)){
         visit1[no+1]=k;
         find(visit,visit1,k+1,yes,no+1);      
     } 
}
int main()
{
     int visit[100],visit1[100];
     scanf("%d",&n);
     for(int i=1;i<=n;i++){
          while(true){
               scanf("%d",&h);
               if(h==0) break;
               num[i][h]=num[i][h]=1;
          }     
     }
     visit[1]=true;
     find(visit,visit1,2,1,0);
     if(sr==0 || sl==0) printf("No solution\n");
     else{    
          if(result[1]==1){
                printf("%d ",sr);  
                for(int i=1;i<=sr;i++) printf("%d ",result[i]);
                printf("\n");
                printf("%d ",sl);
                for(int i=1;i<=sl;i++)  printf("%d ",result1[i]);
                printf("\n"); 
          }
     }
     system("pause");
     return 0;
}
