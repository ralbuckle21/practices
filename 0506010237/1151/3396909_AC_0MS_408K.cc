#include<iostream>
using namespace std;
typedef struct node{
     double sx;      
     double dx;
     double y;
     bool sign;  
}square;
square num[202];
double x[202];
int n,cs=1;
/*
void insert(int l,int r,int i,int j)
{
	if(l==r)
	{
		if(!node[i].cover)
		{
			node[i].y1=y1[j];
			node[i].y2=y2[j];
			node[i].cover=true;
			return;
		}
		else
		{
			if(y2[j]<=node[i].y1)
			{
				if(y1[j]>node[i].y1)
                    node[i].y1=y1[j];
			}
			else
			{
				node[i].area+=(x2[l]-x1[l])*(node[i].y2-node[i].y1);
				node[i].y1=y1[j];
				node[i].y2=y2[j];
			}
			node[i].cover=true;
			return;
		}
	}
	int m=(l+r)/2;
	if(y1[j]<=m) insert(l,m,i*2,t);
	if(y2[j]>m) insert(m+1,r,i*2+1,t);
}*/
int cmp1(const void *a,const void *b){
    if(*(double *)a-*(double *)b<0) return -1;
    else return 1;    
}
int cmp2(const void *a,const void *b){
    square *c=(square *)a,*d=(square *)b;
    if(c->y<d->y) return -1;
    else return 1;   
}
int main()
{
    double x1,x2,y1,y2;
    while(true){
        int xn=0,seg=0;
        scanf("%d",&n);
        if(n==0) break;
        for(int i=0;i<n;i++){
            scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2);
            x[xn++]=x1;x[xn++]=x2;
            num[seg].sx=x1;
            num[seg].dx=x2;
            num[seg].y=y1;
            num[seg++].sign=0;
            num[seg].sx=x1;
            num[seg].dx=x2;
            num[seg].y=y2;
            num[seg++].sign=1;       
        }
        qsort(x,xn,sizeof(x[0]),cmp1);
        int k=0;
        for(int i=1;i<xn;i++)
             if(x[i]!=x[k]) x[++k]=x[i];
        qsort(num,seg,sizeof(num[0]),cmp2);
        double area=0,ys;
        for(int i=0;i<k;i++){
            int cn=0;
            for(int j=0;j<seg;j++){
                  if(num[j].sx<=x[i] && num[j].dx>=x[i+1]){
                        if(cn==0) ys=num[j].y;
                        if(!num[j].sign) cn--;
                        else cn++;
                        if(cn==0) area+=(x[i+1]-x[i])*(num[j].y-ys);
                  }                               
            }        
        }
        printf("Test case #%d\n",cs++);
        printf("Total explored area: %.2lf\n\n",area); 
    }
    system("pause");
    return 0;
}
