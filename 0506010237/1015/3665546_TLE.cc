#include<iostream>
using namespace std;
int n,k,m;
bool s[201][421][421];
int f[201][421][421];
int num[21][2];
int cs=1;
int main()
{
     while(true){
           scanf("%d %d",&n,&k);
           if(n==0 && k==0) break;
           memset(s,0,sizeof(s));
           m=20*k;
           s[0][0][0]=true;
           for(int i=1;i<=n;i++) scanf("%d %d",&num[i][0],&num[i][1]);  
           for(int i=1;i<=n;i++){
               int x=k<i?k:i;
               for(int j=x;j>=1;j--)
                   for(int a=0;a<m;a++)
                      for(int b=0;b<m;b++)
                          if(s[j-1][a][b] && !s[j][a+num[i][0]][b+num[i][1]]){
                              s[j][a+num[i][0]][b+num[i][1]]=true;
                              f[j][a+num[i][0]][b+num[i][1]]=i;
                          }        
           }          
           int mins=INT_MAX,ua,ub,maxs=0;
           for(int a=0;a<=m;a++)
               for(int b=0;b<=m;b++){
                   int v=abs(a-b);
                   if(s[k][a][b] && (v<mins || (v==mins && a+b>maxs))){
                         mins=v;
                         maxs=a+b;
                         ua=a;
                         ub=b;              
                   } 
               }
           printf("Jury #%d\nBest jury has value %d for prosecution and value %d for defence:\n",cs++,ua,ub); 
           int mg[21];
           mg[k]=f[k][ua][ub];
           for(int i=k-1;i>0;i--){
                  ua -= num[mg[i+1]][0];
                  ub -= num[mg[i+1]][1];
                  mg[i]= f[i][ua][ub];
           }
           for(int i=1;i<=k;i++) printf(" %d",mg[i]);
           printf("\n");
     }
     system("pause");
     return 0;
}
