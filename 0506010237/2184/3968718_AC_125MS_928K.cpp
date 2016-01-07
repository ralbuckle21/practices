#include<iostream>
using namespace std;
const int maxs=-100001;
const int base=100000;
struct{
     int v;
     int d;
     bool flag;       
}f[2*base];
int num[100][2];
int up=base,down=base,n;
void dp(){
     for(int i=down;i<=up;i++) f[i].v=maxs;
     f[base].v=0;
     for(int i=0;i<n;i++){
          for(int j=down;j<=up;j++)
              if(f[j].v!=maxs && f[j].v+num[i][1]>f[j+num[i][0]].v){
                    f[j+num[i][0]].flag=true; 
                    f[j+num[i][0]].d=f[j].v+num[i][1];                
              }
          for(int j=down;j<=up;j++)
              if(f[j].flag){ 
                   f[j].v=f[j].d; 
                   f[j].flag=false;
              }
     }     
     int sum=base;
     for(int i=base;i<=up;i++) 
          if(f[i].v!=maxs && f[i].v>=0 && i+f[i].v>sum) 
               sum=i+f[i].v;
     cout<<sum-base<<endl;
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
         scanf("%d%d",&num[i][0],&num[i][1]);
         if(num[i][0]>0) up+=num[i][0];
         else down+=num[i][0];        
    }
    dp();
    system("pause");
    return 0;
}
