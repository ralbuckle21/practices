#include<iostream>
#include<math.h>
using namespace std;
typedef struct
{
    int lenx;
    int leny;
    int fx;
    int fy;       
}Line;
Line line[25000];
int sum=0;
int n,a,b,c,d;
bool finds(int a,int b)
{
     if(sqrt(line[a].fx-line[b].fx)<=(line[a].lenx+line[b].lenx) && sqrt(line[a].fy-line[b].fy)<=(line[a].leny+line[b].leny))
           return true;
     return false;
}
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
           if(i!=j && finds(i,j))
           {
              sum++;
              break;
           }        
      }
    printf("%d\n",sum);
    system("pause");
    return 0;
}
