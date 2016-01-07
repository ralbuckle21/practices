#include<iostream>
#include<math.h>
using namespace std;
int n;
int num[41];
bool f[841][841];
double result=0;
int sum=0;
double getv(int a,int b,int c){
     double p=double(a+b+c)/2;
     double r=sqrt(p*(p-a)*(p-b)*(p-c));
     return r;
}
int main()
{
     scanf("%d",&n);
     for(int i=0;i<n;i++){
        scanf("%d",&num[i]);
        sum+=num[i];
     }
     int bin=sum/2;
     f[0][0]=true;
     for(int i=0;i<n;i++){
          for(int x=bin;x>=0;x--)
             for(int y=bin;y>=0;y--)
                if(f[x][y]){
                      f[x][y+num[i]]=true;
                      f[x+num[i]][y]=true;            
                }        
     }   
     for(int i=1;i<=bin;i++)
         for(int j=1;j<=bin;j++)
             if(f[i][j]){
                   int c=sum-i-j;
                   if(j>=i+c || i>=j+c || c>=i+j) continue;
                   double d=getv(i,j,c);
                   if(d>result) result=d;           
             }
     int r=int(result*100);
     if(r>0) cout<<r<<endl;
     else cout<<-1<<endl;
     system("pause");
     return 0;
}
