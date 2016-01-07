#include<iostream>
using namespace std;
typedef struct
{
      int len;
      int mg[101][2];    
}node;
int mins(int a,int b)
{
    return a<=b?a:b;   
}
int main()
{
    int t,n,m,j,k;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        cin>>n;
        node list[n];
        for(j=0;j<n;j++)
        {
           scanf("%d",&list[j].len);
           for(m=0;m<list[j].len;m++)
             scanf("%d %d",&list[j].mg[m][0],&list[j].mg[m][1]);                  
        }
        for(j=1;j<n;j++)
        {
            for(m=0;m<list[j].len;m++)
            {
               double x,y;
               x=mins(list[j].mg[m][0],list[j-1].mg[0][0]);   
               y=list[j].mg[m][1]+list[j-1].mg[0][1];                    
               for(k=1;k<list[j-1].len;k++)
               {
                   double x1,y1;
                   x1=mins(list[j].mg[m][0],list[j-1].mg[k][0]);
                   y1=list[j].mg[m][1]+list[j-1].mg[k][1];
                   if((x/y)<(x1/y1))
                   {
                      x=x1;
                      y=y1;                 
                   }                            
               }
               list[j].mg[m][0]=int(x);
               list[j].mg[m][1]=int(y);
            }                
        }
        double max=0.000,z=0.000;
        for(k=0;k<list[n-1].len;k++)
        {
           z=double(list[n-1].mg[k][0])/double(list[n-1].mg[k][1]);
           if(max<z)
             max=z;
        }      
       printf("%.3lf\n",max);
    }
    system("pause");
    return 0;
}
