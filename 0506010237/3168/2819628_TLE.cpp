# include <stdio.h>
# include <stdlib.h>
typedef struct
{
    int lenx;
    int leny;
    int fx;
    int fy; 
    bool visit;     
}Line;
Line line[25000];
int sum=0;
int n,a,b,c,d,i;
int main()
{
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d %d %d %d",&a,&b,&c,&d);
        line[i].lenx=(c-a);
        line[i].leny=(d-b);
        line[i].fx=(a+c);
        line[i].fy=(b+d); 
        line[i].visit=false;       
    }
    for(i=0;i<n;i++)
    {
      if(line[i].visit==false)
      {
        for(int j=0;j<n;j++)
        {
           if(i!=j && float(abs(line[i].fx-line[j].fx))/2<=float(line[i].lenx+line[j].lenx)/2 && float(abs(line[i].fy-line[j].fy))/2<=float(line[i].leny+line[j].leny)/2)
           {
              line[j].visit=true;
              sum++;
              break;
           }        
        }
      }
      else
         sum++;
    }
    printf("%d\n",n-sum);
    system("pause");
    return 0;
}
