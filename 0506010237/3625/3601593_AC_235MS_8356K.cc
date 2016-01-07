#include<iostream>
#include<math.h>
using namespace std;
const double maxs=10000000.0 * 1000000.0;
int n,m;
struct{
    long long x,y;  
}mg[1010];
double cost[1010][1010];
double sum=0;
void prim(){
    double lowcost[1010],min;
    int close[1010],k;
    for(int i=0;i<n;i++){
        lowcost[i]=cost[0][i];
        close[i]=0;                
    }    
    for(int i=1;i<n;i++){
        min=maxs;
        for(int j=0;j<n;j++){
           if(lowcost[j]!=-1 && lowcost[j]<min){
              min=lowcost[j];
              k=j;                 
            } 
        }
        sum+=min;
        lowcost[k]=-1;
        for(int j=0;j<n;j++)
            if(cost[k][j]<lowcost[j]){
               lowcost[j]=cost[k][j];
               close[j]=k;                 
            }               
    }
}
int main()
{
   // freopen("roads.in","r",stdin);
    //freopen("roads2.out","w",stdout);
    int s,d;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
         scanf("%ld %ld",&mg[i].x,&mg[i].y);
    for(int i=0;i<n;i++)
       for(int j=i+1;j<n;j++){
              double x=mg[i].x-mg[j].x, y=mg[i].y-mg[j].y;
              x=x*x; y=y*y;
             double d=x+y;
            cost[j][i]=cost[i][j]=sqrt(d);
       }
    for(int i=0;i<m;i++){
        scanf("%d %d",&s,&d);
        cost[s-1][d-1]=0;
        cost[d-1][s-1]=0;
    }
    for(int i=0;i<n;i++) cost[i][i]=-1;
    prim();
    printf("%0.2lf\n",sum);
    return 0;
}
