#include<iostream>
#include<math.h>
using namespace std;
int high[100000];
int cost[100000][101];
int n,c;
int main()
{
    int mins;
    scanf("%d %d",&n,&c);
    for(int i=0;i<n;i++) scanf("%d",&high[i]);
    for(int h=high[0];h<=100;h++) cost[0][h]=(h-high[0])*(h-high[0]);
    for(int i=1;i<n;i++){
         for(int h=high[i];h<=100;h++){
              mins=1000000000;
              for(int x=high[i-1];x<=100;x++){
                   int temp=abs(h-x)*c+cost[i-1][x];
                   if(temp<mins) mins=temp;        
              }        
              cost[i][h]=(h-high[i])*(h-high[i])+mins;
         }   
    }
    mins=1000000000;
    for(int h=high[n-1];h<=100;h++){
         if(mins>cost[n-1][h]) mins=cost[n-1][h];       
    }
    cout<<mins<<endl;
    system("pause");
    return 0;
}
