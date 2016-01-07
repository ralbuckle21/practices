#include<iostream>
using namespace std;
int n,num=0,k;
bool visit[32];
int f[32];
bool solve(int t){
     int i=t/20+2,j;//i层以下的走路可以到达
     while(i<=k){
         while(i<=k && !visit[i]) i++;
         if((i-1)*4+10*num>t) return false;//无法到达i层
         j=(t-10*num+20*i+4)/24; //电梯可以在j层停          
         i=(t-10*num+16*j+4)/20+1;  //第i层以下都可以到达了 
         f[num++]=j;
     } 
     return true;            
}
int main()
{
     int j,mins,maxs,mid;
     while(scanf("%d",&n),n){
          memset(visit,0,sizeof(visit));              
          for(int i=0;i<n;i++){
               scanf("%d",&j);
               visit[j]=true;        
          }                
          mins=0,maxs=(j-1)*14;
          k=j;
          while(mins<maxs-1){
               num=0;
               mid=(mins+maxs)/2;
               if(solve(mid)) maxs=mid;
               else mins=mid;                  
          }
          printf("%d\n%d",maxs,num);
          for(int i=0;i<num;i++) printf(" %d",f[i]);
          printf("\n");
     }
    system("pause");
    return 0;
}
