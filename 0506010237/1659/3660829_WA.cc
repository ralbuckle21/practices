#include<iostream>
using namespace std;
int t,n;
bool ok;
void find(int b[12][12],int num[12],int k,int x){
     if(ok) return;
     if(k==n){
          printf("YES\n");
          for(int i=0;i<n;i++){
              for(int j=0;j<n;j++)  printf("%d ",b[i][j]);
              printf("\n");
          }
          ok=true;
          return;                 
     }      
     if(num[k]==0){
         find(b,num,k+1,k+2);
         return;
     }
     for(int i=x;i<n;i++)
         if(num[i]!=0 && b[k][i]==0){
             num[k]--; num[i]--;
             b[k][i]=1; b[i][k]=1;
             find(b,num,k,i+1);
             num[k]++ ; num[i++];
             b[k][i]=0 ;b[i][k]=0;
         }
}
int main()
{
     int b[12][12];
     int num[12];
     scanf("%d",&t);
     while(t--){
         scanf("%d",&n);
         memset(b,0,sizeof(b)); 
         ok=false;
         for(int i=0;i<n;i++) scanf("%d",&num[i]);
         find(b,num,0,1);   
         if(!ok) printf("NO\n");
         if(t!=0)
         printf("\n");    
     }
     system("pause");
     return 0;
}
