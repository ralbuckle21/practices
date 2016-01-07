#include<iostream>
using namespace std;
int n,m;
char s[200][20];
int sum=0;
bool array[200][20];
void fillarray(int a,int b,int k,int r){
     if((r+4)/5+10+k<=sum) return; 
     if(a==n){ 
             if(sum<k) sum=k;  
             return; 
     } 
     if(s[a][b]=='P')
     if(a==0 || (a==1 && !array[a-1][b]) || (a>=2 && !array[a-2][b] && !array[a-1][b]))
     if(b==0 || (b==1 && !array[a][b-1]) || (b>=2 && !array[a][b-2] && !array[a][b-1])){
             array[a][b]=true;
             if(b==m-1) fillarray(a+1,0,k+1,r-1);
             else fillarray(a,b+1,k+1,r-1);   
     }
     array[a][b]=false;
     if(b==m-1) fillarray(a+1,0,k,r-1);
     else fillarray(a,b+1,k,r-1);
}
int main()
{
     scanf("%d%d",&n,&m);
     for(int i=0;i<n;i++) scanf("%s",s[i]);
     fillarray(0,0,0,n*m);
     cout<<sum<<endl;
     system("pause");
     return 0;
}
