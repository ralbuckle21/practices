#include<iostream>
using namespace std;
int n,num[101];
bool visit[101]={0};
int sum=0;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&num[i]);
    for(int i=3;i<=n;i++){
          int mins=0,u,smin=1000000;
          for(int j=2;j<n;j++){
                 if(!visit[j] && num[j]>mins){
                      int s=j-1,e=j+1;          
                       while(visit[s]) s--;
                       while(visit[e]) e++;
                       if(num[s]*num[e]<smin){
                           u=j;
                           mins=num[j];
                           smin=num[s]*num[e];             
                       }        
                 } 
          }
          sum=sum+smin*mins;
          visit[u]=1;             
    }
    printf("%d\n",sum);
    system("pause");
    return 0;
}
