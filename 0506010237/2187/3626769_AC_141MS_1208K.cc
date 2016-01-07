#include<iostream>
#include<math.h>
using namespace std;
typedef struct {
	int x,y;
}pointt;
int mul(pointt p1,pointt p2,pointt p0){
   return((p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y));
}
int partition(pointt a[50000],int p,int r) { 
   int i=p,j=r+1,k; 
   int ang,dis; 
   pointt R,S; 
   k=(p+r)/2; 
   R=a[p]; a[p]=a[k]; a[k]=R;
   R=a[p]; 
   dis=(R.x-a[0].x)*(R.x-a[0].x)+(R.y-a[0].y)*(R.y-a[0].y);
   while(true){ 
      while(true){ 
         ++i; 
         if(i>r){  
              i=r; 
              break; 
         } 
         ang=mul(R,a[i],a[0]); 
         if(ang>0)   break; 
         else if(ang==0) 
              if((a[i].x-a[0].x)*(a[i].x-a[0].x)+(a[i].y-a[0].y)*(a[i].y-a[0].y)>dis)  break;  
      } 
      while(true){ 
         --j; 
         if(j<p){  
                   j=p; 
                   break; 
         } 
         ang=mul(R,a[j],a[0]); 
         if(ang<0) break; 
         else if(ang==0)  
              if((a[j].x-a[0].x)*(a[j].x-a[0].x)+(a[j].y-a[0].y)*(a[j].y-a[0].y)<dis) break; 
      } 
      if(i>=j)break; 
      S=a[i]; a[i]=a[j]; a[j]=S; 
   } 
   a[p]=a[j]; a[j]=R; 
   return j; 
} 
void anglesort(pointt a[50000],int p,int r) { 
   if(p<r) { 
      int q=partition(a,p,r); 
      anglesort(a,p,q-1); 
      anglesort(a,q+1,r); 
   } 
} 
void getvalue(pointt *ch,int len){
    int dis=0,w;
    for(int i=0;i<len;i++){
       for(int j=0;j<len;j++){
          if(i!=j){
               w=(ch[i].x-ch[j].x)*(ch[i].x-ch[j].x)+ (ch[i].y-ch[j].y)*(ch[i].y-ch[j].y);
               if(w>dis) dis=w;       
          }
       }
    }         
    cout<<dis<<endl;
}
void Graham_scan(pointt point[50000],int n){
    pointt ch[50000];
	int i,j,k=0,top=2;
	pointt tmp;
	for(i=1;i<n;i++)
	  if((point[i].y<point[k].y)||((point[i].y==point[k].y)&&(point[i].x<point[k].x)))  k=i;
	tmp=point[0]; point[0]=point[k]; point[k]=tmp;
    anglesort(point,1,n-1);
	ch[0]=point[0]; ch[1]=point[1]; ch[2]=point[2];	
	for (i=3;i<n;i++){
			while(mul(point[i],ch[top],ch[top-1])>=0) top--;
			ch[++top]=point[i];
    }
    int len=top+1;
    getvalue(ch,len);
}
int main()
{
    int n;
    pointt point[50000];
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d %d",&point[i].x,&point[i].y);
    Graham_scan(point,n);
    system("pause");
    return 0;
}

