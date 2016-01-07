#include<iostream>
using namespace std;
int main()
{
    int sum,a[4],b[4],sum1=0;
    while(true)
    {
       scanf("%d %d %d %d %d",&a[0],&a[1],&a[2],&a[3],&sum);
       if(a[0]==0 && a[1]==0 && a[2]==0 &a[3]==0 && sum==0)
         break;
       for(int i=0;i<4;i++)
          b[i]=a[i];
       for(int i=0;i<=a[0] && i*25<=sum;i++)
       for(int j=0;j<=a[1] && j*10<=sum;j++)
       for(int x=0;x<=a[2] && x*5<=sum;x++)
       for(int y=0;y<=a[3] && y<=sum;y++)
         if(i*25+j*10+x*5+y==sum)
         {
              if(i+j+x+y<=b[0]+b[1]+b[2]+b[3])
              {
                 b[0]=i;
                 b[1]=j;
                 b[2]=x;
                 b[3]=y;   
                 sum1=1;                            
              }                       
         }
       if(sum1==0)
          printf("Cannot dispense the desired amount.\n");
       else
          printf("Dispense %d quarters, %d dimes, %d nickels, and %d pennies.\n",b[0],b[1],b[2],b[3]);  
       sum1=0;  
    }
    system("pause");
    return 0;
}
