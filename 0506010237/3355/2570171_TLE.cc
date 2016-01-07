#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;
typedef struct 
{
	float x,y;
}pointt;
float mul(pointt p1,pointt p2,pointt p0)
{
   return((p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y));
}
void Graham_scan(pointt point[10000],int n)
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
	for (i=3;i<n;i++)
	{
			while(mul(point[i],ch[top],ch[top-1])>=0) 
                top--;
			ch[++top]=point[i];
    }
    for(i=0;i<=top;i++)
    //printf("%c%f%c%f%c ",'(',ch[i].x,',',ch[i].y,')');
    cout<<"("<<ch[i].x<<","<<ch[i].y<<") ";
    //printf("%c%f%c%f%c ",'(',ch[0].x,',',ch[0].y,')');
    cout<<"("<<ch[0].x<<","<<ch[0].y<<") ";
    cout<<endl;
}
int main()
{
   int i;
   pointt point[10000];
   char c;
   while(c=getchar()!=EOF)
   {
     i=0;
     while(c!='\n')
     {
        switch(c)
        {
           case '(': scanf("%f",&point[i].x);break;
           case ',': scanf("%f",&point[i].y);i++;break;
           default: break;        
        }
        c=getchar();              
     }
     Graham_scan(point,i);
   }
   system("pause");
   return 0;    
}
