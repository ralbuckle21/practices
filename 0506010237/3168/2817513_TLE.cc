#include<iostream>
#include<math.h>
using namespace std;
typedef struct
{
    float lenx;
    float leny;
    float fx;
    float fy;       
}Line;
Line line[25000];
int sum=0;
int n,a,b,c,d;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d %d %d %d",&a,&b,&c,&d);
        line[i].lenx=(c-a)/2;
        line[i].leny=(d-b)/2;
        line[i].fx=(a+c)/2;
        line[i].fy=(b+d)/2;        
    }
    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
      {
           if(i!=j && sqrt(line[i].fx-line[j].fx)<=(line[i].lenx+line[j].lenx) && sqrt(line[i].fy-line[j].fy)<=(line[i].leny+line[j].leny))
           {
              sum++;
              break;
           }        
      }
    printf("%d\n",sum);
    system("pause");
    return 0;
}


