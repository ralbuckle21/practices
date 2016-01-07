#include<iostream>
using namespace std;
typedef struct {
	float x,y;
}pointt;
typedef struct{
    float k;  
}node;
int cmp(const void * a, const void * b){
    return((*(float*)a-*(float*)b>0)?1:-1);
}
int main(){
    node num[1005*1005/2];	
    int n,total=2,c=0;
    while(scanf("%d",&n)!=EOF){
        pointt mg[n];
        for(int i=0;i<n;i++) scanf("%f %f",&mg[i].x,&mg[i].y); 
        for(int i=0;i<n;i++){
              int h=0;
           	  for(int j=i+1;j<n;j++)
                   if(mg[i].x!=mg[j].x) num[h++].k=(mg[j].y-mg[i].y)/(mg[j].x-mg[i].x);
              	   else   num[h++].k=100000;
              qsort(num,h,sizeof(num[0]),cmp);
 			  int c=2;
			  for(int j=1;j<h;j++){
				   if(num[j].k==num[j-1].k)	 c++;
				   else{
					       if(total<c) total=c;
						   c=2;
				   }
             }
			 if(total<c)  total=c;
        }
        printf("%d\n",total);   
        total=2;
    }
    system("pause");
    return 0;
}

