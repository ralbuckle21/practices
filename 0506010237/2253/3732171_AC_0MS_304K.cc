#include <math.h>
#include <stdio.h>
int X[201],Y[201];
double point_distance(int i,int j){
    return sqrt((X[i]-X[j])*(X[i]-X[j])+(Y[i]-Y[j])*(Y[i]-Y[j]));
}
int main()
{
    int n,i,j,vertex,count=1;
    double max_step,distance[201],min_distance;
    bool flag[201];
    while(scanf("%d",&n),n!=0)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&X[i],&Y[i]);
            flag[i]=false; 
            distance[i]=point_distance(0,i);  
        }
        flag[0]=true;
        max_step=0;
        while(true)
        {
            min_distance=1500;
            for(j=1;j<=n;j++)
            {
                if(!flag[j]&&distance[j]<min_distance)
                {
                    vertex=j;
                    min_distance=distance[j];
                }
            }
                if(max_step<min_distance)
                    max_step=min_distance;
                if(vertex==1)
                    break;
                flag[vertex]=true;
                for(i=1;i<n;i++)
                {
                    distance[i]=distance[i]<point_distance(i,vertex)?distance[i]:point_distance(i,vertex);
                    
                }
            
            
        }
        printf("Scenario #%d\nFrog Distance = %.3f\n\n",count++,max_step);

    }
    return 1;
}
