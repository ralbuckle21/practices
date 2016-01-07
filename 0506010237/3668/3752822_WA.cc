#include<iostream>
using namespace std;
bool sign=false; //看是否存在垂直线
double slope[40000];
int len=0,n; 
int point[210][2];
int sum=0;
int main()
{
     int h;
     scanf("%d",&n);
     sum=n*(n-1)/2;
     for(int i=0;i<n;i++) scanf("%d%d",&point[i][0],&point[i][1]);
     for(int i=0;i<n;i++)
         for(int j=i+1;j<n;j++){
              if(point[j][0]==point[i][0]){
                   if(!sign) sign=true;
                   else sum--;                           
              } 
              else{
                  double k=double(point[j][1]-point[i][1])/double(point[j][0]-point[i][0]);
                  for(h=0;h<len;h++){
                       if(slope[h]>=k && slope[h]<=k){
                            sum--;
                            break;               
                       }        
                  }     
                  if(h==len) slope[len++]=k;
              }       
         }
     printf("%d\n",sum);
     system("pause");
     return 0;
}
