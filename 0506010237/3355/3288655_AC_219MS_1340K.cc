#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;
typedef struct 
{
	float x,y;
	char out[20],out1[20];
}pointt;
float mul(pointt p1,pointt p2,pointt p0)
{
   return((p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y));
}
int partition(pointt a[10000],int p,int r) 
{ 
   int i=p,j=r+1,k; 
   double ang,dis; 
   pointt R,S; 
   k=(p+r)/2;//防止快排退化
   R=a[p]; 
   a[p]=a[k];
   a[k]=R; 
   R=a[p]; 
   dis=sqrt((R.x-a[0].x)*(R.x-a[0].x)+(R.y-a[0].y)*(R.y-a[0].y));
   while(true) 
   { 
      while(true) //找到第一个极角大于0的或极角等于0但距起点比它远的点 
      { 
         ++i; 
         if(i>r) 
         { 
                 i=r; 
                 break; 
         } 
         ang=mul(R,a[i],a[0]); 
         if(ang>0)   break; 
         else if(ang==0) 
         {
              if(sqrt((a[i].x-a[0].x)*(a[i].x-a[0].x)+(a[i].y-a[0].y)*(a[i].y-a[0].y))>dis)
              break; 
         } 
      } 
      while(true) 
      { 
         --j; 
         if(j<p)  
         {
                  j=p; 
                  break;
         } 
         ang=mul(R,a[j],a[0]); 
         if(ang<0) break; 
         else if(ang==0)
         { 
              if(sqrt((a[j].x-a[0].x)*(a[j].x-a[0].x)+(a[j].y-a[0].y)*(a[j].y-a[0].y))<dis) break; 
         } 
      } 
      if(i>=j)break; 
      S=a[i]; 
      a[i]=a[j]; 
      a[j]=S; 
   } 
   a[p]=a[j];
   a[j]=R; 
   return j; 
} 
void anglesort(pointt a[10000],int p,int r) 
{ 
   if(p<r) 
   { 
      int q=partition(a,p,r); 
      anglesort(a,p,q-1); 
      anglesort(a,q+1,r); 
   } 
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
    anglesort(point,1,n-1);
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
   printf("%c%s%c%s%c ",'(',ch[i].out,',',ch[i].out1,')');
   printf("%c%s%c%s%c \n",'(',ch[0].out,',',ch[0].out1,')');
}
int main()
{
   int i,k=0;
   pointt point[10000];
   char c;
   while((c=getchar())!=EOF)
   {
     i=0;
     while(c!='\n')
     {
           if(c=='(')
           {   
              c=getchar();
              while(c!=',')
              {
                point[i].out[k++]=c;
                c=getchar();
              }
              point[i].out[k]='\0';
              k=0;
              point[i].x=atof(point[i].out);
           }
           if(c==',')
           {
              c=getchar();
              while(c!=')')
              {
                point[i].out1[k++]=c;
                 c=getchar();             
              }
              point[i].out1[k]='\0';
              point[i].y=atof(point[i].out1);
              k=0;
              i++;
           }
           c=getchar();            
     }
     Graham_scan(point,i);
   }
   system("pause");
   return 0;    
}

