#include<iostream>
using namespace std;
int n,k;
int s[201][810];
int f[201][810];
int num[21][2];
int cs=1;
int main()
{
     while(true){
           scanf("%d %d",&n,&k);
           if(n==0 && k==0) break;
           memset(s,-1,sizeof(s));
           for(int i=1;i<=n;i++) scanf("%d %d",&num[i][0],&num[i][1]);
           s[0][400]=0;
           for(int i=1;i<=n;i++){
               int x=k<i?k:i;
               for(int j=x;j>=1;j--)
                   for(int a=0;a<=800;a++){
                       if(s[j-1][a]>=0 && a+num[i][0]-num[i][1]>=0 && s[j][a+num[i][0]-num[i][1]]<s[j-1][a]+num[i][0]+num[i][1]){
                             s[j][a+num[i][0]-num[i][1]]= s[j-1][a]+num[i][0]+num[i][1];
                             f[j][a+num[i][0]-num[i][1]]= i;                     
                       }        
                   }     
           }          
           int mins; 
           for(int i=0;i<=400;i++){
               if(s[k][400+i]>=0){
                   mins= i;
                   if(s[k][400-i]>s[k][400+i]) mins= -i;
                   break;                   
               }         
               if(s[k][400-i]>s[k][400+i]){
                   mins= -i;
                   break;   
               }    
           }
           int sum=s[k][400+mins],dif;
           dif=mins>=0?mins:-mins;
           printf("Jury #%d\nBest jury has value %d for prosecution and value %d for defence:\n",cs++,(sum+dif)/2,(sum-dif)/2); 
           int mg[21];
           mg[k]=f[k][400+mins];
           int v=400+mins-num[mg[k]][0]+num[mg[k]][1];
           for(int i=k-1;i>0;i--){
                 mg[i]=f[i][v];
                 v -= num[mg[i]][0] + num[mg[i]][1];
           }
           for(int i=1;i<=k;i++) printf(" %d",mg[i]);
           printf("\n"); 
     }
     system("pause");
     return 0;
}
