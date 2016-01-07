#include<iostream>
using namespace std;
typedef struct 
{
	float x,y;
}pointt;
float areas(pointt ch[1000],int vcount)
{
  int i;
  float s;
  if(vcount<3)
    return 0;
  s=ch[0].y*(ch[vcount-1].x-ch[1].x);
  for (i=1;i<vcount;i++) 
     s+=ch[i].y*(ch[(i-1)].x-ch[(i+1)%vcount].x);
  return s/2;
}
int main()
{
    int n;
    float area;
    while(true)
    {
        scanf("%d",&n);
        if(n==0)
          break;
        area=0;
        pointt mg[n],ch[n];
        for(int i=0;i<n;i++)
         scanf("%f %f",&mg[i].x,&mg[i].y);
        scanf("%f",&area);
        int k=0;
       	for(int i=1;i<n;i++)
	    if((mg[i].y<mg[k].y)||((mg[i].y==mg[k].y)&&(mg[i].x<mg[k].x)))
	         k=i;
        for(int i=0;i<n;i++)
        {  
           ch[i]=mg[k];
           k=(k+n-1)%n;
        }
        printf("BAR LENGTH: %.2f\n",area/areas(ch,n));
    }
    system("pause");
    return 0;
}
