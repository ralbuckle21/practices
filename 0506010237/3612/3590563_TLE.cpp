#include<iostream>
#include<math.h>
using namespace std;
int high[100000];
int cost[100000][101];
int n,c;
int dif[101];
int pow2[101];
int main()
{
    int mins,maxs=0;
    scanf("%d %d",&n,&c);
    for(int i=0;i<n;i++){ 
            scanf("%d",&high[i]);
            if(high[i]>maxs) maxs=high[i];
    }
    for(int i=0;i<=100;i++) dif[i]=i*c;
    for(int i=0;i<=100;i++) pow2[i]=i*i;
    for(int h=high[0];h<=maxs;h++) cost[0][h]=pow2[abs(h-high[0])];
    for(int i=1;i<n;i++){
         for(int h=high[i];h<=maxs;h++){
              mins=2000000000;
              for(int x=high[i-1];x<=maxs;x++){
                   int temp=dif[abs(h-x)]+cost[i-1][x];
                   if(temp<mins) mins=temp;        
              }        
              cost[i][h]=pow2[abs(high[i]-h)]+mins;
         }   
    }
    mins=2000000000;
    for(int h=high[n-1];h<=maxs;h++){
         if(mins>cost[n-1][h]) mins=cost[n-1][h];       
    }
    cout<<mins<<endl;
    system("pause");
    return 0;
}

