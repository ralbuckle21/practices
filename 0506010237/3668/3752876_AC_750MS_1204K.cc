#include<iostream>
using namespace std;
bool sign=false; //看是否存在垂直线
int slope[40000][2];
int len=0,n; 
int point[210][2];
int sum=0;
int main()
{
     int k,x,y;
     scanf("%d",&n);
     sum=n*(n-1)/2;
     for(int i=0;i<n;i++) scanf("%d%d",&point[i][0],&point[i][1]);
     for(int i=0;i<n;i++)
         for(int j=i+1;j<n;j++){
              x=point[j][0]-point[i][0]; y=point[j][1]-point[i][1];
              for(k=0;k<len;k++){
                   if(x*slope[k][1]==y*slope[k][0]){
                         sum--;
                         break;                               
                   }                   
              }    
              if(k==len){
                   slope[len][0]=x;
                   slope[len][1]=y;
                   len++;
              }
         }
     printf("%d\n",sum);
     system("pause");
     return 0;
}
