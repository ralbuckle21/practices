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
int s(pointt p[1000],int len)
{
     int k=0;
     for(int i=1;i<len;i++)
       k=k+sqrt(int((p[i].x-p[i-1].x)*(p[i].x-p[i-1].x))+int((p[i].y-p[i-1].y)*(p[i].y-p[i-1].y)));
     k=k+sqrt(int((p[len-1].x-p[0].x)*(p[len-1].x-p[0].x))+int((p[0].y-p[len-1].y)*(p[0].y-p[len-1].y)));
     return k;  
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
    int len=top+1,c;
    float sum=0;
    sum=2*3.14159265*l+s(ch,len);
    c=int(sum);
    if(sum-c>=0.5)
       printf("%d\n",int(sum)+1);
    else
       printf("%d\n",int(sum));
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

