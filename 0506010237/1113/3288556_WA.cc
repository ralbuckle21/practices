#include<iostream>
#include<math.h>
using namespace std;
typedef struct 
{
	int x,y;
}pointt;
int n,l;
float mul(pointt p1,pointt p2,pointt p0)
{
   return((p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y));
}
void Graham_scan(pointt point[1000],int n)
{
    pointt ch[10000];
	int i,j,k=0,top=2;
	pointt tmp;
	for(i=1;i<n;i++)
	  if((point[i].y<point[k].y)||((point[i].y==point[k].y)&&(point[i].x<point[k].x)))
	        k=i;
	tmp=point[0];
	point[0]=point[k];
	point[k]=tmp;
	for(i=1;i<n-1;i++) 
	{	
        k=i;
	    for(j=i+1;j<n;j++)
	    {
            pointt p1,p2,p0;
            p1=point[j];
            p2=point[k];
            p0=point[0];
            if(mul(p1,p2,p0)>0)
               k=j;
            else if(mul(p1,p2,p0)>=0.0 && mul(p1,p2,p0)<=0.0)
               if(sqrt((p0.x-p1.x)*(p0.x-p1.x)+(p0.y-p1.y)*(p0.y-p1.y))<sqrt((p0.x-p2.x)*(p0.x-p2.x)+(p0.y-p2.y)*(p0.y-p2.y)))
                 k=j;
        }
	    tmp=point[i];
	    point[i]=point[k];
	    point[k]=tmp;
	}
	ch[0]=point[0];
	ch[1]=point[1];
	ch[2]=point[2];
	for (int i=3;i<n;i++)
	{
			while(mul(point[i],ch[top],ch[top-1])>=0) 
                top--;
			ch[++top]=point[i];
    }
    int len=top+1;
    float sum=0;
    k=0;
    for(i=1;i<len;i++)
       k=k+(int)sqrt(((ch[i].x-ch[i-1].x)*(ch[i].x-ch[i-1].x))+((ch[i].y-ch[i-1].y)*(ch[i].y-ch[i-1].y)));
     k=k+(int)sqrt(((ch[len-1].x-ch[0].x)*(ch[len-1].x-ch[0].x))+((ch[0].y-ch[len-1].y)*(ch[0].y-ch[len-1].y)));
     sum=2*acos(-1.0)*l+k;
     printf("%d\n",int(sum+0.5));
}
int main()
{
   pointt point[1000];
   scanf("%d %d",&n,&l);
   for(int i=0;i<n;i++)
   {
      scanf("%d",&point[i].x);
      scanf("%d",&point[i].y);     
   }
   Graham_scan(point,n);
   system("pause");
   return 0;    
}


