#include<iostream>
#include<math.h>
#define maxs 4000000000
using namespace std;
int n,m;
struct{
    int x,y;  
}mg[1000];
double cost[1000][1000];
double sum=0;
double sqr(int a){
    return double(a*a);   
}
void prim(){
    double lowcost[1000],min;
    int close[1000],i,j,k;
    for(i=0;i<n;i++){
        lowcost[i]=cost[0][i];
        close[i]=0;                
    }    
    for(i=1;i<n;i++){
        min=maxs;
        for(j=0;j<n;j++){
           if(lowcost[j]!=-1 && lowcost[j]<min){
              min=lowcost[j];
              k=j;                 
            } 
        }
        sum+=min;
        lowcost[k]=-1;
        for(j=0;j<n;j++)
            if(cost[k][j]<lowcost[j]){
               lowcost[j]=cost[k][j];
               close[j]=k;                 
            }               
    }
}
int main()
{
    int s,d;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
         scanf("%d %d",&mg[i].x,&mg[i].y);
    for(int i=0;i<n;i++)
       for(int j=i;j<n;j++)
            cost[j][i]=cost[i][j]=sqrt(sqr(mg[i].x-mg[j].x)+sqr(mg[i].y-mg[j].y));
    for(int i=0;i<m;i++){
        scanf("%d %d",&s,&d);
        cost[s-1][d-1]=0;
        cost[d-1][s-1]=0;
    }
    for(int i=0;i<n;i++) cost[i][i]=-1;
    prim();
    printf("%.2f\n",sum);
    system("pause");
    return 0;
}
