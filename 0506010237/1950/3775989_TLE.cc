#include<iostream>
using namespace std;
char c[16];
int n,sum=0;
void find(int k){
     if(k==n){
         int v[16]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
         for(int i=1;i<k;i++)
             if(c[i]=='.'){
                 if(v[i+1]<10) v[i+1]+=v[i]*10;
                 else v[i+1]+=v[i]*100;
             }
         int s=0; char p='+'; c[k]='+';
         for(int i=1;i<=k;i++)
             if(c[i]=='+'){
                 if(p=='+') s+=v[i]; 
                 else if(p=='-'){ s-=v[i]; p='+'; }
             }             
             else if(c[i]=='-'){
                 if(p=='+'){ s+=v[i]; p='-';}
                 else if(p=='-') s-=v[i];
             } 
        if(s==0){
             if(sum<20){
                 for(int i=1;i<k;i++) printf("%d %c ",i,c[i]);
                 printf("%d\n",k);       
             } 
             sum++;
        }
        return;
     }
     c[k]='+';find(k+1);
     c[k]='-';find(k+1);
     c[k]='.';find(k+1);
}
int main()
{
     scanf("%d",&n);
     find(1);
     printf("%d\n",sum);
     system("pause");
     return 0;
}
